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

    // The following methods: MarkCellOccupied, MarkCellUnoccupied, TransferCell
    // help to keep track of the number of cells occupied by each player.
    /**
     * @fn  void GameEngine::MarkCellOccupied(size_t player_id);
     *
     * @brief   Increases number of cells occupied by player with player_id
     * @details Called when player makes a move on an empty cell
     *
     * @param   player_id   Identifier for the player.
     */
    void MarkCellOccupied(size_t player_id);

    /**
     * @fn  void GameEngine::MarkCellUnoccupied(size_t player_id);
     *
     * @brief   Decreases number of cells occupied by player with player_id
     * @details Called when a player leaves a cell, usually when they add enough atoms
     *          such that the cell explodes.
     *
     * @param   player_id   Identifier for the player.
     */
    void MarkCellUnoccupied(size_t player_id);

    /**
     * @fn  void GameEngine::TransferCell(size_t prev_player_id_, size_t curr_player_id);
     *
     * @brief   Transfer cell ownership between two players
     * @details Called when a player converts another player's cells, usually when
     *          a neighboring cell explodes.
     *
     * @param   prev_player_id_ Identifier for the player that occupied the cell prior to this move.
     * @param   curr_player_id  Identifier for the player that will occupy the cell after this move.
     */
    void TransferCell(size_t prev_player_id_, size_t curr_player_id);

    /**
     * @fn  void GameEngine::FinishCurrentTurn();
     *
     * @brief   Called from a HexCell object after player makes a valid move,
     *          updates the current player state.
     */
    void FinishCurrentTurn();

    /**
     * @fn  bool GameEngine::IsGameOver() const;
     *
     * @brief   Query if the game is over, i.e. some player has won
     *
     * @returns True if only one player occupies a non-zero number of cells
     */
    bool IsGameOver() const;

    /**
     * @fn  size_t GameEngine::GetWinningPlayerId() const;
     *
     * @brief   Gets winning player identifier
     * @details Undefined behavior if the game hasn't finished / there is no winner yet.
     *
     * @returns The winning player identifier.
     */
    size_t GetWinningPlayerId() const;
  private:
    const GameSettings& settings_;

    /** @brief   Contains only players that occupy at least one cell after the first round  
    /**          Players occupying no cells have lost the game and cannot take any more turns.
    */
    vector<size_t> active_player_ids_;
    vector<size_t>::iterator current_player_iter_;
    size_t current_player_;

    vector<size_t> num_occupied_cells_;

    bool is_first_round_ = true;
};
} // namespace Hexplosions