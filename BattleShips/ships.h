#pragma once
#include <string>
#define SHIPS

class aircraft_carrier {
	public:
		char ship[6] = "#####";
};

class battleship {
	char ship[5] = "####";
};

class destroyer {
	char ship[4] = "###";
};

class sub{
	char ship[4] = "###";
};

class patrol_boat {
	char ship[3] = "##";
};
