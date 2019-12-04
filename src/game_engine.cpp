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
}

size_t GameEngine::GetGridSize() const { 
    return settings_.GetGridSize();
}

size_t GameEngine::GetNumPlayers() const {
    return settings_.GetNumPlayers();
}

size_t GameEngine::GetCurrentPlayerId() const { 
    return current_player_;
}

void GameEngine::FinishCurrentTurn() {
    ++current_player_iter;
    if (current_player_iter == active_player_ids_.end()) {
        // Wrap around, it is the first player's turn again
        current_player_iter = active_player_ids_.begin();
    }
    current_player_ = *current_player_iter;

    // TODO: Check if any players have been eliminated by the latest move
}

bool GameEngine::IsGameOver() { return false; }

size_t GameEngine::GetWinningPlayerId() { return size_t(); }

void GameEngine::SetHexGrid(HexGrid &hex_grid) {
    hex_grid_ptr_ = &hex_grid;
}
}  // namespace Hexplosions