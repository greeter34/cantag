#ifndef GLOBALS
#define GLOBALS
#include <stdbool.h>
#define MAX_DESC 999
#define TTL_OBJS 1
//MAX_DESC will be the maximum length of a string for the long_desc in the locations structures
//TTL_OBJS is the total number of actual objects in the game that the player can interact with

//type definitions for structures go here. global variables go in globals.c

typedef struct objects {
	char name[30];
	int weight;
	struct objects *location;
	bool can_move;
	bool exists;
	bool been_here;
	char short_desc[50];
	char long_desc[MAX_DESC];
	//location pointers
	struct objects *north;
	struct objects *northeast;
	struct objects *east;
	struct objects *southeast;
	struct objects *south;
	struct objects *southwest;	
	struct objects *west;
	struct objects *northwest;
	struct objects *up;
	struct objects *down;
} object;
 
extern object player;
extern object home;
extern object north1;
extern object paint;
extern object objs[TTL_OBJS];
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
void print_objects(object *where);

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
