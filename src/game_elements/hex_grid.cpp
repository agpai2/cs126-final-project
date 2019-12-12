#include "hex_grid.h"

namespace Hexplosions {
HexGrid::HexGrid(ofVec3f center, GameEngine &engine) : 
    center_(center), engine_(engine) {}

const vector<HexCell>& HexGrid::GetCells() const { 
    return cells_; 
}

void HexGrid::setup() {
    grid_size_ = engine_.GetGridSize();
    vector<HexCell> middle_column = CreateGridMiddleColumn();
    deque<vector<HexCell>> left_half = CreateGridLeftHalf(middle_column);
    deque<vector<HexCell>> right_half = CreateGridRightHalf(middle_column);
    
    left_half.pop_back();  // Prevent duplicate of middle column
    for (vector<HexCell>& column : left_half) {
        std::move(column.begin(), column.end(), std::back_inserter(cells_));
    }
    for (vector<HexCell>& column : right_half) {
        std::move(column.begin(), column.end(), std::back_inserter(cells_));
    }

    for (HexCell& cell : cells_) {
        cell.setup();
    }
    SetupCellNeighbors();
}

void HexGrid::update() {}

void HexGrid::draw() {
    for (HexCell& cell : cells_) {
        cell.draw();
    }
}

void HexGrid::exit() {}

vector<HexCell> HexGrid::CreateGridMiddleColumn() const {
    const float kHexCellHalfHeight = kHexCellRadius * sin(kHexCellAngleRad);
    const float kHexCellHeight = kHexCellHalfHeight * 2;

    float top_cell_center_y = center_.y - (grid_size_ - 1) * kHexCellHalfHeight;
    vector<HexCell> middle_column;
    for (int i = 0; i < grid_size_; i++) {
        ofVec3f cell_center(center_.x, top_cell_center_y + kHexCellHeight * i);
        middle_column.emplace_back(HexCell(cell_center, engine_));
    }
    return middle_column;
}

deque<vector<HexCell>> HexGrid::CreateGridLeftHalf(
    vector<HexCell>& middle_column) const {
    deque<vector<HexCell>> left_half = {middle_column};
    for (int i = 1; i < grid_size_; i++) {
        vector<HexCell> new_column;

        for (HexCell& prev_col_cell : left_half.front()) {
            ofVec3f cell_center = prev_col_cell.GetLowerLeftVertex();
            cell_center.x -= kHexCellRadius;
            new_column.emplace_back(HexCell(cell_center, engine_));
        }

        // Each column has one fewer cell than the previous column
        new_column.pop_back();
        left_half.push_front(new_column);
    }

    return left_half;
}

deque<vector<HexCell>> HexGrid::CreateGridRightHalf(
    vector<HexCell>& middle_column) const {
    deque<vector<HexCell>> right_half = {middle_column};
    for (int i = 1; i < grid_size_; i++) {
        vector<HexCell> new_column;

        for (HexCell& prev_col_cell : right_half.back()) {
            ofVec3f cell_center = prev_col_cell.GetLowerRightVertex();
            cell_center.x += kHexCellRadius;
            new_column.emplace_back(HexCell(cell_center, engine_));
        }

        // Each column has one fewer cell than the previous column
        new_column.pop_back();
        right_half.push_back(new_column);
    }

    return right_half;
}

void HexGrid::SetupCellNeighbors() {
    // Not an efficient way to add neighbors, but this function is only run once
    for (HexCell& cell : cells_) {
        ofVec3f cell_center = cell.GetCenter();
        for (HexCell& other_cell : cells_) {
            ofVec3f other_cell_center = other_cell.GetCenter();
            if (cell_center == other_cell_center) continue;

            if (cell_center.distance(other_cell_center) < kHexCellDiameter) {
                cell.AddNeighbor(other_cell);
            }
        }
    }
}
}  // namespace Hexplosions