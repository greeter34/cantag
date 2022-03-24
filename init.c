#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "globals.h"

//detailed comments explaining the comments in this file can be found in globals.c

void init_game() {
	//locations
	
	//starting location for player
	locations[0].north = &locations[1]; 
	locations[0].south = NULL;
	locations[0].east = NULL;
	locations[0].west = NULL;
	locations[0].northeast = NULL;
	locations[0].northwest = NULL;
	locations[0].southeast = NULL;
	locations[0].southwest = NULL;
	locations[0].up = NULL;
	locations[0].down = NULL;
	strcpy(locations[0].name, "Living room");
	strcpy(locations[0].short_desc, "The main living room of the mansion");
	strcpy(locations[0].long_desc, "You are in a large living room, approximately four meters by five meters. Bay windows let in the sunlight from the east. A cast iron fireplace on the west end of the room is visible. You can make out engravings on the very back that depict pioneer life in days gone by. A couple of black chandeliers with light bulbs in the shape of candle flames can provide additional light by night.");
	player.location = &locations[0];
	
	// 1,0,0
	locations[1].north = NULL;
	locations[1].south = &locations[0];
	locations[1].east = &locations[2];
	locations[1].west = &locations[3];
	locations[1].northeast = NULL;
	locations[1].northwest = &locations[4];
	locations[1].southeast = NULL;
	locations[1].southwest = NULL;
	locations[1].up = NULL;
	locations[1].down = NULL;
	strcpy(locations[1].name, "Ground floor hall"); //this name needs to be better
	strcpy(locations[1].short_desc, "You find yourself in the hallway on the ground floor of the mansion.");
	strcpy(locations[1].long_desc, "You are in a grand hallway with an ornate wooden staircase that can take you elsehwere in the estate. A buffet table rests neatly against the wall and stained glass windows give the sunlight a more muted yet colorful effect in here. One singular bright light, surrounded in a globe like structure of uranium glass casts a greenish tint to everything here.");

	// 1,1,0
	locations[2].north = NULL;
	locations[2].south = NULL;
	locations[2].east = NULL;
	locations[2].west = &locations[1];
	locations[2].northeast = NULL;
	locations[2].northwest = NULL;
	locations[2].southeast = NULL;
	locations[2].southwest = NULL;
	locations[2].up == NULL;
	locations[2].down == NULL;
	strcpy(locations[2].name, "Vestibule");
	strcpy(locations[2].short_desc, "The front door vestibule.");
	strcpy(locations[2].long_desc, "You are in the vestibule to the front door. An old gray mat covers the floor. Prismatic shards of glass held beautifully together in their frame shower the area in rainbow colored light. An old name plate on the door bears the name of your grandfather, the man who bought this house many years ago.");	

	// 1,-1,0
	locations[3].north = NULL;
	locations[3].south = NULL;
	locations[3].east = &locations[1];
	locations[3].west = NULL;
	locations[3].northeast = NULL;
	locations[3].northwest = NULL;
	locations[3].southeast = NULL;
	locations[3].southwest = NULL;
	locations[3].up = NULL;
	locations[3].down = NULL;
	strcpy(locations[3].name, "Back hall");
	strcpy(locations[3].short_desc, "The back hallway of the old mansion");
	strcpy(locations[3].long_desc, "You are in the back hallway of the mansion. A single ceiling light with three bulbs provides illumination. A gray plastic outdoor carpet protects the floor, a start contrast to the original hardwood floors in most of the rest of the house. Various coats hang from several bars in the corner of the room as well.");	

	// 2,-1,0
	locations[4].north = NULL;
	locations[4].south = NULL;
	locations[4].east = NULL;
	locations[4].west = NULL;
	locations[4].northeast = NULL;
	locations[4].northwest = NULL;
	locations[4].southeast = &locations[1];
	locations[4].southwest = NULL;
	strcpy(locations[4].name, "Dining room");
	strcpy(locations[4].short_desc, "You are in the main dining room");
	strcpy(locations[4].long_desc, "You find yourself in a huge octagonal dining room. Huge windows stretching nearly to the top of the 12 foot ceilings let copious amounts of bright light from the north. An antique dining room set complete with upholstered chairs is on the south end of the room. A singular large black light fixture with three bulbs can provide additional lighting at night. A large beveled mirror hanging above the dining room set makes the room look even larger. There is also a couch along the north wall by the windows.");		

	//objects that the player can interact with

	// brass key
	strcpy(objs[0].name, "key");	
	objs[0].weight = 10;
	objs[0].location = &locations[1];
	objs[0].id = 1;
	objs[0].can_move = true;
	objs[0].hidden = false;
	strcpy(objs[0].short_desc, "A plain brass key");
	strcpy(objs[0].long_desc, "This key looks ancient, like it came when they originally built this house back in 1895.");	

	strcpy(objs[1].name, "coin");
	objs[1].weight = 0;
	objs[1].location = &locations[1];
	objs[1].id = 1; //ids correspond to unique locations, so multiple items can share the same id
	objs[1].can_move = true;
	objs[1].hidden = false;	
	strcpy(objs[1].short_desc, "A shiny golden colored coin.");
	strcpy(objs[1].long_desc, "A shiny golden colored coin with Lady Liberty stamped on one side and the year 1867 on it. It is officially valued at $5 but you figure it is worth considerably more today.");

	//initialize location IDs. this is for save/load game functions in files.c

	int i = 0;
	for (i = 0; i < TTL_LOCATIONS; i++) {
		locations[i].id = i;
		locations[i].been_here = false; //we have not been anywhere in the game when this function is called		
	}	

	//sprites
	player.id = USHRT_MAX;
	return;
}

