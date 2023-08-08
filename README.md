# Board_Game
## Overview
This is an elementary board game implemented in C++ without using any GUI 

## Game Mechanics
There is an island with a bridge **B** always in the middle row and the rightmost of the island, with 2 cats **C** whose positions are defined by the user.
The user chooses the number, names, and positions of the animals he/she wants to play with.
Each animal has 4 movements only specified by the letters **U** for up, **R** for right, **L** for left, and **D** for down.
After these movements, there are 4 possibilities for each animal:
1. Drowned outside the island. --> if an animal got out of the island borders during its movement.
2. Eaten by the cat. --> if an animal during its movement stepped on one of the 2 cats positions.
3. Starved... Stuck inside the board. --> if an animal stayed on the island without reaching the bridge or getting eaten by a cat.
4. Escaped through the bridge. --> if an animal reached the bridge of winning.

The only way to win is by escaping through the bridge.

## User Guide
If you want to try the game download the whole folder and run the file named **game.exe**.
