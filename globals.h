#ifndef GLOBALS
#define _GLOBALS

//global variables

static int seen = 1;

// type definitons for structures

typedef struct sprites {
	char name[15];
	int health;
	int money;
	unsigned int attack;
	unsigned int defense;
	//inventory to go here
} sprite;

typedef struct objects {
	char name[30];
	char desc[100]; //description
	char extdesc[255]; //extended description
} object;

typedef struct locations {
	short unsigned int id;
	//possibly add name here
	char desc[100];
	char extdesc[255]; //extended description
	int seen; //0 if unseen, other value otherwise. possibly increment in order of seen rooms
	//inventory to go here
} location;

//function definitions

char all_lower(char *p);

#endif
