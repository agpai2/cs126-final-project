#include "game_settings.h"
#include "ofApp.h"
#include "ofMain.h"

//========================================================================
int main() {
    ofSetupOpenGL(Hexplosions::GameSettings::kWindowWidth,
                  Hexplosions::GameSettings::kWindowHeight,
                  OF_WINDOW);  // <-------- setup the GL context

    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new Hexplosions::ofApp());
}
