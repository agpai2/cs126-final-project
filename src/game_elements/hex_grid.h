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
    HexGrid(ofVec3f center, GameEngine &engine);
    const vector<HexCell>& GetCells() const;

    // These methods follow OpenFrameworks convention
    void setup();
    void update();
    void draw();
    void exit();

  private:
    ofVec3f center_;
    vector<HexCell> cells_;
    size_t grid_size_;
    GameEngine& engine_;

    /**
     * @fn  vector<HexCell> HexGrid::CreateGridMiddleColumn() const;
     *
     * @brief   Creates the middle column of grid based on grid size
     *
     * @returns Cells in the middle column 
     */
    vector<HexCell> CreateGridMiddleColumn() const;

    /**
     * @fn  deque<vector<HexCell>> HexGrid::CreateGridLeftHalf(vector<HexCell>& middle_column) const;
     *
     * @brief   Creates left half of the grid based on grid size
     *
     * @param [in,out]  middle_column   The middle column.
     *
     * @returns Cells in the left half of the grid, inclusive of the middle column
     */
    deque<vector<HexCell>> CreateGridLeftHalf(vector<HexCell>& middle_column) const;

    /**
     * @fn  deque<vector<HexCell>> HexGrid::CreateGridRightHalf(vector<HexCell>& middle_column) const;
     *
     * @brief   Creates right half of the grid based on grid size
     *
     * @param [in,out]  middle_column   The middle column.
     *
     * @returns Cells in the  right half of the grid, inclusive of the middle column
     */
    deque<vector<HexCell>> CreateGridRightHalf(vector<HexCell>& middle_column) const;

    /**
     * @fn  void HexGrid::SetupCellNeighbors();
     *
     * @brief   Calculates which cells are adjacent then calls HexCell's AddNeighbor.
     * @details This method is not implemented efficiently, runtime of O(n^2) 
     *          where n is the number of cells.
     *          Run the method only once near the start of the object's lifetime.
     */
    void SetupCellNeighbors();
};
}  // namespace Hexplosions