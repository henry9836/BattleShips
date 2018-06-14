#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <time.h>
#include "animations.h"
#include "battle_init.h"
#include "mainmenu.h"
#include "battle.h"


/*
Required Game Features: The game-play must be implemented as per the description under the Game-play and Rules section. Game-play must be bug free.

The game setup phase must allow the player to set up the ships’ positions via one of two options: Computer randomly generates positions and 
orientations for the player’s ships. Player specifies the position and orientation of each ship individually. Both of the above options must be implemented.

There is to be only one game mode, single player, which allows one human player to play headto-head with the computer AI. The AI does not need to be complex, 
but must be functional to allow an interactive game of Battleship.

A summary of the game must be displayed when a game is over, clearly identifying the winner.

The game must provide a Debug mode that displays all the four grids (Player-Computer Ship placement grid and Player- Computer hit/miss grid) in game. 
The debug mode must be accessible from the main menu screen

1 5ship, 1 4ship, 2 3ship, 1 2ship

CHECKLIST

[x] Display 4 Grids
[x] Debug Mode that shows all grids (accessible in main menu)
[x] Display only player grids for playing
[X] Randomly pick Boat Locations
[X] Player Can Pick Boat Locations
[X] Ship Classes
[] AI
[] Summary Of Game After Finished


*/



using namespace std;



int main() {

	HWND console = GetConsoleWindow();
	RECT w;
	GetWindowRect(console, &w);
	
	MoveWindow(console, w.left, w.top, 600, 550, TRUE); //Resize console window
	mainmenu();

	return 0;
}