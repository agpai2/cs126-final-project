#pragma once

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

namespace Hexplosions {
constexpr float kPi = 3.14159266;
constexpr float kHexCellRadius = 40.0;
constexpr float kHexCellDiameter = kHexCellRadius * 2;
constexpr float kHexCellAngleDeg = 60.0;
constexpr float kHexCellAngleRad = kPi / 3.0;

/**
 * @class   HexCell
 *
 * @brief   A hexagonal grid cell that is displayed on-screen and interactive.
 * @details The class provides the following functionality:
 *          1. Draw hexagon on screen  
 *          2. Draw number of atoms (simple game entity) in cell  
 *          3. Allow user to click on cell, which increases number of atoms in cell  
 *          4. Controls explosion behavior (game mechanic) which is triggered when   
 *             number of atoms exceeds threshold
 *
 * @author  Estelle Lee
 * @date    1/12/2019
 */
class HexCell : public ofxMSAInteractiveObject {
  public:
    HexCell(ofVec3f center);

	// Override methods from base class
    void setup();
    void exit();
    void update();
    void draw();
    void onPress(int x, int y, int button);

    // Getters for the location of the hexagon on screen
    vector<ofVec3f> GetVertices();
    ofVec3f GetCenter();
    ofVec3f GetUpperRightVertex();
    ofVec3f GetLowerRightVertex();
    ofVec3f GetUpperLeftVertex();
    ofVec3f GetLowerLeftVertex();
    ofVec3f GetRightVertex();
    ofVec3f GetLeftVertex();

	vector<HexCell*>& GetNeighbors();
	void AddNeighbor(HexCell &neighbor);

  private:
    // Vertices of the hexagon on screen
    ofVec3f center_;
    ofVec3f right_vertex_;
    ofVec3f upper_right_vertex_;
    ofVec3f upper_left_vertex_;
    ofVec3f left_vertex_;
    ofVec3f lower_left_vertex_;
    ofVec3f lower_right_vertex_;

	size_t atoms_ = 0;
	vector<HexCell*> neighbor_cells_;
};
} // namespace Hexplosions