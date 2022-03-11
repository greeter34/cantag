#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "globals.h"

void display() { //displays the room description prior to reloading the loop() function
    if (player.location-> here == true) {printw("%s\n", player.location->short_desc);}	
    if (player.location->here == false) {	
		printw("%s\n", player.location->long_desc);
		player.location->here = true; 
	}	
	refresh();
	return;
}

void loop() {
	display();
	char cmd[80];
	getnstr(cmd, 80);
	parse(cmd);
	loop();
	return;
}

int main() {
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	scrollok(stdscr, TRUE);
	start_color();
	clear();
	printw("Welcome to the adventure. Please enter your name below. Maximum 10 characters.\n");
	refresh();
	getnstr(player.name, 10);
	if (strlen(player.name) == 0) printw("Name not entered. Naming you Bob.\n");
	printw("Initializing game %s. Please wait...\n", player.name);
	refresh();
	init_game();
	printw("\nGame initialized. Press any key to begin...");
	refresh();
	getch();
	clear();
	loop();
	endwin(); //These will be remaining here in case execusion ever somehow gets back to this point
	return 0;
}
