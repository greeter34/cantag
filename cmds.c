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
		if (!strcmp(noun, objs[i].name) && (objs[i].location == player.location)) {
			printw("You have taken the object and carefully stuffed it in your inventory.\n");
			taken = true;
			objs[i].location = &player;	
			objs[i].hidden = false;
			objs[i].id = player.id;	
			break;
		}
	}
	if (!taken) {printw("There is no item here called %s\n", noun);} 
	refresh();
	return;
}

void use (char *noun) { //let's use something shall we
	bool used = false;
	if (!strcmp(noun, "key") && (objs[0].location == &player)) {
		printw("You spill the key everywhere, using it up.\n");
		objs[0].location = NULL;
		used = true;
	}
	if (!strcmp(noun, "coin") && (objs[1].location == &player)) {
		printw("You spend your coin.\n");
		objs[1].location = NULL;
		used = true;
	}
	if (!used) {
		printw("You don't know how to use %s here, or it is not in inventory\n", noun);
	}
	return;
}		

void drop (char *noun) { //i think we get the gist here
	bool dropped = false;	
	if (!strcmp(noun, "key") && (objs[0].location == &player)) {
		objs[0].location = player.location;
		objs[0].id = player.location->id;	
		dropped = true;	
	}
	if (!strcmp(noun, "coin") && (objs[1].location == &player)) {
		objs[1].location = player.location;
		objs[1].id = player.location->id;	
		dropped = true;
	}
	if (dropped) {printw("You drop your %s\n", noun);}
	else {printw("You don't have a %s to drop\n", noun);} 
	return;
} 

void examine (char *noun) {
	bool examined = false;
	if (!strcmp(noun, "key") && ((objs[0].location == &player) || (objs[0].location == player.location))) {
		printw("%s\n", objs[0].long_desc);
		examined = true;
	}	
	if (!examined) {
		printw("%s isn't here or in your inventory to examine.\n", noun);
	}
	return;
}	

void count (char *noun) {
	bool counted = false;
	if (!strcmp(noun, "coats") && player.location == &locations[3]) {
		printw("There are 69,105 coats hanging here.\n");
		counted = true;
	}
	if (!counted) {
		printw("I don't see any %s here to count.\n", noun);
	}
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

void move_object(int direction) {
	if ((player.location->north != NULL) && (direction == NORTH)) {player.location = player.location->north;}
	else if ((player.location->south != NULL) && (direction == SOUTH)) {player.location = player.location->south;}
	else if ((player.location->east != NULL) && (direction == EAST)) {player.location = player.location->east;}
	else if ((player.location->west != NULL) && (direction == WEST)) {player.location = player.location->west;}
	else if ((player.location->northeast != NULL) && (direction == NORTHEAST)) {player.location = player.location->northeast;}
	else if ((player.location->northwest != NULL) && (direction == NORTHWEST)) {player.location = player.location->northwest;}
	else if ((player.location->southeast != NULL) && (direction == SOUTHEAST)) {player.location = player.location->southeast;}
	else if ((player.location->southwest != NULL) && (direction == SOUTHWEST)) {player.location = player.location->southwest;}
	else if ((player.location->up != NULL) && (direction == UP)) {player.location = player.location->up;}
	else if ((player.location->down != NULL) && (direction == DOWN)) {player.location = player.location->down;}	
	else {no_exit();}
	return;
}

