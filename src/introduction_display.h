#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "game_settings.h"

namespace Hexplosions {
/**
 * @class   IntroductionDisplay
 *
 * @brief   The initial display that appears when the game launches. 
 *          User can choose game settings and start game from here.
 *
 * @author  Estelle Lee
 * @date    1/12/2019
 */
class IntroductionDisplay {
  public:
    // Method names follow OpenFrameworks convention
    void setup();
    void draw();
    void update();
    void exit();

    ofxButton start_;
    GameSettings GetSettings();

  private:
    ofParameter<size_t> num_players_param_;
    ofxButton small_grid_button_;
    ofxButton medium_grid_button_;
    ofxButton large_grid_button_;
    ofxPanel gui;
};
}  // namespace Hexplosions