# Overview
Hexplosions is a 2-4 player strategy game played on a hexagonal grid. The objective is to dominate the grid and eliminate all cells of their opponents' color. See [rules](#Rules).

# Build Requirements
Running Hexplosions requires:
1. 64-bit Microsoft Windows
2. Visual Studio 2017 Community (Enterprise probably works too)
3. OpenFrameworks 0.11.0 and above

# Installation
1. If you don't have Visual Studio 2017, [install Visual Studio](https://docs.microsoft.com/en-us/visualstudio/install/install-visual-studio?view=vs-2017).
2. If you don't have OpenFrameworks, [download it](https://openframeworks.cc/download/) and follow the instructions in the [setup guide](https://openframeworks.cc/setup/vs/).
3. Install the [ofxMSAInteractiveObject library](https://github.com/memo/ofxMSAInteractiveObject) as an OpenFrameworks addon.
4. Clone this repository using 
```git clone https://github.com/CS126FA19/fantastic-finale-estelle0500.git```
5. Build and run the project from Visual Studio.

# Documentation
This codebase (tries to) follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) with Doxygen-style documentation. You can generate your own HTML version of the documentation, see [the guide on the Doxygen page](http://www.doxygen.nl/manual/doxygen_usage.html).

# Rules 
On each player's turn, they can make one of the following moves:
1. Add an atom to an unoccupied cell
2. Add an atom to a cell they already occupy

When the number of atoms in a cell reaches the critical mass (equal to the number of neighbors the cell has), the cell "explodes" and all its atoms are distributed to its neighbors. Hence each neighbor will gain one atom. Note that this may cause the neighbor cells to reach critical mass, causing even more explosions!

The game ends when only one player occupies any cells.