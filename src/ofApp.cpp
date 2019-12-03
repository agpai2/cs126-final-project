#include "ofApp.h"

namespace Hexplosions {
//--------------------------------------------------------------
void ofApp::setup() { 
    SetupDisplayStateIntroduction();
}

//--------------------------------------------------------------
void ofApp::update() {}

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
    engine_ = GameEngine(intro_display_.GetSettings());
    intro_display_.exit();
    
    ofVec3f center(kWindowWidth / 2, kWindowHeight / 2, 0);
    hex_grid_ = HexGrid(center, engine_.GetGridSize());
    hex_grid_.setup();

    engine_.SetHexGrid(hex_grid_);
}

void ofApp::SetupDisplayStateEnd() {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

} // namespace Hexplosions