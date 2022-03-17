#include <string.h>
#include <ctype.h>
#include "globals.h"

char *stl(char *string) { //lower case an entire string
	for (char *s = string; *s; s++) {
		*s = tolower(*s);
	}
	return string;
}	

void parse(char *cmd) {
	if (!strcmp(cmd, "help")) {help();}
	else if (!strcmp(cmd, "quit")) {quit(0);}
	else if ((!strcmp(cmd, "north") || (!strcmp(cmd, "n")) || (!strcmp(cmd, "go north")))) {north();}
	else if ((!strcmp(cmd, "south") || (!strcmp(cmd, "s")) || (!strcmp(cmd, "go south")))) {south();}
	else if ((!strcmp(cmd, "northeast") || (!strcmp(cmd, "ne")) || (!strcmp(cmd, "go northeast")))) {northeast();}
	else if ((!strcmp(cmd, "northwest") || (!strcmp(cmd, "nw")) || (!strcmp(cmd, "go northwest")))) {northwest();}
	else if ((!strcmp(cmd, "southeast") || (!strcmp(cmd, "se")) || (!strcmp(cmd, "go southeast")))) {southeast();}
	else if ((!strcmp(cmd, "southwest") || (!strcmp(cmd, "sw")) || (!strcmp(cmd, "go southwest")))) {southwest();}
	else if ((!strcmp(cmd, "east") || (!strcmp(cmd, "e")) || (!strcmp(cmd, "go east")))) {east();}
	else if ((!strcmp(cmd, "west") || (!strcmp(cmd, "w")) || (!strcmp(cmd, "go west")))) {west();}
	else if ((!strcmp(cmd, "up") || (!strcmp(cmd, "u")) || (!strcmp(cmd, "go up")))) {up();}
	else if ((!strcmp(cmd, "down") || (!strcmp(cmd, "d")) || (!strcmp(cmd, "go down")))) {down();}
	else if ((!strcmp(cmd, "inventory") || (!strcmp(cmd, "i")))) {print_objects(&player);}
	else {
		unknown_cmd();
	} 
	return;
}

