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
    if (!first_round_) {
        // Check if any players have been eliminated by the move (i.e. occupy 0 cells)
        auto new_end_iter = std::remove_if(active_player_ids_.begin(), 
            active_player_ids_.end(), 
            [this](size_t player) { return num_occupied_cells_[player] == 0; });

        if (new_end_iter != active_player_ids_.end()) {
            active_player_ids_.erase(new_end_iter, active_player_ids_.end());
            current_player_iter = std::find(active_player_ids_.begin(), 
                active_player_ids_.end(), current_player_);
        }
    }

    ++current_player_iter;
    if (current_player_iter == active_player_ids_.end()) {
        // Wrap around, it is the first player's turn again
        current_player_iter = active_player_ids_.begin();
        first_round_ = false;
    }
    current_player_ = *current_player_iter;
}

bool GameEngine::IsGameOver() {
    return active_player_ids_.size() == 1;
}

size_t GameEngine::GetWinningPlayerId() { 
    return active_player_ids_.front();
}
}  // namespace Hexplosions