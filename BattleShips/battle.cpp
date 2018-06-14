#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "animations.h"
#include "battle_init.h"
#include "battle.h"
#include "mainmenu.h"

using namespace std;

bool gameover = false;

void draw_grids(int debug, string name, string p1_board[10][10], string p1_board2[10][10], string p2_board[10][10], string p2_board2[10][10]) {
	system("cls");

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

bool battle(int debug, string name, string p1_board[10][10], string p1_board2[10][10], string p2_board[10][10], string p2_board2[10][10]) {

	draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);
	bool cancel = false;

	while (gameover == false) {

		/* PLAYER TURN */
		int x = 33;
		int y = 1;
		int xcord = 0;
		int ycord = 0;
		char keyInput;
		int asciiInput;
		bool turndone = false;

		while (turndone == false) {

			//MOVE CURSOR

			GotoXY(x, y);
			keyInput = _getch();
			asciiInput = keyInput;

			if (asciiInput == 27) { //esc button
				animation(2);
				//cancel = true;
				break;
			}

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
				cout <<  "*";
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
				draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);
			}


			if (debug == true) {//
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

			/* AI TURN */



		}
		//return true for player win, false for ai win

		if (cancel == true) {
			mainmenu();
			return false;
		}

		return false;
	}
}