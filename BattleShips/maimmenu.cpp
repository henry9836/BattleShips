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
	int choice = 1; //TF: Variable Type
	animation(choice);
	int debug;
	string mainchoice;
	string name;

	string* choiceptr = &mainchoice; // TF: Pointer Dereferenced TF: Pointer Initialised

	

	cout << "Main Menu" << endl;
	cout << "1 - Play" << endl;
	cout << "2 - Debug Mode" << endl;
	cout << "3 - Quit" << endl;
	cout << "Select An Option: ";
	cin >> mainchoice;

	while ((*choiceptr != "1") && (*choiceptr != "2") && (*choiceptr != "3")) { // TF: Relational Operator
		cout << "Select A Valid Option: ";
		cin >> mainchoice;
	}
	if (*choiceptr != "3") { // TF: Conditional Statement
		cout << "What is your name? ";
		cin >> name;

		if (*choiceptr == "2") {
			debug = 1;
		}
		else {
			debug = 0;
		}
		start_init(debug, name);
		mainmenu();
	}

	if (*choiceptr == "3") {
		animation(3);
	}

	choiceptr = nullptr; // TF: Pointer Initialised

	return 0;
}