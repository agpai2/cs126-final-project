#pragma once

#include "ofMain.h"

#include "displays/endgame_display.h"
#include "game_engine.h"
#include "game_elements/hex_grid.h"
#include "displays/introduction_display.h"

namespace Hexplosions {

/**
 * @enum    GameDisplayState
 *
 * @brief   Values that represent the display screens
 */
enum GameDisplayState { INTRODUCTION, GAME, END };

/**
 * @class   ofApp
 *
 * @brief   Main application that controls the various game screens
 *
 * @author  Estelle Lee
 * @date    1/12/2019
 */

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();

   private:
    /**
     * @fn  void ofApp::SetupDisplayStateIntroduction();
     *
     * @brief   Sets up the introduction display which will be drawn on the next frame
     *          onwards until the display state transitions to game display.
     */
    void SetupDisplayStateIntroduction();

    /**
     * @fn  void ofApp::SetupDisplayStateGame();
     *
     * @brief   Sets up the game display which will be drawn on the next frame
     *          onwards until the display state transitions to endgame display.
     */
    void SetupDisplayStateGame();

    /**
     * @fn  void ofApp::SetupDisplayStateEnd();
     *
     * @brief   Sets up the endgame display which will be drawn on the next frame
     *          onwards until the user closes the app.
     */
    void SetupDisplayStateEnd();

    GameDisplayState display_state_;
    IntroductionDisplay intro_display_;
    EndgameDisplay end_display_;

    GameSettings settings_;
    GameEngine engine_ = GameEngine(settings_);
    HexGrid hex_grid_ = HexGrid(
        ofVec3f(GameSettings::kWindowWidth / 2, GameSettings::kWindowHeight / 2), 
        engine_);
};
}  // namespace Hexplosions