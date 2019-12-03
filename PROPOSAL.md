# CS 126 Final Project Proposal: Hexplosions
## Description
Hexplosions is a game based on the multiplayer strategy game "Chain Reaction" (see [this video](https://www.youtube.com/watch?v=e4qcgvgPWvg) for a demonstration of gameplay). The original game is played on a square grid but Hexplosions is played on the superior hexagonal grid. Additionally, Hexplosions has an element of chance (!) whereby cells may randomly explode before reaching critical mass. Non-deterministic games are more fun because computers always beat us at deterministic perfect-information games...

## Development Timeline (Tentative)
The work is split into 3 major categories: engine, graphics, and user interface (UI).

| Week | Engine | Graphics | UI |
|------|--------|----------|----|
|1|Cell class can:<ul><li>Track number of atoms</li><li>Add atom</li><li>Track neighbors</li></ul>|Game screen displays:<ul><li>5x5x5 hexagonal grid</li><li>Number of atoms in the cell (an ASCII symbol, not graphical)</li></ul>|User can interact by:<ul><li>Clicking on a cell to increment the number of atoms in it</li></ul>|
|2|Cell class can:<ul><li>Detect when critical mass is reached</li><li>Distribute its atoms to its neighbors (the "chain reaction")</li></ul>|Game screen displays:<ul><li>Variable size hexagonal grid</li></ul>Introduction screen displays:<ul><li>List of board sizes</li><li>Selector for number of players</li><li>Abridged rules</li></ul>|User can interact by:<ul><li>Clicking to select board size</li><li>Dragging slider or typing number into box to select number of players</li></ul>
|3|Cell class can:<ul><li>Track which player occupies the cell</ul></li>Engine class can:<ul><li>Track player's turns</li><li>Determine win/lose conditions</li><li>Reject invalid moves (e.g. clicking on a cell occupied by another player)</li></ul>|Game screen displays:<ul><li>Number of atoms in cell, represented by fused circles</li><li>Which player's turn it is</li><li>Error message on invalid move</li></ul>|User can interact by:<ul><li>Hovering over cell highlights it</li></ul>|
|4|Cell class can:<ul><li>Randomly trigger explosion</li></ul>|[EXTRAS](#Extensions-Extras-Exciting-Stuff-A-Largely-Unfiltered-List)|[EXTRAS](#Extensions-Extras-Exciting-Stuff-A-Largely-Unfiltered-List)|

## External Libraries
* [ofxMSAInteractiveObject](https://github.com/memo/ofxMSAInteractiveObject) to make it easier to detect what the user is clicking on 

## Extensions, Extras, Exciting Stuff (A Largely Unfiltered List)
|Extension|Difficulty Rating (out of 5)|Fun Rating (out of 5)|
|---------|-----------------|----------|
|Explosion sounds that get louder for longer chain reactions|1.5|4.5 (scares your neighbors, but also ruins your hearing)|
|3D grids|4 (need 3D rendering, UI of selecting cell is difficult)|2|
|Using iClickers as a console to play the game "remotely"|4.99 (I don't know if I need custom hardware to detect the emitted radio waves)|5 (benefits bored students)|
|Irregular grids (e.g. mix of triangular and square cells)|depends on how irregular|4 (more replayability)|
|AI Player|4-5 (it seems [an AI player has been written for Chain Reaction](https://github.com/Agnishom/ChainReactionAI))|3.5 (the AI would probably wreck the human player)
|Better animations (original game has rotating/vibrating atoms)|? (I don't know how to do this)|3|

