#include "hex_grid.h"

namespace Hexplosions {
HexGrid::HexGrid() : HexGrid(ofVec3f(0, 0)) {}

HexGrid::HexGrid(ofVec3f center) : center_(center) {}

vector<HexCell> HexGrid::GetCells() { return cells_; }

void HexGrid::setup() {
    const float kHexCellHalfHeight = kHexCellRadius * sin(kHexCellAngleRad);
    const float kHexCellHeight = kHexCellHalfHeight * 2;

    // Generate middle column of cells
    float top_cell_center_y = center_.y - (kGridSize - 1) * kHexCellHalfHeight;
    vector<HexCell> middle_column;
    for (int i = 0; i < kGridSize; i++) {
        ofVec3f cell_center(center_.x, top_cell_center_y + kHexCellHeight * i);
        middle_column.emplace_back(HexCell(cell_center));
    }

    // Generate left half of grid
    vector<vector<HexCell>> left_half = {middle_column};
    for (int i = 1; i < kGridSize; i++) {
        left_half.push_back(vector<HexCell>());

        for (HexCell& prev_col_cell : left_half[i - 1]) {
            ofVec3f cell_center = prev_col_cell.GetLowerLeftVertex();
            cell_center.x -= kHexCellRadius;
            left_half[i].emplace_back(HexCell(cell_center));
        }

        // Each column has one fewer cell than the previous column
        left_half[i].pop_back();
        cells_.insert(cells_.end(), left_half[i].begin(), left_half[i].end());
    }

    reverse(cells_.begin(), cells_.end());
    cells_.insert(cells_.end(), middle_column.begin(), middle_column.end());

    // Generate right half of grid
    vector<vector<HexCell>> right_half = {middle_column};
    for (int i = 1; i < kGridSize; i++) {
        right_half.push_back(vector<HexCell>());

        for (HexCell& prev_col_cell : right_half[i - 1]) {
            ofVec3f cell_center = prev_col_cell.GetLowerRightVertex();
            cell_center.x += kHexCellRadius;
            right_half[i].emplace_back(HexCell(cell_center));
        }

        // Each column has one fewer cell than the previous column
        right_half[i].pop_back();
        cells_.insert(cells_.end(), right_half[i].begin(), right_half[i].end());
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
} // namespace Hexplosions