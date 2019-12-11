#include "ofApp.h"

namespace Hexplosions {
//--------------------------------------------------------------
void ofApp::setup() { 
    ofSetBackgroundColor(ofColor::black);
    SetupDisplayStateIntroduction();
}

//--------------------------------------------------------------
void ofApp::update() { 
    if (display_state_ == GameDisplayState::GAME && engine_.IsGameOver()) {
        SetupDisplayStateEnd();    
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    switch (display_state_) {
        case GameDisplayState::INTRODUCTION:
            intro_display_.draw();
            break;
        case GameDisplayState::GAME:
            hex_grid_.draw(); 
            break;
        case GameDisplayState::END:
            end_display_.draw();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

void ofApp::SetupDisplayStateIntroduction() {
    display_state_ = GameDisplayState::INTRODUCTION;
    intro_display_.setup();
    intro_display_.start_.addListener(this, &ofApp::SetupDisplayStateGame);
}

void ofApp::SetupDisplayStateGame() {
    display_state_ = GameDisplayState::GAME;
    settings_ = intro_display_.GetSettings();
    intro_display_.exit();

    engine_.setup();
    hex_grid_.setup();
}

void ofApp::SetupDisplayStateEnd() {
    display_state_ = GameDisplayState::END;
    end_display_ = EndgameDisplay(engine_.GetWinningPlayerId());
    end_display_.setup();
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

} // namespace Hexplosions