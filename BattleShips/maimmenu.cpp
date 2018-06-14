#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "animations.h"
#include "battle_init.h"
#include "battle.h"

using namespace std;

int mainmenu() {
	system("COLOR 0F");
	int choice = 1; //banner
	animation(choice);
	int debug;
	string mainchoice;
	string name;

	

	cout << "Main Menu" << endl;
	cout << "1 - Play" << endl;
	cout << "2 - Debug Mode" << endl;
	cout << "3 - Quit" << endl;
	cout << "Select An Option: ";
	cin >> mainchoice;
	while ((mainchoice != "1") && (mainchoice != "2") && (mainchoice != "3")) {
		cout << "Select A Valid Option: ";
		cin >> mainchoice;
	}
	if (mainchoice != "3") {
		cout << "What is your name? ";
		cin >> name;

		if (mainchoice == "2") {
			debug = 1;
		}
		else {
			debug = 0;
		}
		start_init(debug, name);
		mainmenu();
	}

	if (mainchoice == "3") {
		animation(3);
	}
	return 0;
}