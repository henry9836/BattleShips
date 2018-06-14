#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "battle.h"

/*
CHOICE ANIMATIONS

1 - Banner
2 - Cancelled
3 - Quiting
4 - Win
5 - Gameover

*/

using namespace std;

void GotoXY(int _iX, int _iY) {
	COORD point;
	point.X = _iX;
	point.Y = _iY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

int animation(int choice) {
	if (choice == 1) {
		system("cls");
		cout << "                              _____________           " << endl;
		cout << "           _________________ /             |          " << endl;
		cout << "           |________________|          ___ |          " << endl;
		cout << "                            |          ___ |          " << endl;
		cout << "                            |          ___ |          " << endl;
		cout << "____________________________|______________|__________" << endl;
		Beep(100, 250);
		system("cls");

		system("cls");
		cout << "                              _____________           " << endl;
		cout << "          *_________________ /             |          " << endl;
		cout << "        <==|________________|          ___ |          " << endl;
		cout << "          *                 |          ___ |          " << endl;
		cout << "                            |          ___ |          " << endl;
		cout << "____________________________|______________|__________" << endl;
		Beep(100, 250);
		system("cls");

		system("cls");
		cout << "                              _____________           " << endl;
		cout << "         /\\_________________//             |          " << endl;
		cout << "   <==. +x|_________________|          ___ |          " << endl;
		cout << "         \\/                 |          ___ |          " << endl;
		cout << "                            |          ___ |          " << endl;
		cout << "____________________________|______________|__________" << endl;
		Beep(100, 250);
		system("cls");

		cout << "          *                   _____________           " << endl;
		cout << "         ox_________________ /             |          " << endl;
		cout << " <==., +x8|_________________|          ___ |          " << endl;
		cout << "         ox                 |          ___ |          " << endl;
		cout << "          *                 |          ___ |          " << endl;
		cout << "____________________________|______________|__________" << endl;

		cout << " _           _   _   _           _     _           " << endl;
		cout << "| |         | | | | | |         | |   (_)          " << endl;
		cout << "| |__   __ _| |_| |_| | ___  ___| |__  _ _ __  ___  " << endl;
		cout << "| '_ \\ / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\/ __| " << endl;
		cout << "| |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) \\__ \\ " << endl;
		cout << "|_.__/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/|___/ " << endl;
		cout << "                                        | |        " << endl;
		cout << "                                        |_|        " << endl;
		Beep(250, 500);
	}

	if (choice == 2) {
		system("COLOR 40");
		system("cls");
		GotoXY(20, 11);
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		GotoXY(20, 12);
		cout << char(186) << "        GAME CANCELLED       " << char(186) << endl;
		GotoXY(20, 13);
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
		GotoXY(0,0);
		Beep(1200, 500);
		Sleep(3000);
		system("COLOR 0F");
	}

	if (choice == 3) {
		system("COLOR 40");
		system("cls");
		GotoXY(20, 11);
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		GotoXY(20, 12);
		cout << char(186) << "        GAME QUITING         " << char(186) << endl;
		GotoXY(20, 13);
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
		GotoXY(0, 0);
		Beep(1200, 500);
		Sleep(1000);
		system("COLOR 0F");
	}

	if (choice == 4) {
		system("1B");
		cout << "(-_)           (_ - __ / \\__)" << endl;
		cout << "           / \\" << endl;
		cout << "        ///o  \\" << endl;
		cout << "        \\/     \\" << endl;
		cout << "________/______/______________" << endl;
		cout << " - - - - - - - - - - - - - " << endl;
		cout << "  - - - - - - - - - - - -" << endl;
		cout << "   - - - - - - - - - - -" << endl;
		cout << " " << endl;
		Beep(900, 500);
		system("cls");
		cout << "(-_)           (_ - __ / \\__)" << endl;
		cout << "           / \\" << endl;
		cout << "        ///o  \\" << endl;
		cout << "        \\/     \\" << endl;
		cout << "________/______/______________" << endl;
		cout << "- - - - - - - - - - - - - " << endl;
		cout << "   - - - - - - - - - - - -" << endl;
		cout << "  - - - - - - - - - - -" << endl;
		cout << " " << endl;
		Beep(1000, 500);
		system("cls");
		cout << "(-_)           (_ - __ / \\__)" << endl;
		cout << "           / \\" << endl;
		cout << "        ///o  \\" << endl;
		cout << "        \\/     \\" << endl;
		cout << "________/______/______________" << endl;
		cout << " - - - - - - - - - - - - - " << endl;
		cout << "  - - - - - - - - - - - -" << endl;
		cout << "   - - - - - - - - - - -" << endl;
		cout << " " << endl;
		Beep(1100, 500);
		system("cls");
		cout << "(-_)           (_ - __ / \\__)" << endl;
		cout << "           / \\" << endl;
		cout << "        ///o  \\" << endl;
		cout << "        \\/     \\" << endl;
		cout << "________/______/______________" << endl;
		cout << "  - - - - - - - - - - - - - " << endl;
		cout << " - - - - - - - - - - - -" << endl;
		cout << "    - - - - - - - - - - -" << endl;
		cout << " " << endl;
		Beep(1200, 500);
		system("cls");
		cout << "(-_)           (_ - __ / \\__)" << endl;
		cout << "           / \\" << endl;
		cout << "        ///o  \\" << endl;
		cout << "        \\/     \\" << endl;
		cout << "________/______/______________" << endl;
		cout << " - - - - - - - - - - - - - " << endl;
		cout << "  - - - - - - - - - - - -" << endl;
		cout << "   - - - - - - - - - - -" << endl;
		cout << " " << endl;
		cout << "      -= You Win = - " << endl;
		system("pause");
		system("07");
	}

	if (choice == 5) {
		system("04");
		cout << "(-_)           (_ - __ / \\__)" << endl;
		cout << "           / \\" << endl;
		cout << "        ///o  \\" << endl;
		cout << "        \\/     \\" << endl;
		cout << "________/______/______________" << endl;
		cout << " - - - - - - - - - - - - - " << endl;
		cout << "  - - - - - - - - - - - -" << endl;
		cout << "   - - - - - - - - - - -" << endl;
		cout << " " << endl;
		Beep(1200, 500);
		system("cls");
		cout << "(-_)           (_ - __ / \\__)" << endl;
		cout << "           / \\" << endl;
		cout << "        ///o  \\" << endl;
		cout << "        \\/     \\" << endl;
		cout << "________/______/______________" << endl;
		cout << "- - - - - - - - - - - - - " << endl;
		cout << "   - - - - - - - - - - - -" << endl;
		cout << "  - - - - - - - - - - -" << endl;
		cout << " " << endl;
		Beep(1100, 500);
		system("cls");
		cout << "(-_)           (_ - __ / \\__)" << endl;
		cout << "           / \\" << endl;
		cout << "        ///o  \\" << endl;
		cout << "        \\/     \\" << endl;
		cout << "________/______/______________" << endl;
		cout << " - - - - - - - - - - - - - " << endl;
		cout << "  - - - - - - - - - - - -" << endl;
		cout << "   - - - - - - - - - - -" << endl;
		cout << " " << endl;
		Beep(1000, 500);
		system("cls");
		cout << "(-_)           (_ - __ / \\__)" << endl;
		cout << "           / \\" << endl;
		cout << "        ///o  \\" << endl;
		cout << "        \\/     \\" << endl;
		cout << "________/______/______________" << endl;
		cout << "  - - - - - - - - - - - - - " << endl;
		cout << " - - - - - - - - - - - -" << endl;
		cout << "    - - - - - - - - - - -" << endl;
		cout << " " << endl;
		Beep(900, 500);
		system("cls");
		cout << "(-_)           (_ - __ / \\__)" << endl;
		cout << "           / \\" << endl;
		cout << "        ///o  \\" << endl;
		cout << "        \\/     \\" << endl;
		cout << "________/______/______________" << endl;
		cout << " - - - - - - - - - - - - - " << endl;
		cout << "  - - - - - - - - - - - -" << endl;
		cout << "   - - - - - - - - - - -" << endl;
		cout << " " << endl;
		cout << "      -= You Lose = - " << endl;
		system("pause");
		system("07");
	}

	return 0;
}