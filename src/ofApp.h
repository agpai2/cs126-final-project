#pragma once

#include "ofMain.h"

#include "endgame_display.h"
#include "game_engine.h"
#include "hex_grid.h"
#include "introduction_display.h"

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

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

   private:
    GameDisplayState display_state_;
    void SetupDisplayStateIntroduction();
    void SetupDisplayStateGame();
    void SetupDisplayStateEnd();

    IntroductionDisplay intro_display_;
    EndgameDisplay end_display_;

    GameSettings settings_;
    GameEngine engine_ = GameEngine(settings_);
    HexGrid hex_grid_ = HexGrid(ofVec3f(kWindowWidth / 2, kWindowHeight / 2), engine_);
};
}  // namespace Hexplosions