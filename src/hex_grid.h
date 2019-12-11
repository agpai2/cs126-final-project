#pragma once

#include "ofMain.h"
#include "hex_cell.h"
#include "game_settings.h"

namespace Hexplosions {
/**
 * @class   HexGrid
 *
 * @brief   A container for multiple cells (HexCell) which form a grid.
 * @details This class sets up individual cells by calculating the location of each cell.
 *          This class also populates the neighbors of each cell.
 *          This class does not have any graphical or interactive functionality.
 *          
 * @see     HexCell
 *
 * @author  Estelle Lee
 * @date    1/12/2019
 */
class HexGrid {
  public:
    HexGrid();
    HexGrid(ofVec3f center, GameEngine &engine);
    const vector<HexCell>& GetCells() const;

    void setup();
    void update();
    void draw();
    void exit();

  private:
    ofVec3f center_;
    vector<HexCell> cells_;
    size_t grid_size_;
    GameEngine& engine_;

    vector<HexCell> CreateGridMiddleColumn() const;
    deque<vector<HexCell>> CreateGridLeftHalf(vector<HexCell>& middle_column) const;
    deque<vector<HexCell>> CreateGridRightHalf(vector<HexCell>& middle_column) const;
    void SetupCellNeighbors();
};
}  // namespace Hexplosions