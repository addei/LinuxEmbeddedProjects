#include "strman.h"

char readstring(char string[]) {
	if (fgets(string, arrsize, stdin)){
		string[strcspn(string,"\n")] = 0;
	}
	return *string;
}

int checkifalldigit(char string[]) {
	for (int x = 0; x < strlen(string); x++) {
		if (isdigit(string[x]) == 0) {
			return 1;
		}
	}
	return 0;
}

long str2long(char string[]) {
	int x = 0;
	char *endptr;
	x = strtol(string, &endptr, 10);
	return x;
}
