#pragma once

#include "ofMain.h"
#include "game_settings.h"
#include "hex_grid.h"

namespace Hexplosions {

/**
 * @class   GameEngine
 *
 * @brief   A game engine to manage players and turns.
 * @details Engine can
 *          1. Track active players (those that occupy at least one cell)    
 *          2. Track which player's turn it is
 *          2. Reject invalid player actions  
 *          3. Detect win condition
 *
 * @author  Estelle Lee
 * @date    3/12/2019
 */

class GameEngine {
  public:
    GameEngine();
    GameEngine(const GameSettings &settings);

    size_t GetGridSize() const;
    size_t GetNumPlayers() const;
    size_t GetCurrentPlayerId() const;

    void FinishCurrentTurn();
    
    bool IsGameOver();
    size_t GetWinningPlayerId();

    void SetHexGrid(HexGrid &hex_grid);

  private:
    GameSettings settings_;
    HexGrid *hex_grid_ptr_;

    vector<size_t> active_player_ids_; // Players who have no cells occupied are removed 
    vector<size_t>::iterator current_player_iter;
    size_t current_player_;
};
} // namespace Hexplosions