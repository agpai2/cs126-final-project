#pragma once

#include <vector>
#include "ofMain.h"

namespace Hexplosions {
/**
 * @enum    GameGridSize
 *
 * @brief   Length (number of cells) of the game grid
 *
 */
enum GameGridSize { SMALL = 5, MEDIUM = 7, LARGE = 9 };

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

    static constexpr size_t kMinimumPlayers = 2;
    static constexpr size_t kMaximumPlayers = 4;

    static constexpr size_t kWindowWidth = 1280;
    static constexpr size_t kWindowHeight = 900;

    static ofColor GetPlayerColor(size_t player_id);
   private:
    GameGridSize grid_size_;
    size_t num_players_;
};
}  // namespace Hexplosions