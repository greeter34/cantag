#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "globals.h"

//detailed comments explaining the comments in this file can be found in globals.c

void init_game() {
	//locations

	int i = 0;
	for (i = 0; i < TTL_LOCATIONS; i++) {
		//below, we'll set all location pointers NULL, then only set location pointers as necessary from there
		locations[i].north = NULL;
		locations[i].south = NULL;
		locations[i].east = NULL;
		locations[i].west = NULL;
		locations[i].northeast = NULL;
		locations[i].northwest = NULL;
		locations[i].southeast = NULL;
		locations[i].southwest = NULL;
		locations[i].up = NULL;
		locations[i].down = NULL;
		locations[i].id = i;
		locations[i].been_here = false; //we have not been anywhere in the game when this function is called 
	}
	
	//Living room, starting location for player 
	locations[0].north = &locations[1]; //ground floor hall 
	strcpy(locations[0].name, "Living room");
	strcpy(locations[0].short_desc, "The main living room of the mansion");
	strcpy(locations[0].long_desc, "You are in a large living room, approximately four meters by five meters. Bay windows let in the sunlight from the east. A cast iron fireplace on the west end of the room is visible. You can make out engravings on the very back that depict pioneer life in days gone by. A couple of black chandeliers with light bulbs in the shape of candle flames can provide additional light by night.");
	player.location = &locations[0];
	
	//Ground floor hall 
	locations[1].south = &locations[0]; //living room
	locations[1].east = &locations[2]; //vestibule
	locations[1].west = &locations[3]; //back hall
	locations[1].northwest = &locations[4]; //dining room
	strcpy(locations[1].name, "Ground floor hall"); //this name needs to be better
	strcpy(locations[1].short_desc, "You find yourself in the hallway on the ground floor of the mansion.");
	strcpy(locations[1].long_desc, "You are in a grand hallway with an ornate wooden staircase that can take you elsehwere in the estate. A buffet table rests neatly against the wall and stained glass windows give the sunlight a more muted yet colorful effect in here. One singular bright light, surrounded in a globe like structure of uranium glass casts a greenish tint to everything here.");

	//Front vestibule 
	locations[2].west = &locations[1];
	strcpy(locations[2].name, "Front vestibule"); //ground floor hall
	strcpy(locations[2].short_desc, "The front door vestibule.");
	strcpy(locations[2].long_desc, "You are in the vestibule to the front door. An old gray mat covers the floor. Prismatic shards of glass held beautifully together in their frame shower the area in rainbow colored light. An old name plate on the door bears the name of your grandfather, the man who bought this house many years ago.");	

	//Back hall 
	locations[3].east = &locations[1]; //ground floor hall
	locations[3].west = &locations[6]; //kitchen
	strcpy(locations[3].name, "Back hall");
	strcpy(locations[3].short_desc, "The back hallway of the old mansion");
	strcpy(locations[3].long_desc, "You are in the back hallway of the mansion. A single ceiling light with three bulbs provides illumination. A gray plastic outdoor carpet protects the floor, a start contrast to the original hardwood floors in most of the rest of the house. Various coats hang from several bars in the corner of the room as well.");	

	//Dining room 
	locations[4].southeast = &locations[1]; //ground floor hall
	locations[4].west = &locations[5]; //pantry
	strcpy(locations[4].name, "Dining room");
	strcpy(locations[4].short_desc, "You are in the main dining room");
	strcpy(locations[4].long_desc, "You find yourself in a huge octagonal dining room. Huge windows stretching nearly to the top of the 12 foot ceilings let copious amounts of bright light from the north. An antique dining room set complete with upholstered chairs is on the south end of the room. A singular large black light fixture with three bulbs can provide additional lighting at night. A large beveled mirror hanging above the dining room set makes the room look even larger. There is also a couch along the north wall by the windows.");		

	//Pantry 
	locations[5].east = &locations[4]; //dining room
	locations[5].south = &locations[6]; //kitchen
	strcpy(locations[5].name, "Pantry");
	strcpy(locations[5].short_desc, "A pantry, full of dishware, complete with a sink for cleaning the dishes.");
	strcpy(locations[5].long_desc, "This is the pantry. It is full of various crystal dishware and even has a kitchen sink with separate hot and cold water taps. A false ceiling is here in a brick like pattern. Brown and white tile flooring here reminds you of what this small town is most famous for, cattle.");
	
	// Kitchen
	locations[6].north = &locations[5]; //pantry
	locations[6].east = &locations[3]; //back hall
	strcpy(locations[6].name, "Kitchen");
	strcpy(locations[6].short_desc, "The kitchen, complete with many amenities but oddly devoid of cupboards.");
	strcpy(locations[6].long_desc, "The kitchen of the estate. A few small counters dot the otherwise large kitchen. One huge fluorescent light provides all the lighting this room ever needs. A gas stove sits along the south wall, able to provide a hot meal even without power. This kitchen is oddly devoid of any cupboards.");

	//Side door
	locations[7].north = &locations[3]; //back hall
	strcpy(locations[7].name, "Side door");
	strcpy(locations[7].short_desc, "You arrive at the side door, and are standing on an ornate iron grate.");
	strcpy(locations[7].long_desc, "You're at the side door of the house. An iron grate with an intricate pattern is below your feet. You can see the estate next door through the south facing window. It isn't nearly as big as the one you're in right now however. The lighting mixed with the purple walls gives an odd sense of dreariness that you don't experience anywhere else in this mansion.");

	//objects that the player can interact with

	// brass key
	strcpy(objs[0].name, "key");	
	objs[0].weight = 10;
	objs[0].location = &locations[1];
	objs[0].id = 1;
	objs[0].hidden = false;
	strcpy(objs[0].short_desc, "A plain brass key");
	strcpy(objs[0].long_desc, "This key looks ancient, like it came when they originally built this house back in 1895.");	

	strcpy(objs[1].name, "coin");
	objs[1].weight = 0;
	objs[1].location = &locations[1];
	objs[1].id = 1; //ids correspond to unique locations, so multiple items can share the same id
	objs[1].hidden = false;	
	strcpy(objs[1].short_desc, "A shiny golden colored coin.");
	strcpy(objs[1].long_desc, "A shiny golden colored coin with Lady Liberty stamped on one side and the year 1867 on it. It is officially valued at $5 but you figure it is worth considerably more today.");

	//initialize location IDs. this is for save/load game functions in files.c

	//sprites
	player.id = USHRT_MAX;
	return;
}

