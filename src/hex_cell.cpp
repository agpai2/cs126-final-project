#include "hex_cell.h"

HexCell::HexCell(ofVec3f center) : center_(center) {
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
    return vector<ofVec3f>({right_vertex_, upper_right_vertex_,
                            upper_left_vertex_, left_vertex_,
                            lower_left_vertex_, lower_right_vertex_});
}

ofVec3f HexCell::GetUpperRightVertex() { 
	return upper_right_vertex_; 
}

ofVec3f HexCell::GetLowerRightVertex() { 
	return lower_right_vertex_; 
}

ofVec3f HexCell::GetUpperLeftVertex() { 
	return upper_left_vertex_; 
}

ofVec3f HexCell::GetLowerLeftVertex() {
	return lower_left_vertex_; 
}

ofVec3f HexCell::GetRightVertex() { 
	return right_vertex_; 
}

ofVec3f HexCell::GetLeftVertex() { 
	return left_vertex_; 
}


void HexCell::setup() {
    set(center_.x - kHexCellRadius / 2.0, center_.y - kHexCellRadius / 2.0,
        kHexCellRadius, kHexCellRadius);
    enableMouseEvents();
}

void HexCell::exit() {}

void HexCell::update() {}

void HexCell::draw() {
    ofSetColor(255, 0, 0);
    ofPolyline hexagon_outline;
    for (ofVec3f& vertex : GetVertices()) {
        hexagon_outline.addVertex(vertex);
    }
    hexagon_outline.close();
    hexagon_outline.draw();
}

void HexCell::onPress(int x, int y, int button) {

}
