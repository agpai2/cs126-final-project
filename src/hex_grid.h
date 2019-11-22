#pragma once

#include "ofMain.h"
#include "hex_cell.h"

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
    void SetupCellNeighbors();
};
} // namespace Hexplosions