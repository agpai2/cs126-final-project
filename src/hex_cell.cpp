#include "hex_cell.h"

namespace Hexplosions {
HexCell::HexCell(ofVec3f center, GameEngine &engine)
    : center_(center), engine_(engine) {
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

vector<ofVec3f> HexCell::GetVertices() const {
    return vector<ofVec3f>({right_vertex_, upper_right_vertex_,
                            upper_left_vertex_, left_vertex_,
                            lower_left_vertex_, lower_right_vertex_});
}

ofVec3f HexCell::GetCenter() const { return center_; }

ofVec3f HexCell::GetUpperRightVertex() const { return upper_right_vertex_; }

ofVec3f HexCell::GetLowerRightVertex() const { return lower_right_vertex_; }

ofVec3f HexCell::GetUpperLeftVertex() const { return upper_left_vertex_; }

ofVec3f HexCell::GetLowerLeftVertex() const { return lower_left_vertex_; }

ofVec3f HexCell::GetRightVertex() const { return right_vertex_; }

ofVec3f HexCell::GetLeftVertex() const { return left_vertex_; }

size_t HexCell::GetAtoms() const { return atoms_; }

void HexCell::AddAtom(size_t curr_player_id) {
    if (is_occupied_ && curr_player_id != player_id_) {
        engine_.TransferCell(player_id_, curr_player_id);
    } else if (!is_occupied_) {
        engine_.MarkCellOccupied(curr_player_id);
    }

    player_id_ = curr_player_id;
    is_occupied_ = true;
    ++atoms_;

    if (atoms_ >= neighbor_cells_.size()) {
        ExplodeAtoms();
    }
}

void HexCell::ExplodeAtoms() {
    atoms_ = 0;
    is_occupied_ = false;
    engine_.MarkCellUnoccupied(player_id_);

    for (HexCell* neighbor : neighbor_cells_) {
        neighbor->AddAtom(player_id_);
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
    ofSetColor(ofColor::red);
    ofPolyline hexagon_outline;
    for (ofVec3f& vertex : GetVertices()) {
        hexagon_outline.addVertex(vertex);
    }
    hexagon_outline.close();
    hexagon_outline.draw();

    if (is_occupied_) {
        ofSetColor(GameSettings::GetPlayerColor(player_id_));
        ofDrawBitmapString(to_string(atoms_), center_);
    }
}

void HexCell::onPress(int x, int y, int button) {
    if (!is_occupied_ || engine_.GetCurrentPlayerId() == player_id_) {
        player_id_ = engine_.GetCurrentPlayerId();
        AddAtom(player_id_);
        engine_.FinishCurrentTurn();
    } else {
        // TODO: Throw exception to let player know their move is invalid
    }
}

 const vector<HexCell*>& HexCell::GetNeighbors() const { return neighbor_cells_; }

void HexCell::AddNeighbor(HexCell& neighbor) {
    neighbor_cells_.push_back(&neighbor);
}
}  // namespace Hexplosions