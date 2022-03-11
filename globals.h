#ifndef GLOBALS
#define GLOBALS
#include <stdbool.h>

//type definitions for structures

typedef struct objects {
	char name[30];
	int weight;
	signed short int curx;
	signed short int cury;
	int location; //to be used with ID to determine where to stick items. -1 is player inventory
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
	char long_desc[255];
	char short_desc[50];	
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

//cmds.c
void unknown_cmd();
void help();
void quit();
void north();
void south();

//init.c
void init_game();
#endif
