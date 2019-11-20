#pragma once

#include "ofMain.h"

constexpr float kPi = 3.14159266;
constexpr float kHexCellRadius = 20.0;
constexpr float kHexCellAngleDeg = 60.0;
constexpr float kHexCellAngleRad = kPi / 3.0;

class HexCell {
   public:
    HexCell(ofVec3f center);
    vector<ofVec3f> GetVertices();

   private:
    ofVec3f center_;
    ofVec3f right_vertex_;
    ofVec3f upper_right_vertex_;
    ofVec3f upper_left_vertex_;
    ofVec3f left_vertex_;
    ofVec3f lower_left_vertex_;
    ofVec3f lower_right_vertex_;
};