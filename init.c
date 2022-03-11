#include <string.h>
#include "globals.h"

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
	strcpy(home.name, "Home");
	strcpy(home.short_desc, "Your home in the game");
	strcpy(home.long_desc, "You find yourself in a large cube closed on most sides.\n\nThere is one exit to the north.\n"); 
	player.location = &home;
	
	//north of starting location
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
	strcpy(north1.name, "North1"); //this name needs to be better
	strcpy(north1.long_desc, "You find yourself in a large cube closed on most sides.\n\nThere is one exit to the south.\n");
	return;
}

