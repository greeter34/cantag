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
	/* Let's start with our basic one word commands. if a one word command is defined,
	   it will be defined in this part of the function. two word commands come later */
	bool valid = false; //is our command valid? assume not unless otherwise specified below
	if (!strcmp(cmd, "help")) {
		valid = true;	
		help();
	}
	else if (!strcmp(cmd, "quit")) {
		valid = true;	
		quit(0);
	}
	else if ((!strcmp(cmd, "north") || (!strcmp(cmd, "n")) || (!strcmp(cmd, "go north")))) {
		valid = true;	
		north();
	}
	else if ((!strcmp(cmd, "south") || (!strcmp(cmd, "s")) || (!strcmp(cmd, "go south")))) {
		valid = true;	
		south();
	}
	else if ((!strcmp(cmd, "northeast") || (!strcmp(cmd, "ne")) || (!strcmp(cmd, "go northeast")))) {
		valid = true;	
		northeast();
	}
	else if ((!strcmp(cmd, "northwest") || (!strcmp(cmd, "nw")) || (!strcmp(cmd, "go northwest")))) {
		valid = true;	
		northwest();
	}
	else if ((!strcmp(cmd, "southeast") || (!strcmp(cmd, "se")) || (!strcmp(cmd, "go southeast")))) {
		valid = true;	
		southeast();
	}
	else if ((!strcmp(cmd, "southwest") || (!strcmp(cmd, "sw")) || (!strcmp(cmd, "go southwest")))) {
		valid = true;	
		southwest();
	}
	else if ((!strcmp(cmd, "east") || (!strcmp(cmd, "e")) || (!strcmp(cmd, "go east")))) {
		valid = true;	
		east();
	}
	else if ((!strcmp(cmd, "west") || (!strcmp(cmd, "w")) || (!strcmp(cmd, "go west")))) {
		valid = true;	
		west();
	}
	else if ((!strcmp(cmd, "up") || (!strcmp(cmd, "u")) || (!strcmp(cmd, "go up")))) {
		valid = true;	
		up();
	}
	else if ((!strcmp(cmd, "down") || (!strcmp(cmd, "d")) || (!strcmp(cmd, "go down")))) {
		valid = true;	
		down();
	}
	else if ((!strcmp(cmd, "inventory") || (!strcmp(cmd, "i")))) {
		valid = true;	
		print_objects(&player);
	}
	
	//two word commands go here

	char *noun = strtok(cmd, " ");	
	if (!strcmp(cmd, "take")) {
		noun = strtok(NULL, " ");	
		take(noun);
		valid = true;
	}

	if (!valid) {
		unknown_cmd();
	} 
	return;
}

