#include "endgame_display.h"

namespace Hexplosions {
EndgameDisplay::EndgameDisplay(): EndgameDisplay(0) {}

EndgameDisplay::EndgameDisplay(size_t winner_id): winner_id_(winner_id) {}

void EndgameDisplay::setup() {}

void EndgameDisplay::update() {}

void EndgameDisplay::draw() { 
    ofSetColor(GetPlayerColor(winner_id_));
    std::string win_message =
        "Game over.\nPlayer " + to_string(winner_id_ + 1) + " won!";
    ofDrawBitmapString(win_message, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
}

void EndgameDisplay::exit() {}
} // namespace Hexplosions