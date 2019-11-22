#include "catch.hpp"
#include "hex_cell.h"

using Hexplosions::HexCell;

TEST_CASE("Test HexCell constructor creates correct vertices in a hexagon") {
    vector<ofVec3f> expected_vertices = {
		{80, 40}, {60, 5.36}, {20, 5.36}, 
        {0, 40}, {20, 74.64}, {60, 74.64}
	};
    
	HexCell cell(ofVec3f(40, 40, 0));
	vector<ofVec3f> vertices = cell.GetVertices();
    REQUIRE(vertices.size() == 6);
    
	for (int i = 0; i < 6; i++) {
        REQUIRE(vertices[i].x == Approx(expected_vertices[i].x).epsilon(0.01));
		REQUIRE(vertices[i].y == Approx(expected_vertices[i].y).epsilon(0.01));
    }
}