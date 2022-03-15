#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "globals.h"

void display() { //displays the room description prior to reloading the loop() function
	int max_x = 0, max_y = 0, length = 0; //get maximum width and screen at time the function is called
	char description[MAX_DESC], *to_print, *token ; //copy the appropriate description, to_print will be written out to the screen while token is for strtok();
	getmaxyx(stdscr, max_y, max_x);	
	to_print = (char *) malloc(sizeof(char) * (max_x + 1)); //dynamically allocate enough memory for to_print to print one line
	strcpy(to_print, "");
	if (player.location->here) {
		strcpy(description, player.location->short_desc);
		}
	else {
		strcpy(description, player.location->long_desc);
		player.location->here = true;
	}	
	getmaxyx(stdscr, max_y, max_x);
	token = strtok(description, " ");
	while (token != NULL) {	
		if (length + (strlen(token) + 1) > max_x) { //if the current length of text plus the next token and one space exceeds the width of the screen, immediately print the line to screen 
			printw("%s\n", to_print);
			length = strlen(token);
			strcpy(to_print, "");
		}	
		strcat(to_print, token);
		strcat(to_print, " ");
		length += (strlen(token) + 1); //we add one to account for the space	
		token = strtok(NULL, " ");
	}
	printw("%s\n", to_print);
	refresh();
	free(to_print);
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
