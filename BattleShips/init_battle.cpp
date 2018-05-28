#include <iostream>
#include <windows.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include "animations.h"

using namespace std;

void GotoXY(int _iX, int _iY) {
	COORD point;
	point.X = _iX;
	point.Y = _iY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

int start_init(int debug, string name){
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



	return 0;
}