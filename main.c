#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "globals.h"

void display() { //displays the room description prior to reloading the loop() function. this will be edited later to format output to prevent lines from being broken up mid-word
	/* i'll be the first to admit that this function looks strange. i plan to have the lengths of the tokens added up and compared against rows *
	 * then output them so that words don't get split across separate lines, a common problem i've experienced before, particularly where users *
	 * get to pick their own names. currently only the string tokening exists. this code will be updated later                                  */ 
	int rows = 0, cols = 0;
	char *token;
	getmaxyx(stdscr, rows, cols);
	if (player.location-> here == true) {
		token = strtok(player.location->short_desc, " ");
		while (token != NULL) {
			printw("%s ", token);
			token = strtok(NULL, " ");	
		}	
	}	
	if (player.location->here == false) {
		token = strtok(player.location->short_desc, " ");
		while (token != NULL) {
			printw("%s ", token);
			token = strtok(NULL, " ");
		}	
		player.location->here = true; 
	}
	printw("\n");	
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
	init_color(COLOR_BLACK, 0, 0, 0); //sets black to darkest possible value. found on my terminal personally to be needed
	init_pair(1, COLOR_WHITE, COLOR_BLACK); 
	attron(COLOR_PAIR(1));
	bkgd(COLOR_PAIR(1));
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
