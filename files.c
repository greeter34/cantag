#include <stdio.h>
#include <string.h>
#include <curses.h>
#include "globals.h"

/* A note about this file. The functions here are NOT complete. Because the saved data
 * contains pointers, the absolute memory addresses get saved to file. Using these
 * functions in the same instance of the same game (ie not closing the program and
 * starting it again later) will work since the same memory addresses will still
 * belong to the program. However if you close the program, then try to load a file
 * after reopening it, a segmentation fault will happen, as the saved memory addresses
 * will not belong to the new instance of the program. I therefore need to rewrite the
 * save and load functions to work with location IDs, parsing restoring the file pointers
 * properly and leaving other variables untouched, such as how locations link to each
 * other, as those pointers should never need to change anyway. Another note is that
 * these binary files are likely not interchangeable between different operating
 * systems, such as between windows and linux. As such, use of these functions and files
 * is at your own risk until they are properly updated to handle the memory pointer
 * issues documented above
 */

char *prompt() {
	static char path[100];	
	printw("Please enter a file name\nNote: Name can be relative or an absolute path\n");
	getnstr(path, 100);
	return path;
}	

void save(char *destination) {
	FILE *savefile = fopen(destination, "wb");
	if (savefile == NULL) {
		printw("File is NULL\n");
	}
	fwrite(&objs, sizeof(objs), 1, savefile);
	fwrite(&player, sizeof(player), 1, savefile);	
	fclose(savefile);
	return;
}

void load(char *destination) { //this function is incomplete
	FILE *loadfile = fopen(destination, "rb");
	if (loadfile == NULL) {
		printw("File is NULL\n");
   	}
	fread(&objs, sizeof(objs), 1, loadfile);
	fread(&player, sizeof(player), 1, loadfile);	
	fclose(loadfile);	
	return;
}
