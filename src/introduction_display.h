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
    /**
     * @fn  void IntroductionDisplay::SelectSmallGrid(bool &is_small_grid);
     *
     * @brief   Event listener that is triggered when user clicks on the small 
     *          grid button
     *          Sets grid_size_param_ to SMALL
     *
     * @param [in,out]  is_small_grid   True if small grid button is checked
     */
    void SelectSmallGrid(bool &is_small_grid);

    /**
     * @fn  void IntroductionDisplay::SelectMediumGrid(bool &is_medium_grid);
     *
     * @brief   Event listener that is triggered when user clicks on the medium
     *          grid button
     *          Sets grid_size_param_ to MEDIUM
     *
     * @param [in,out]  is_medium_grid   True if medium grid button is checked
     */
    void SelectMediumGrid(bool &is_medium_grid);

    /**
     * @fn  void IntroductionDisplay::SelectLargeGrid(bool &is_large_grid);
     *
     * @brief   Event listener that is triggered when user clicks on the large
     *          grid button
     *          Sets grid_size_param_ to LARGE
     *
     * @param [in,out]  is_large_grid   True if large grid button is checked
     */
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