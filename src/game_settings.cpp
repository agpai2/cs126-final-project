#include "game_settings.h"
        
namespace Hexplosions {
GameSettings::GameSettings() : 
    grid_size_(GameGridSize::SMALL), num_players_(kMinimumPlayers) {}

GameSettings::GameSettings(GameGridSize grid_size, size_t num_players) : 
    grid_size_(grid_size), num_players_(num_players) {}

size_t GameSettings::GetGridSize() { 
    return grid_size_;
}

size_t GameSettings::GetNumPlayers() {
    return num_players_;
}
}  // namespace Hexplosions