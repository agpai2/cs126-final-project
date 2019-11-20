#include "catch.hpp"
#include "hex_cell.h"

TEST_CASE("Test HexCell constructor creates correct vertices in a hexagon") {
    vector<ofVec3f> expected_vertices = {
		{40, 20}, {30, 2.68}, {10, 2.68}, 
        {0, 20}, {10, 37.32}, {30, 37.32}
	};
    
	HexCell cell(ofVec3f(20, 20, 0));
	vector<ofVec3f> vertices = cell.GetVertices();
    REQUIRE(vertices.size() == 6);
    
	for (int i = 0; i < 6; i++) {
        REQUIRE(vertices[i].x == Approx(expected_vertices[i].x).epsilon(0.01));
		REQUIRE(vertices[i].y == Approx(expected_vertices[i].y).epsilon(0.01));
    }
}