#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

/*
CHOICE ANIMATIONS

1 - Banner
2 - Explosion

*/

using namespace std;

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
		cout << "         /\\_________________ /             |          " << endl;
		cout << "   <==. +x|_________________|          ___ |          " << endl;
		cout << "         \//                 |          ___ |          " << endl;
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
	return 0;
}