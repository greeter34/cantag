#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //for tolower

char all_lower(char *p) {
	for ( ; *p; ++p) {
		*p = tolower(*p);
		if (*p == '\n') {*p = '\0';}
	}
	return p;
}
