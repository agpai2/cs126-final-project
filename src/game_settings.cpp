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

ofColor GameSettings::GetPlayerColor(size_t player_id) { 
    // Note: static const member variables of non-trivial types can't be
    // initialized in header files in C++11
    // Following code may be updated once OpenFrameworks supports C++17
    static const ofColor kPlayerColors[4] = {
        ofColor::red, ofColor::green, ofColor::blue, ofColor::white
    }; 

    try {
        return kPlayerColors[player_id];
    } catch (std::exception e) {
        return ofColor::black;
    }
}
}  // namespace Hexplosions