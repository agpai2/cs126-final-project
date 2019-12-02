#include "introduction_display.h"

namespace Hexplosions {
void IntroductionDisplay::setup() {
    gui.setup("Game Settings");

    small_grid_param_.addListener(this, &IntroductionDisplay::SelectSmallGrid);
    medium_grid_param_.addListener(this,
                                   &IntroductionDisplay::SelectMediumGrid);
    large_grid_param_.addListener(this, &IntroductionDisplay::SelectLargeGrid);

    gui.add(num_players_param_.set("Number of Players", kMinimumPlayers,
                                   kMinimumPlayers, kMaximumPlayers));
    gui.add(small_grid_param_.set("Small", true));
    gui.add(medium_grid_param_.set("Medium", false));
    gui.add(large_grid_param_.set("Large", false));
    gui.add(start_.setup("Start Game"));
}

void IntroductionDisplay::draw() { 
    gui.draw(); 
}

void IntroductionDisplay::update() {}

void IntroductionDisplay::exit() {}

void IntroductionDisplay::SelectSmallGrid(bool &is_small_grid) { 
    if (grid_size_ == GameGridSize::SMALL) {
        is_small_grid = true;
        return;
    }
    if (is_small_grid) {
        grid_size_ = GameGridSize::SMALL;
        medium_grid_param_ = false;
        large_grid_param_ = false;
    }
}

void IntroductionDisplay::SelectMediumGrid(bool &is_medium_grid) {
    if (grid_size_ == GameGridSize::MEDIUM) {
        is_medium_grid = true;
        return;
    }
    if (is_medium_grid) {
        grid_size_ = GameGridSize::MEDIUM;
        small_grid_param_ = false;
        large_grid_param_ = false;
    }
}

void IntroductionDisplay::SelectLargeGrid(bool &is_large_grid) { 
    if (grid_size_ == GameGridSize::LARGE) {
        is_large_grid = true;
        return;
    }
    if (is_large_grid) {
        grid_size_ = GameGridSize::LARGE;
        medium_grid_param_ = false;
        small_grid_param_ = false;
    }
}

GameSettings IntroductionDisplay::GetSettings() {
    return GameSettings(grid_size_, num_players_param_);
}
}  // namespace Hexplosions