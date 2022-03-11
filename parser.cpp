#include <iostream>
#include <algorithm>
#include "globals.h"

using namespace std;

void parse(char *cmd) {
	string new_cmd(cmd);
	transform(new_cmd.begin(), new_cmd.end(), new_cmd.begin(), ::tolower);
	if (new_cmd == "help") {help();}
	else if (new_cmd == "quit") {quit(0);}
	else if (new_cmd == "north" || new_cmd == "n" || new_cmd == "go north") {north();}
	else if (new_cmd == "south" || new_cmd == "s" || new_cmd == "go south") {south();}
	else {
		unknown_cmd();
	} 
	return;
}

