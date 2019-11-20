#pragma once

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

constexpr float kPi = 3.14159266;
constexpr float kHexCellRadius = 20.0;
constexpr float kHexCellAngleDeg = 60.0;
constexpr float kHexCellAngleRad = kPi / 3.0;

class HexCell : public ofxMSAInteractiveObject {
public:
	// Override methods from base class
    void setup();
    void exit();
    void update();
    void draw();
    void onPress(int x, int y, int button);

    HexCell(ofVec3f center);
    vector<ofVec3f> GetVertices();
    ofVec3f GetUpperRightVertex();
    ofVec3f GetLowerRightVertex();
    ofVec3f GetUpperLeftVertex();
    ofVec3f GetLowerLeftVertex();
    ofVec3f GetRightVertex();
    ofVec3f GetLeftVertex();

   private:
    ofVec3f center_;
    ofVec3f right_vertex_;
    ofVec3f upper_right_vertex_;
    ofVec3f upper_left_vertex_;
    ofVec3f left_vertex_;
    ofVec3f lower_left_vertex_;
    ofVec3f lower_right_vertex_;
};