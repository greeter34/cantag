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
	else if (new_cmd == "east" || new_cmd == "e" || new_cmd == "go east") {east();}
	else if (new_cmd == "west" || new_cmd == "w" || new_cmd == "go west") {west();}
	else if (new_cmd == "northeast" || new_cmd == "ne" || new_cmd == "go northeast") {northeast();}
	else if (new_cmd == "northwest" || new_cmd == "nw" || new_cmd == "go northwest") {northwest();}
	else if (new_cmd == "southeast" || new_cmd == "se" || new_cmd == "go southeast") {southeast();}
	else if (new_cmd == "southwest" || new_cmd == "sw" || new_cmd == "go southwest") {southwest();}
	else if (new_cmd == "up" || new_cmd == "u" || new_cmd == "go up") {up();}
	else if (new_cmd == "down" || new_cmd == "d" || new_cmd == "go down") {down();} 
	else if (new_cmd == "inventory" || new_cmd == "i") {print_objects(&player);}
	else {
		unknown_cmd();
	} 
	return;
}

