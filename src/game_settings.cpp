#include "game_settings.h"
        
namespace Hexplosions {
GameSettings::GameSettings() : 
    grid_size_(GameGridSize::SMALL), num_players_(kMinimumPlayers) {}

GameSettings::GameSettings(GameGridSize grid_size, size_t num_players) : 
    grid_size_(grid_size), num_players_(num_players) {}

size_t GameSettings::GetGridSize() const { 
    return grid_size_;
}

size_t GameSettings::GetNumPlayers() const {
    return num_players_;
}

ofColor GetPlayerColor(size_t player_id) { 
    switch (player_id) { 
        case 0:
            return ofColor::red;
        case 1:
            return ofColor::green;
        case 2:
            return ofColor::blue;
        case 3:
            return ofColor::black;
        default:
            return ofColor::white;
    }
}
}  // namespace Hexplosions