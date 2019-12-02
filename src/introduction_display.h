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
    void SelectSmallGrid(bool &is_small_grid);
    void SelectMediumGrid(bool &is_medium_grid);
    void SelectLargeGrid(bool &is_large_grid);

    ofParameter<size_t> num_players_param_;
    ofParameter<GameGridSize> grid_size_param_;
    ofParameter<bool> small_grid_param_;
    ofParameter<bool> medium_grid_param_;
    ofParameter<bool> large_grid_param_;
    ofxPanel gui;

    GameGridSize grid_size_;
};
}  // namespace Hexplosions