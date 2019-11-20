#include "hex_cell.h"

HexCell::HexCell(ofVec3f center): center_(center) {
    float cumulative_angle = 0;
    vector<ofVec3f*> vertex_ptrs = {&right_vertex_,      &upper_right_vertex_,
                                   &upper_left_vertex_, &left_vertex_,
                                   &lower_left_vertex_, &lower_right_vertex_};

	for (auto& vertex_ptr : vertex_ptrs) {
        float x = center_.x + kHexCellRadius * cos(cumulative_angle);
        float y = center_.y + kHexCellRadius * sin(cumulative_angle);
        *vertex_ptr = ofVec3f(x, y, 0);

		cumulative_angle += kHexCellAngleRad;
	}
}

vector<ofVec3f> HexCell::GetVertices() { 
	return vector<ofVec3f>({
        right_vertex_,
        upper_right_vertex_,
        upper_left_vertex_,
        left_vertex_,
        lower_left_vertex_,
        lower_right_vertex_
	}); 
}
