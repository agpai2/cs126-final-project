# Progress
### 11/20
- Generated hexagonal grid graphics
- Tracked and displayed number of atoms in individual cell
- Added listener to mouse clicks which increment number of atoms in a cell

### 12/1
- Added explosion game mechanic
    - Tracked cell's neighbors
    - Distributed atoms to neighbors on reaching capacity
    - Checked neighbors' explosion condition (and recursively called explode if condition is met)
- Added introduction screen for user to choose game settings
- Linked introduction screen to main game screen

### 12/3
- Added game engine (stores and modifies game state)
- Tracked player turns
    - Disallowed players from clicking on cells that do not belong to them
    - Calculated player which has the next turn (may not be in order due to eliminations)
- Eliminated players when they occupy 0 cells

# Issues
See Github Issues. 

# Remaining work
- Exit game when only 1 player remains, show an endgame screen with the winner
- Display information on game screen:
    - Which players are still in the game
    - Whose turn it is
    - If the attempted move was invalid
- Improve UI