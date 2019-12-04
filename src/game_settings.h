#pragma once

#include "ofMain.h"

namespace Hexplosions {
constexpr size_t kWindowWidth = 1280;
constexpr size_t kWindowHeight = 900;

/**
 * @enum    GameGridSize
 *
 * @brief   Length (number of cells) of the game grid
 *
 */
enum GameGridSize { SMALL = 5, MEDIUM = 7, LARGE = 9 };

constexpr size_t kMinimumPlayers = 2;
constexpr size_t kMaximumPlayers = 4;

/**
 * @class   GameSettings
 *
 * @brief   Game settings that can be modified by the user before the game
 * starts.
 *
 * @author  Estelle Lee
 * @date    1/12/2019
 */

class GameSettings {
   public:
    GameSettings();
    GameSettings(GameGridSize grid_size, size_t num_players);
    size_t GetGridSize() const;
    size_t GetNumPlayers() const;

   private:
    GameGridSize grid_size_;
    size_t num_players_;
};

ofColor GetPlayerColor(size_t player_id);

// Getting read access violation exception when using a const array instead of
// GetPlayerColor() const ofColor kPlayerColors[4] = {ofColor(255, 0, 0),
// ofColor(0, 255, 0),
//                                      ofColor(0, 0, 255),
//                                      ofColor(255, 255, 255)};
//
// This version does not work. TODO: Figure out why
// const ofColor kPlayerColors[4] = { ofColor::red, ofColor::green,
// ofColor::blue, ofColor::black };
}  // namespace Hexplosions