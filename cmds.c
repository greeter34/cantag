#include <curses.h>
#include <string.h>
#include "globals.h"

void help() { //print out help. this will be made context specific
	printw("This is the help function.\n");
	refresh();
	return;
}

void take(char *noun) { //let's take something shall we
	int i = 0; //our iterator
	bool taken = false; //flag for if an object has been taken yet or not 
	for (i = 0; i != TTL_OBJS; i++) { //set up a loop to check each object against the input provided by the user
		if (!strcmp(noun, objs[i].name)) {
			printw("You have taken the object and carefully stuffed it in your inventory.\n");
			taken = true;
			objs[i].location = &player;	
			break;
		}
	}
	if (!taken) {printw("There is no item here called %s\n", noun);} 
	refresh();
	return;
}

void unknown_cmd() { //unknown command was entered
	printw("Unknown command entered. For help use help.\n");
	refresh();
	return;
}

void quit (int reason) { //user typed quit
	running = false;
	if (reason == 0) { //user initiated quit through quit command. should prompt for save/confirmation of quit 
		printw("Thank you for playing. Press any key to quit now.\n");
		refresh();	
		getch();
	}
	endwin();
    return;
}

void no_exit() { //user picks a direction invalid for the current location
	printw("You cannot go that way from here.\n");
	return;
}

//directional commands
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

void east() { //user typed east or some variation
	if (player.location->east == NULL) {no_exit();}
	else player.location = player.location->east;
	return;
}

void west() { //user typed west or some variation
	if (player.location->west == NULL) {no_exit();}
	else player.location = player.location->west;
	return;
}

void northeast() { //user typed northeast or some variation
	if (player.location->northeast == NULL) {no_exit();}
	else player.location = player.location->northeast;
	return;
}

void northwest() { //user typed northwest or some variation
	if (player.location->northwest == NULL) {no_exit();}
	else player.location = player.location->northwest;
	return;
}

void southeast() { //user typed southeast or some variation
	if (player.location->southeast == NULL) {no_exit();}
	else player.location = player.location->southeast;
	return;
}

void southwest() { //user typed southwest or some variation
	if (player.location->southwest == NULL) {no_exit();}
	else player.location = player.location->southwest;
	return;
}

void up() { //user typed up or some variation
	if (player.location->up == NULL) {no_exit();}
	else player.location = player.location->up;
	return;
}

void down() { //user typed down or some variation
	if (player.location->down == NULL) {no_exit();}
	else player.location = player.location->up;
	return;
}
	

