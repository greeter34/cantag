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
		dropped = true;	
	}
	if (!strcmp(noun, "coin") && (objs[1].location == &player)) {
		objs[1].location = player.location;
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
	

