#pragma once

#include "game_settings.h"
#include "ofMain.h"

namespace Hexplosions {

/**
 * @class   EndgameDisplay
 *
 * @brief   The display that appears after the game finishes.
 *          Shows the winner of the game.
 *
 * @author  Estelle Lee
 * @date    11/12/2019
 */
class EndgameDisplay {
   public:
    EndgameDisplay();
    EndgameDisplay(size_t winner_id);

    // Method names follow OpenFrameworks convention
    void setup();
    void update();
    void draw();
    void exit();

   private:
    size_t winner_id_;
};
}  // namespace Hexplosions