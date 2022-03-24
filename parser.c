#include <string.h>
#include <ctype.h>
#include <curses.h>
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
/*	else if (!strcmp(cmd, "exits")) {
		valid = true;
		print_exits();
	} currently print_exits() is called every time from the loop. this command is here in case that changes later */ 
	else if (!strcmp(cmd, "save")) {
		valid = true;
		save("vfile");
	}
	else if (!strcmp(cmd, "load")) {
		valid = true;
		load("vfile");
	}
	
	//two word commands go here

	char *noun = strtok(cmd, " ");	
	if (!strcmp(cmd, "take")) {
		noun = strtok(NULL, " ");	
		if (noun) {take(noun);}
		else {printw("Nothing was specified to be taken.\n");}	
		valid = true;
	}
	if (!strcmp(cmd, "use")) {
		noun = strtok(NULL, " ");
		if (noun) {use(noun);}
		else {printw("Nothing was specified to use.\n");}	
		valid = true;
	}
	if (!strcmp(cmd, "drop")) {
		noun = strtok(NULL, " ");
		if (noun) {drop(noun);}
		else {printw("Nothing was specified to drop.\n");}	
		valid = true;
	}
	if (!strcmp(cmd, "count")) {
		noun = strtok(NULL, " ");
		if (noun) {count(noun);}
		else {printw("Nothing was specified to count.\n");}		
		valid = true;
	}
	
	//commands that could be one or two words
	if (!strcmp(cmd, "examine")) {
		noun = strtok(NULL, " ");
		if (!noun) {
			valid = true;
			display(player.location->long_desc);
		}
		else {
			valid = true;	
			examine(noun);
		}
	}

	if (!valid) {
		unknown_cmd();
	} 
	return;
}

