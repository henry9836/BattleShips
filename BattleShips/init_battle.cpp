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

int start_init(int debug, string name){
	srand((unsigned int)time(NULL));
	char keyInput;
	int asciiInput;
	bool cancel = false;
	bool boatsplaced = false;

	system("cls");

	int p1_1 = 0;
	int p2_1 = 0;

	string p1_board[10][10]; //ships
	string p1_board2[10][10]; //hits and misses
	string p2_board[10][10]; //ships
	string p2_board2[10][10]; //hits and misses

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
	int shiptype = 5;

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

			if (x != 1) {
				Beep(1000, 50);
				x -= 3;
			}
			else {
				Beep(200, 50);
			}

		}
		if (asciiInput == 72) { //up

			if (y != 1) {
				Beep(1500, 50);
				y -= 1;
			}
			else {
				Beep(200, 50);
			}
			
		}
		if (asciiInput == 77) { //right

			if (x != 28) {
				Beep(1000, 50);
				x += 3;
			}
			else {
				Beep(200, 50);
			}

		}
		if (asciiInput == 80) { //down

			if (shiptype == 5) { //aircraft carrier
				if (y != 6) {
					Beep(500, 50);
					y += 1;
				}
				else {
					Beep(200, 50);
				}
			}
			else { //default
				if (y != 10) {
					Beep(500, 50);
					y += 1;
				}
				else {
					Beep(200, 50);
				}
			}
		}

		if (debug == true) {
			GotoXY(0, 26);
			cout << "[DEBUG MODE]" << endl;
			GotoXY(0, 27);
			cout << "X: " << x << " Y: " << y << endl;
			GotoXY(0, 28);
			cout << "Magic Number: " << rand() % 1000000000 << endl;
			GotoXY(0, 29);
			cout << "Key: " << keyInput << " Ascii Value= " << asciiInput << endl;
			GotoXY(x, y);
		}

		if (shiptype == 5) { //maxs y:6 x:
			cout << "#";
			for (int i = 0; i < 5; i++) {
				GotoXY(x, y + i);
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