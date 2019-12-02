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
            grid_.draw(); 
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
    settings_ = intro_display_.GetSettings();
    intro_display_.exit();

    ofVec3f screen_center(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    grid_ = HexGrid(screen_center, settings_.GetGridSize());
    grid_.setup();
}

void ofApp::SetupDisplayStateEnd() {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

} // namespace Hexplosions