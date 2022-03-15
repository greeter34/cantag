#include <string.h>
#include <stdbool.h>
#include "globals.h"

//detailed comments explaining the comments in this file can be found in globals.c

void init_game() {
	//starting location for player
	home.north = &north1; 
	home.south = NULL;
	home.east = NULL;
	home.west = NULL;
	home.northeast = NULL;
	home.northwest = NULL;
	home.southeast = NULL;
	home.southwest = NULL;
	home.up = NULL;
	home.down = NULL;
	home.here = false; 
	strcpy(home.name, "Home");
	strcpy(home.short_desc, "Your home in the game");
	strcpy(home.long_desc, "You find yourself in a large cube closed on most sides. There is one exit to the north. This is a delibnerately long string intended to take up multiple lines of the terminal. This should wrap around to the next line of the terminal. Experiment with the player name to break a word across lines and see what happens.");
	player.location = &home;
	
	// 1,0,0
	north1.north = NULL;
	north1.south = &home;
	north1.east = NULL;
	north1.west = NULL;
	north1.northeast = NULL;
	north1.northwest = NULL;
	north1.southeast = NULL;
	north1.southwest = NULL;
	north1.up = NULL;
	north1.down = NULL;
	north1.here = false; 
	strcpy(north1.name, "North1"); //this name needs to be better
	strcpy(north1.short_desc, "The other end of the rectangular prism");
	strcpy(north1.long_desc, "You find yourself in a large cube closed on most sides. There is one exit to the south.");
	return;
}

