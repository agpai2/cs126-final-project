#include "hex_cell.h"

namespace Hexplosions {
HexCell::HexCell(ofVec3f center) : center_(center) {
    float cumulative_angle = 0;
    vector<ofVec3f*> vertex_ptrs = {&right_vertex_,      &upper_right_vertex_,
                                    &upper_left_vertex_, &left_vertex_,
                                    &lower_left_vertex_, &lower_right_vertex_};

    for (auto& vertex_ptr : vertex_ptrs) {
        float x = center_.x + kHexCellRadius * cos(cumulative_angle);
        float y = center_.y + kHexCellRadius * sin(cumulative_angle);
        *vertex_ptr = ofVec3f(x, y, 0);

        cumulative_angle -= kHexCellAngleRad;
    }

    set(center_.x - kHexCellRadius / 2, center_.y - kHexCellRadius / 2,
        kHexCellRadius, kHexCellRadius);
}

vector<ofVec3f> HexCell::GetVertices() {
    return vector<ofVec3f>({right_vertex_, upper_right_vertex_,
                            upper_left_vertex_, left_vertex_,
                            lower_left_vertex_, lower_right_vertex_});
}

ofVec3f HexCell::GetCenter() { 
    return center_; 
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

size_t HexCell::GetAtoms() { 
    return atoms_;
}

void HexCell::AddAtom() { 
    ++atoms_;
    if (atoms_ >= neighbor_cells_.size()) {
        atoms_ = 0;
        ExplodeAtoms();
    }
}

void HexCell::ExplodeAtoms() { 
    for (HexCell* neighbor : neighbor_cells_) {
        neighbor->AddAtom();
    }
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

    ofDrawBitmapString(to_string(atoms_), center_);
}

void HexCell::onPress(int x, int y, int button) { 
    AddAtom(); 
}

vector<HexCell*>& HexCell::GetNeighbors() { 
	return neighbor_cells_; 
}

void HexCell::AddNeighbor(HexCell &neighbor) { 
	neighbor_cells_.push_back(&neighbor);
}
} // namespace Hexplosions