#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string>
#include "animations.h"
#include "ships.h"
#include "mainmenu.h"

using namespace std;

string p1_board[10][10]; //ships
string p1_board2[10][10]; //hits and misses
string p2_board[10][10]; //ships
string p2_board2[10][10]; //hits and misses

void draw_grids(int debug, string name) {
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


int start_init(int debug, string name){

	srand((unsigned int)time(NULL));
	char keyInput;
	int asciiInput;
	bool cancel = false;
	bool boatsplaced = false;
	int amountmovedx = 0;

	system("cls");

	int p1_1 = 0;
	int p2_1 = 0;

	for (int h = 0; h < 3; h++) {
			for (int i = 0; i < 10; i++)    //This loops on the rows.
			{
				for (int j = 0; j < 10; j++) //This loops on the columns
				{
					if (h == 1) {
						p1_board[i][j] = " ~ ";
						p1_board2[i][j] = " ~ ";
					}
					if (h == 2) {
						p2_board[i][j] = " ~ ";
						p2_board2[i][j] = " ~ ";
					}
				}
			}
	}

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

	//Player Select Positions

	//random locations

	//player picked locations

	GotoXY(1, 1); // top left

	int x = 1;
	int y = 1;
	int xcord = 0;
	int ycord = 0;
	int shiptype = 5;
	bool horizontal = false;

	if (debug == true) {
		system("COLOR 0A");
	}
	else {
		system("COLOR 17");
	}

	while (boatsplaced == false) {

		//MOVE CURSOR

		GotoXY(x, y);
		keyInput = _getch();
		asciiInput = keyInput;

		if (asciiInput == 27) { //esc button
			animation(2);
			cancel = true;
			break;
		}

		if (asciiInput == 75) { //left
			if (horizontal == false) {
				if (x != 1) {
					Beep(1000, 50);
					x -= 3;
					xcord -= 1;
					draw_grids(debug, name);
				}
				else {
					Beep(200, 50);
				}
			}

			if (horizontal == true) {
				if (x != 1) {
					Beep(1000, 50);
					x -= 3;
					xcord -= 1;
					draw_grids(debug, name);
				}
				else {
					Beep(200, 50);
				}
			}

		}
		if (asciiInput == 72) { //up
			if (horizontal == false) {
				if (y != 1) {
					Beep(1500, 50);
					y -= 1;
					ycord -= 1;
					draw_grids(debug, name);
				}
				else {
					Beep(200, 50);
				}
			}
			if (horizontal == true) {
				if (y != 1) {
					Beep(1500, 50);
					y -= 1;
					ycord -= 1;
					draw_grids(debug, name);
				}
				else {
					Beep(200, 50);
				}
			}
			
		}
		if (asciiInput == 77) { //right
			if (horizontal == false) {
				if (x != 28) {
					Beep(1000, 50);
					x += 3;
					xcord += 1;
					draw_grids(debug, name);
				}
				else {
					Beep(200, 50);
				}
			}
			if (horizontal == true) {
				if (x != 16) {
					Beep(1000, 50);
					x += 3;
					xcord += 1;
					draw_grids(debug, name);
				}
				else {
					Beep(200, 50);
				}
			}
		}

		if (asciiInput == 114) { //r

			if (horizontal == false) {
				if (x <= 16) {
					if (y <= 10) {
						horizontal = !horizontal;
						draw_grids(debug, name);
						Beep(250, 50);
					}
				}
			}
			
			else if (horizontal == true) {
				if (x <= 28) {
					if (y <= 6) {
						horizontal = !horizontal;
						draw_grids(debug, name);
						Beep(250, 50);
						
					}
				}
			}
		}

		if (asciiInput == 80) { //down

			if (shiptype == 5) { //aircraft carrier
				if (horizontal == false) {
					if (y != 6) {
						Beep(500, 50);
						y += 1;
						ycord += 1;
						draw_grids(debug, name);
					}
				}

				else if (horizontal == true) {
					if (y != 10) {
						Beep(500, 50);
						y += 1;
						ycord += 1;
						draw_grids(debug, name);
					}
				}
				else {
					Beep(200, 50);
				}
			}
			else { //default
				if (y != 10) {
					Beep(500, 50);
					y += 1;
					ycord += 1;
					draw_grids(debug, name);
				}
				else {
					Beep(200, 50);
				}
			}
		}

		if (asciiInput == 13) { //enter

			if (x != 28) {
				Beep(1750, 50);

				//set ships
				if (shiptype == 5) {
					if (horizontal == false) {
						p1_board[ycord][xcord] = " # "; // invert fix
						p1_board[ycord+1][xcord] = " # ";
						p1_board[ycord+2][xcord] = " # ";
						p1_board[ycord+3][xcord] = " # ";
						p1_board[ycord+4][xcord] = " # ";

						shiptype = 4;
					}

					if (horizontal == true) {
						p1_board[ycord][xcord] = " # "; // invert fix
						p1_board[ycord][xcord + 1] = " # ";
						p1_board[ycord][xcord + 2] = " # ";
						p1_board[ycord][xcord + 3] = " # ";
						p1_board[ycord][xcord + 4] = " # ";

						shiptype = 4;
					}
				}

				draw_grids(debug, name);
				/*xcord = 0;
				ycord = 0;*/
				GotoXY(1,1);
			}
			else {
				Beep(200, 50);
			}

		}

		if (debug == true) {
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
			cout << "Key: " << keyInput << " Ascii Value= " << asciiInput << endl;
			GotoXY(0, 30);
			cout << "                                                ";
			GotoXY(0, 30);
			cout << "p1_board[" << xcord << ", " << ycord << "] = " << p1_board[xcord, ycord];
			GotoXY(x, y);
		}

		if (shiptype == 5) { //maxs y:6 x:?
			if (horizontal == false) {
				cout << "#";
				for (int i = 0; i < 5; i++) { //print ship on screen
					GotoXY(x, y + i);
					cout << "#";
				}
			}
			if (horizontal == true) {
				cout << "#";
				GotoXY(x + 3, y);
				cout << "#";
				GotoXY(x + 6, y);
				cout << "#";
				GotoXY(x + 9, y);
				cout << "#";
				GotoXY(x + 12, y);
				cout << "#";
			}
			GotoXY(x, y);
		}
	}

	if (cancel == true) {
		mainmenu();
		exit(0);
	}

	return 0;
}