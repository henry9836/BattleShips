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

bool checkforships(int ship, int x, int y, bool horizontal) {
	bool result = false;
	
	if (ship == 1) {
		if (horizontal == false) {
			if ((p1_board[x][y] != "#") && (p1_board[x][y+1] != "#")) {
				result = true;
			}
			else {
				result = false;
			}
		}
		if (horizontal == true) {
			if ((p1_board[x][y] != "#") && (p1_board[x+1][y] != "#")) {
				result = true;
			}
			else {
				result = false;
			}
		}
	}

	if (result == false) {
		cout << "Denied";
	}

	return result;
}


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

	string tmp;
	cout << "Select a placement mode (s)elf placement / (r)andmoise: ";
	cin >> tmp;
	while (1 == 1){
		if (tmp == "r") {
			break;
		}
		if (tmp == "s") {
			break;
		}
		system("cls");
		cout << "Invalid Input please enter a valid option" << endl;
		cout << "Select a placement mode (s)elf placement / (r)andmoise: ";
		cin >> tmp;
	}
	system("cls");

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
	if (tmp == "s") {
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
				if (shiptype == 5) {
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
				if (shiptype == 4) {
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
						if (x != 19) {
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

				if (shiptype == 3) {
					if (horizontal == false) {
						if (x <= 27) {
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
						if (x <= 21) {
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

				if (shiptype == 2) {
					if (horizontal == false) {
						if (x <= 27) {
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
						if (x <= 21) {
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


				if (shiptype == 1) {
					if (horizontal == false) {
						if (x <= 28) {
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
						if (x < 25) {
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
				}
				if (shiptype == 4) { //destoryer
					if (horizontal == false) {
						if (y != 7) {
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
				}

				if (shiptype == 3) { //sub
					if (horizontal == false) {
						if (y != 8) {
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
				}


				if (shiptype == 2) { //battleship
					if (horizontal == false) {
						if (y != 8) {
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
				}

				if (shiptype == 1) { //u-boat
					if (horizontal == false) {
						if (y != 9) {
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
				}

				else {
					Beep(200, 50);
				}
			}

			if (asciiInput == 114) { //r
				if (shiptype == 5) {
					if (horizontal == false) {
						if (x <= 16) {
							if (y <= 10) {
								horizontal = !horizontal;
								draw_grids(debug, name);
								Beep(250, 50);
							}
							else {
								Beep(200, 50);
							}
						}
						else {
							Beep(200, 50);
						}
					}

					else if (horizontal == true) {
						if (x <= 28) {
							if (y <= 6) {
								horizontal = !horizontal;
								draw_grids(debug, name);
								Beep(250, 50);

							}
							else {
								Beep(200, 50);
							}
						}
						else {
							Beep(200, 50);
						}
					}
				}

				if (shiptype == 4) {
					if (horizontal == false) {
						if (x <= 19) {
							if (y <= 7) {
								horizontal = !horizontal;
								draw_grids(debug, name);
								Beep(250, 50);
							}
							else {
								Beep(200, 50);
							}
						}
						else {
							Beep(200, 50);
						}
					}

					else if (horizontal == true) {
						if (x <= 19) {
							if (y <= 7) {
								horizontal = !horizontal;
								draw_grids(debug, name);
								Beep(250, 50);

							}
							else {
								Beep(200, 50);
							}
						}
						else {
							Beep(200, 50);
						}
					}
				}

				if (shiptype == 3) {
					if (horizontal == false) {
						if (x <= 22) {
							if (y <= 10) {
								horizontal = !horizontal;
								draw_grids(debug, name);
								Beep(250, 50);
							}
							else {
								Beep(200, 50);
							}
						}
						else {
							Beep(200, 50);
						}
					}

					else if (horizontal == true) {
						if (x <= 28) {
							if (y <= 8) {
								horizontal = !horizontal;
								draw_grids(debug, name);
								Beep(250, 50);

							}
							else {
								Beep(200, 50);
							}
						}
						else {
							Beep(200, 50);
						}
					}
				}

				if (shiptype == 2) {
					if (horizontal == false) {
						if (x <= 22) {
							if (y <= 10) {
								horizontal = !horizontal;
								draw_grids(debug, name);
								Beep(250, 50);
							}
							else {
								Beep(200, 50);
							}
						}
						else {
							Beep(200, 50);
						}
					}

					else if (horizontal == true) {
						if (x <= 28) {
							if (y <= 8) {
								horizontal = !horizontal;
								draw_grids(debug, name);
								Beep(250, 50);

							}
							else {
								Beep(200, 50);
							}
						}
						else {
							Beep(200, 50);
						}
					}
				}

				if (shiptype == 1) {
					if (horizontal == false) {
						if (x <= 25) {
							if (y <= 10) {
								horizontal = !horizontal;
								draw_grids(debug, name);
								Beep(250, 50);
							}
							else {
								Beep(200, 50);
							}
						}
						else {
							Beep(200, 50);
						}
					}

					else if (horizontal == true) {
						if (x <= 25) {
							if (y <= 9) {
								horizontal = !horizontal;
								draw_grids(debug, name);
								Beep(250, 50);

							}
							else {
								Beep(200, 50);
							}
						}
						else {
							Beep(200, 50);
						}
					}
				}

			}

			if (asciiInput == 13) { //enter

				if (x != 28) {
					//set ships
					if (shiptype == 5) {
						if (horizontal == false) {
							p1_board[ycord][xcord] = " # "; // invert fix
							p1_board[ycord + 1][xcord] = " # ";
							p1_board[ycord + 2][xcord] = " # ";
							p1_board[ycord + 3][xcord] = " # ";
							p1_board[ycord + 4][xcord] = " # ";


						}

						if (horizontal == true) {
							p1_board[ycord][xcord] = " # "; // invert fix
							p1_board[ycord][xcord + 1] = " # ";
							p1_board[ycord][xcord + 2] = " # ";
							p1_board[ycord][xcord + 3] = " # ";
							p1_board[ycord][xcord + 4] = " # ";
						}
					}
					if (shiptype == 4) {
						if (horizontal == false) {
							p1_board[ycord][xcord] = " # "; // invert fix
							p1_board[ycord + 1][xcord] = " # ";
							p1_board[ycord + 2][xcord] = " # ";
							p1_board[ycord + 3][xcord] = " # ";
						}

						if (horizontal == true) {
							p1_board[ycord][xcord] = " # "; // invert fix
							p1_board[ycord][xcord + 1] = " # ";
							p1_board[ycord][xcord + 2] = " # ";
							p1_board[ycord][xcord + 3] = " # ";
						}
					}
					if (shiptype == 3) {
						if (horizontal == false) {
							p1_board[ycord][xcord] = " # "; // invert fix
							p1_board[ycord + 1][xcord] = " # ";
							p1_board[ycord + 2][xcord] = " # ";
						}

						if (horizontal == true) {
							p1_board[ycord][xcord] = " # "; // invert fix
							p1_board[ycord][xcord + 1] = " # ";
							p1_board[ycord][xcord + 2] = " # ";
						}
					}
					if (shiptype == 2) {
						if (horizontal == false) {
							p1_board[ycord][xcord] = " # "; // invert fix
							p1_board[ycord + 1][xcord] = " # ";
							p1_board[ycord + 2][xcord] = " # ";
						}

						if (horizontal == true) {
							p1_board[ycord][xcord] = " # "; // invert fix
							p1_board[ycord][xcord + 1] = " # ";
							p1_board[ycord][xcord + 2] = " # ";
						}
					}
					if (shiptype == 1) {

						bool ibooltmp;
						ibooltmp = checkforships(shiptype, xcord, ycord, horizontal);
						
						if (ibooltmp == true) {
							if (horizontal == false) {
								p1_board[ycord][xcord] = " # "; // invert fix
								p1_board[ycord + 1][xcord] = " # ";
							}

							if (horizontal == true) {
								p1_board[ycord][xcord] = " # "; // invert fix
								p1_board[ycord][xcord + 1] = " # ";
							}

							//boatsplaced = true;
						}
						else {
							Beep(200, 50);
						}
					}
					if (shiptype > 0) {
						shiptype -= 1;
					}
					Beep(1750, 50);
					draw_grids(debug, name);
					GotoXY(1, 1);
				}
				else {
					Beep(200, 50);
				}

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
				cout << "Key: " << keyInput << " Ascii Value= " << asciiInput << endl;
				GotoXY(0, 30);
				cout << "                                                ";
				GotoXY(0, 30);
				cout << "p1_board[" << xcord << ", " << ycord << "] = " << p1_board[ycord][xcord];
				GotoXY(x, y);
			}

			//print ship on screen

			if (shiptype == 5) { //maxs y:6 x:?
				if (horizontal == false) {
					cout << "#";
					for (int i = 0; i < 5; i++) {
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

			if (shiptype == 4) { //maxs y:? x:?
				if (horizontal == false) {
					cout << "#";
					for (int i = 0; i < 4; i++) {
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
				}
				GotoXY(x, y);
			}

			if (shiptype == 3) { //maxs y:? x:?
				if (horizontal == false) {
					cout << "#";
					for (int i = 0; i < 3; i++) {
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
				}
				GotoXY(x, y);
			}


			if (shiptype == 2) { //maxs y:? x:?
				if (horizontal == false) {
					cout << "#";
					for (int i = 0; i < 3; i++) {
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
				}
				GotoXY(x, y);
			}

			if (shiptype == 1) { //maxs y:? x:?
				if (horizontal == false) {
					cout << "#";
					for (int i = 0; i < 2; i++) {
						GotoXY(x, y + i);
						cout << "#";
					}
				}
				if (horizontal == true) {
					cout << "#";
					GotoXY(x + 3, y);
					cout << "#";
				}
				GotoXY(x, y);
			}

		}
	}
	//randomise spots
	if (tmp == "r") {
		srand((unsigned int)time(NULL));
		while (boatsplaced == false) {
			

			int dir = (rand() % 2) + 1;//1 = horizontal 2 = veritcal

			cout << dir;



		}

	}


	if (cancel == true) {
		mainmenu();
		exit(0);
	}



	return 0;
}
