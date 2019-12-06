#pragma once

#include "game_settings.h"
#include "ofMain.h"

namespace Hexplosions {
class EndgameDisplay {
   public:
    EndgameDisplay();
    EndgameDisplay(size_t winner_id);

    void setup();
    void update();
    void draw();
    void exit();

   private:
    size_t winner_id_;
};
}  // namespace Hexplosions