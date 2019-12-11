#include "catch.hpp"

#include "game_engine.h"
#include "game_settings.h"
#include "hex_cell.h"
#include "hex_grid.h"

using Hexplosions::HexCell;
using Hexplosions::HexGrid;
using Hexplosions::GameSettings;
using Hexplosions::GameEngine;

TEST_CASE(
    "Test HexGrid constructor generates hexagonal cells in correct positions") {
    vector<ofVec3f> expected_cell_centers = {
        {272, 384},    {332, 349.36}, {332, 418.64}, {392, 314.72},
        {392, 384},    {392, 453.28}, {452, 280.08}, {452, 349.36},
        {452, 418.64}, {452, 487.92}, {512, 245.44}, {512, 314.72},
        {512, 384},    {512, 453.28}, {512, 522.56}, {572, 280.08},
        {572, 349.36}, {572, 418.64}, {572, 487.92}, {632, 314.72},
        {632, 384},    {632, 453.28}, {692, 349.36}, {692, 418.64},
        {752, 384}};

    GameSettings settings;
    GameEngine engine(settings);
    engine.setup();
    HexGrid grid_(ofVec3f(512, 384), engine);
    grid_.setup();
    REQUIRE(grid_.GetCells().size() == 25);

    int i = 0;
    for (const HexCell& cell : grid_.GetCells()) {
        ofVec3f actual_center = cell.GetCenter();
        REQUIRE(actual_center.x ==
                Approx(expected_cell_centers[i].x).epsilon(0.01));
        REQUIRE(actual_center.y ==
                Approx(expected_cell_centers[i].y).epsilon(0.01));
        i++;
    }
}