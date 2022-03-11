#include <stdlib.h>
#include <curses.h>
#include "globals.h"

void help() { //print out help. this will be made context specific
	printw("This is the help function.\n");
	refresh();
	return;
}

void unknown_cmd() { //unknown command was entered
	printw("Unknown command entered. For help use help.\n");
	refresh();
	return;
}

void quit (int reason) { //user typed quit
	if (reason == 0) { //user initiated quit through quit command. should prompt for save/confirmation of quit 
		printw("Thank you for playing. Press any key to quit now.\n");
		refresh();	
		getch();
	}
	endwin();
	exit(0);
}

void no_exit() { //user picks a direction invalid for the current location
	printw("You cannot go that way from here.\n");
	return;
}

void north() { //user typed north or some variation
	if (player.location->north == NULL) {no_exit();} //have another function for this
	else player.location = player.location->north;
	return;
}

void south() { //user typed south or some variation
	if (player.location->south == NULL) {no_exit();}
	else player.location = player.location->south;
	return;
}
