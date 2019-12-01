#include "catch.hpp"
#include "hex_cell.h"

using Hexplosions::HexCell;

TEST_CASE("Test HexCell constructor creates correct vertices in a hexagon") {
    vector<ofVec3f> expected_vertices = {{80, 40}, {60, 5.36},  {20, 5.36},
                                         {0, 40},  {20, 74.64}, {60, 74.64}};

    HexCell cell(ofVec3f(40, 40, 0));
    vector<ofVec3f> vertices = cell.GetVertices();
    REQUIRE(vertices.size() == 6);

    for (int i = 0; i < 6; i++) {
        REQUIRE(vertices[i].x == Approx(expected_vertices[i].x).epsilon(0.01));
        REQUIRE(vertices[i].y == Approx(expected_vertices[i].y).epsilon(0.01));
    }
}

TEST_CASE("Test HexCell's ExplodeAtoms()") {
    HexCell cell(ofVec3f(0, 0, 0));
    HexCell neighbor1(ofVec3f(20, 0, 0));
    HexCell neighbor2(ofVec3f(20, 20, 0));
    HexCell neighbor3(ofVec3f(0, 20, 0));

    const size_t kNumCells = 4;
    HexCell* cells[kNumCells] = {&cell, &neighbor1, &neighbor2, &neighbor3};

    for (int i = 0; i < kNumCells; i++) {
        for (int j = 0; j < kNumCells; j++) {
            if (j == i) {
                continue;
            }
            cells[i]->AddNeighbor(*cells[j]);
        }
    }

    SECTION("is triggered when number of atoms equals number of neighbors") {
        cell.AddAtom();
        REQUIRE(cell.GetAtoms() == 1);

        cell.AddAtom();
        REQUIRE(cell.GetAtoms() == 2);

        cell.AddAtom();
        REQUIRE(cell.GetAtoms() == 0);
    }

    SECTION("adds 1 atom to each neighbor upon exploding") {
        cell.AddAtom();
        cell.AddAtom();
        cell.AddAtom();  // triggers explosion

        REQUIRE(neighbor1.GetAtoms() == 1);
        REQUIRE(neighbor2.GetAtoms() == 1);
        REQUIRE(neighbor3.GetAtoms() == 1);
    }

    SECTION(
        "can trigger its neighbor's ExplodeAtoms function (i.e. a chain "
        "reaction") {
        cell.AddAtom();
        cell.AddAtom();
        neighbor1.AddAtom();
        neighbor1.AddAtom();
        cell.AddAtom();

        REQUIRE(neighbor1.GetAtoms() == 0);
        REQUIRE(cell.GetAtoms() == 1);
        REQUIRE(neighbor2.GetAtoms() == 2);
        REQUIRE(neighbor3.GetAtoms() == 2);
    }
}