#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "animations.h"
#include "battle_init.h"
#include "battle.h"

using namespace std;

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

bool battle(int debug, string name,string p1_board[10][10], string p1_board2[10][10], string p2_board[10][10], string p2_board2[10][10]){

	int it;



	draw_grids(debug, name, p1_board, p1_board2, p2_board, p2_board2);


	cout << "Done!";
	cin >> it;
	//return true for player win, false for ai win

	return false;
}