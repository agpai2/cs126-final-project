#include "game_engine.h"

namespace Hexplosions {
GameEngine::GameEngine() : GameEngine(GameSettings()) {}

GameEngine::GameEngine(const GameSettings &settings) :
    settings_(settings) {
    for (size_t i = 0; i < settings_.GetNumPlayers(); i++) {
        active_player_ids_.push_back(i);   
    }
    current_player_iter = active_player_ids_.begin();
    current_player_ = *current_player_iter;

    num_occupied_cells_.assign(settings_.GetNumPlayers(), 0);
}

size_t GameEngine::GetGridSize() const { 
    return settings_.GetGridSize();
}

size_t GameEngine::GetNumPlayers() const {
    return settings_.GetNumPlayers();
}

size_t GameEngine::GetCurrentPlayerId() const { 
    return current_player_; }

void GameEngine::MarkCellOccupied(size_t player_id) { 
    // cout << "Occupied: " << player_id << endl;
    ++num_occupied_cells_[player_id];
}

void GameEngine::MarkCellUnoccupied(size_t player_id) {
    // cout << "Unoccupied: " << player_id << endl;
    --num_occupied_cells_[player_id];
}

void GameEngine::TransferCell(size_t prev_player_id_, size_t curr_player_id) {
    MarkCellOccupied(curr_player_id);
    MarkCellUnoccupied(prev_player_id_);
}

void GameEngine::FinishCurrentTurn() {
    ++current_player_iter;
    if (current_player_iter == active_player_ids_.end()) {
        // Wrap around, it is the first player's turn again
        current_player_iter = active_player_ids_.begin();
    }
    current_player_ = *current_player_iter;
}

bool GameEngine::IsGameOver() { return false; }

size_t GameEngine::GetWinningPlayerId() { return size_t(); }
}  // namespace Hexplosions