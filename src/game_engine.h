#pragma once

#include "ofMain.h"
#include "game_settings.h"

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
    explicit GameEngine(const GameSettings& settings);
    void setup();

    size_t GetGridSize() const;
    size_t GetNumPlayers() const;
    size_t GetCurrentPlayerId() const;

    void MarkCellOccupied(size_t player_id);
    void MarkCellUnoccupied(size_t player_id);
    void TransferCell(size_t prev_player_id_, size_t curr_player_id);

    void FinishCurrentTurn();
    
    bool IsGameOver() const;
    size_t GetWinningPlayerId() const;
  private:
    const GameSettings& settings_;

    vector<size_t> active_player_ids_; // Players who have no cells occupied are removed 
    vector<size_t>::iterator current_player_iter_;
    size_t current_player_;

    vector<size_t> num_occupied_cells_;

    bool is_first_round_ = true;
};
} // namespace Hexplosions