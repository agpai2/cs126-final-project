#pragma once

#include "hex_cell.h"
#include "ofMain.h"

namespace Hexplosions {
const size_t kGridSize = 5;

class HexGrid {
   public:
    HexGrid();
    HexGrid(ofVec3f center);
    vector<HexCell> GetCells();

    void setup();
    void update();
    void draw();
    void exit();

   private:
    ofVec3f center_;
    vector<HexCell> cells_;

    vector<HexCell> CreateGridMiddleColumn() const;
    deque<vector<HexCell>> CreateGridLeftHalf(vector<HexCell>& middle_column) const;
    deque<vector<HexCell>> CreateGridRightHalf(vector<HexCell>& middle_column) const;
    void SetupCellNeighbors();
};
}  // namespace Hexplosions