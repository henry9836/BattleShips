#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "animations.h"
#include "battle_init.h"
#include "battle.h"
#include "mainmenu.h"
#include "classes.h"

using namespace std;

Player player; // TF: Class Instance
AI ai;

bool gameover = false;

void draw_grids(int debug, string name, string p1_board[10][10], string p1_board2[10][10], string p2_board[10][10], string p2_board2[10][10]) {
	system("cls");
	GotoXY(0, 0);

	int p1_1 = 0;
	int p2_1 = 0;

	for (int h = 0; h < 3; h++) {
		for (int i = 0; i < 10; i++)    //This loops on the rows.
		{
			for (int j = 0; j < 10; j++) //This loops on the columns
			{
				if (h == 1) {
					if (p1_1 == 0) {
						GotoXY(0, 0);
						p1_1 = 1;
						cout << name << "'s Ships:" << endl;
					}
					cout << p1_board[i][j];
				}
				if (debug == 1) {
					if (h == 2) {
						if (p2_1 == 0) {
							//GotoXY(100, 0);
							p2_1 = 1;
							cout << "AI's Ships: " << endl;
						}
						cout << p2_board[i][j];
					}
				}
			}
			cout << "\t";
			for (int o = 0; o < 10; o++) //This loops on the columns of second grid
			{
				if (h == 1) {
					cout << p1_board2[i][o];
				}
				if (debug == 1) {
					if (h == 2) {
						cout << p2_board2[i][o];
					}
				}

			}

			cout << endl;
		}
		cout << endl << endl << endl;
	}
}

bool Fire(int xcord, int ycord, int ai_ycord, int ai_xcord, bool isAI, string p1_board[10][10], string p1_board2[10][10], string p2_board[10][10], string p2_board2[10][10]) {

	int& aihealth = ai.health; // TF: Reference
	int& phealth = player.health; 

	if (isAI == false) {

		if ((p2_board[ycord][xcord] != " X ") && (p2_board[ycord][xcord] != " o ")) { // TF: Logical Operator
			if (p2_board[ycord][xcord] == " # ") {
				p2_board[ycord][xcord] = " X ";
				p1_board2[ycord][xcord] = " X ";
				aihealth -= 1;
				Beep(300, 50);
				Beep(3000, 50);
				return true;
			}
			else {
				p2_board[ycord][xcord] = " o ";
				p1_board2[ycord][xcord] = " o ";
				Beep(300, 50);
				Beep(100, 50);
				return false;
			}
		}
		else {
			Beep(100, 50);
			return false;
		}
	}

	else if (isAI == true) {

			while (p1_board[ai_ycord][ai_xcord] == " X " || p1_board[ai_ycord][ai_xcord] == " o ") {
				ai_xcord = (rand() % 10); // TF: Arithmetic Operator
				ai_ycord = (rand() % 10);
				if (p1_board[ai_ycord][ai_xcord] != " X " && p1_board[ai_ycord][ai_xcord] != " o ") {
					break;
				}
			}

			if (p1_board[ai_ycord][ai_xcord] == " # ") {
				p2_board2[ai_ycord][ai_xcord] = " X ";
				p1_board[ai_ycord][ai_xcord] = " X ";
				phealth -= 1;
				Beep(300, 50);
				Beep(3000, 50);
				return true;
			}
			else {
				p2_board2[ai_ycord][ai_xcord] = " o ";
				p1_board[ai_ycord][ai_xcord] = " o ";
				Beep(300, 50);
				Beep(100, 50);
				return false;
			}
		}
	else {
		Beep(250, 10000);
		return false;
	}
	return false;


}

void player_turn(Player player, AI ai, bool isAI, bool turndone, int x, int y, bool cancel, int ycord, int xcord, int ai_ycord, int ai_xcord, int debug, string name, string p1_board[10][10], string p1_board2[10][10], string p2_board[10][10], string p2_board2[10][10]) {
	int& aihealth = ai.health;
	char keyInput;
	int asciiInput;
	isAI = false;
	turndone = false;

	while (turndone == false) {

		//MOVE CURSOR

		GotoXY(x, y);
		keyInput = _getch();
		asciiInput = keyInput;

		if (asciiInput == 72 && y != 1) { //up
			Beep(1500, 50);
			y -= 1;
			ycord -= 1;
			GotoXY(x, y);
			draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);
			cout << "*";
		}

		if (asciiInput == 75 && x != 33) { //left
			x -= 3;
			xcord -= 1;
			GotoXY(x, y);
			Beep(1000, 50);
			draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);
			cout << "*";
		}

		if (asciiInput == 77 && x != 60) { //right
			x += 3;
			xcord += 1;
			GotoXY(x, y);
			Beep(1000, 50);
			draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);
			cout << "*";
		}

		if (asciiInput == 80 && y != 10) {//down
			y += 1;
			ycord += 1;
			GotoXY(x, y);
			Beep(500, 50);
			draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);
			cout << "*";
		}

		if (asciiInput == 13) { //enter

			isAI = false;
			bool didIhittheAI = false;
			didIhittheAI = Fire(xcord, ycord, isAI, ai_ycord, ai_xcord, p1_board, p1_board2, p2_board, p2_board2);
			draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);
			if (aihealth <= 0) {
				GotoXY(0, 27);
				cout << "                                                ";
				GotoXY(0, 27);
				cout << "Player hit the AI!" << endl;
				isAI = false;
				turndone = true;
				break;
			}
			if (aihealth > 0) {
				if (didIhittheAI != true) {
					GotoXY(0, 27);
					cout << "                                                ";
					GotoXY(0, 27);
					cout << "Player missed the AI!" << endl;
					Sleep(700); //delay for reading msg
					isAI = true;
					turndone = true;
					break;
				}
				else {
					GotoXY(0, 27);
					cout << "                                                ";
					GotoXY(0, 27);
					cout << "Player Hit the AI!" << endl;
				}
			}
			else {
				isAI = true;
				turndone = true;
				break;
			}
		}

		if (debug == 1) { //Debug
			GotoXY(0, 26);
			cout << "[DEBUG MODE]" << endl;
			GotoXY(0, 27);
			cout << "                                                ";
			GotoXY(0, 27);
			cout << "player.health: " << player.health << endl;
			GotoXY(0, 28);
			cout << "                                                ";
			GotoXY(0, 28);
			cout << "ai.health: " << ai.health << endl;
			GotoXY(0, 29);
			cout << "                                                ";
			GotoXY(0, 29);
			cout << "p1_board2[" << xcord << ", " << ycord << "] = " << p1_board2[ycord][xcord];
			GotoXY(0, 30);
			cout << "p2_board[" << xcord << ", " << ycord << "] = " << p2_board[ycord][xcord];
			GotoXY(1, 1);
		}

	}

	return;
}

void AI_turn(Player player, AI ai, bool isAI, bool turndone, int x, int y, bool cancel, int ycord, int xcord, int ai_ycord, int ai_xcord, int debug, string name, string p1_board[10][10], string p1_board2[10][10], string p2_board[10][10], string p2_board2[10][10]) {
	int& phealth = player.health;
	isAI = true;
	turndone = false;

	while (turndone == false) {
		isAI = true;
		ai_xcord = (rand() % 10);
		ai_ycord = (rand() % 10);
		bool didIhittheplayer = false;
		didIhittheplayer = Fire(xcord, ycord, isAI, ai_ycord, ai_xcord, p1_board, p1_board2, p2_board, p2_board2);
		draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);

		if (phealth <= 0) {
			GotoXY(0, 27);
			cout << "                                                ";
			GotoXY(0, 27);
			cout << "AI missed the player!" << endl;
			Sleep(700); //delay for reading msg
			turndone = true;
			break;
		}
		if (didIhittheplayer != true) {
			GotoXY(0, 27);
			cout << "                                                ";
			GotoXY(0, 27);
			cout << "AI missed the player!" << endl;
			Sleep(700); //delay for reading msg
			isAI = false;
			turndone = true;
			break;
		}

		else {
			GotoXY(0, 27);
			cout << "                                                ";
			GotoXY(0, 27);
			cout << "AI hit the player!" << endl;
			Sleep(700); //delay for reading msg
		}
		

		if (debug == 1) { //Debug
			GotoXY(0, 26);
			cout << "[DEBUG MODE]" << endl;
			GotoXY(0, 27);
			cout << "                                                ";
			GotoXY(0, 27);
			cout << "X: " << x << " Y: " << y << endl;
			GotoXY(0, 28);
			cout << "                                                ";
			GotoXY(0, 28);
			cout << "Magic Number: " << rand() % 1000000000 << endl;
			GotoXY(0, 29);
			cout << "                                                ";
			GotoXY(0, 29);
			cout << "p1_board2[" << xcord << ", " << ycord << "] = " << p1_board2[ycord][xcord];
			GotoXY(0, 30);
			cout << "p2_board[" << xcord << ", " << ycord << "] = " << p2_board[ycord][xcord];
			GotoXY(1, 1);
		}

	}

	return;
}

bool battle(int debug, string name, string p1_board[10][10], string p1_board2[10][10], string p2_board[10][10], string p2_board2[10][10]) {
	
	player.health = 17;
	ai.health = 17;

	draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);
	bool cancel = false;
	bool isAI = false;

	while (gameover == false) {
		int x = 33;
		int y = 1;
		int xcord = 0;
		int ycord = 0;
		int ai_ycord = 0;
		int ai_xcord = 0;
		bool turndone = false;
		bool playerwin = false;

		/* Game */

		while (1 == 1) {
			/* PLAYER TURN */
			isAI = false;
			player_turn(player, ai, isAI, turndone, x, y, cancel, ycord, xcord, ai_ycord, ai_xcord, debug, name, p1_board, p1_board2, p2_board, p2_board2);

			if (ai.health <= 0) {
				playerwin = true;
				break;
			}

			draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);

			/* AI TURN */
			isAI = true;
			AI_turn(player, ai, isAI, turndone, x, y, cancel, ycord, xcord, ai_ycord, ai_xcord, debug, name, p1_board, p1_board2, p2_board, p2_board2);

			if (player.health <= 0) {
				playerwin = false;
				break;
			}

			draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);
		}

		/* END GAME */

		system("cls");

		if (playerwin == true) {
			animation(4);
		}
		else {
			animation(5);
		}
		return false;
	}
	return false;
}