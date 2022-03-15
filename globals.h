#ifndef GLOBALS
#define GLOBALS
#include <stdbool.h>
#define MAX_DESC 999
//MAX_DESC will be the maximum length of a string for the long_desc in the locations structures

//type definitions for structures

typedef struct objects {
	char name[30];
	int weight;
	signed short int curx;
	signed short int cury;
	struct locations *location;	
} object;

typedef struct locations {
	struct locations *north;
	struct locations *northeast;
	struct locations *east;
	struct locations *southeast;
	struct locations *south;
	struct locations *southwest;
	struct locations *west;
	struct locations *northwest;
	struct locations *up;
	struct locations *down;
	char name[30];
	char long_desc[MAX_DESC];
	char short_desc[50];	
	bool here; //if we've been here set this to true, then use short_desc instead of long_desc
} place;

typedef struct sprites {
	char name[10];
	place *location;
	//inventory to go here
} sprite;

// global variables declared in globals.c

extern sprite player;
extern place home;
extern place north1;
extern object paint;

//function definitions

//parser.cpp 
void parse(char *cmd);

//main.c
void unknown_cmd();
void help();
int main();
void display();
void quit(int reason);
void init_game();
void loop();
void display();

//cmds.c
void unknown_cmd();
void help();
void quit();
void north();
void south();
void east();
void west();
void northeast();
void northwest();
void southeast();
void southwest();
void up();
void down();

//init.c
void init_game();
#endif
