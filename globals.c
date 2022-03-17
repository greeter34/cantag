#include "globals.h"

/* Below are structures representing sprites, locations and  *
 * objects. Sprites will be individually commented with what *
 * they represent. Places will be individually commented     *
 * their location in the game relative to the home position  *
 * which is 0,0,0. Coordinates will be given in x, z, y      *
 * order, where x is north/south, z is altitude, and y is    *
 * east/west. Structures denoting objects will be commented  *
 * with which object they represent and where their starting *
 * location is within the game.                              */

object player; //struture representing our hero
object home; //starting location for the player
object north1; // 1,0,0 
object paint;
object objs[TTL_OBJS];
