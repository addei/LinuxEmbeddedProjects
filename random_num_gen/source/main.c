/* main.c */
/* 0 copyright/licensing */

/* 1 includes */
#include <stdio.h>
#include <stdlib.h>

#include "uinput.h"

/* 2 defines */
/* 3 external declarations */
/* 4 typedefs */
/* 5 global variable declarations */


/* 6 function prototypes */

int main(int argc, char *argv[]) {
/* 7 command-line parsing */
    
    createseed();
    
    while(1) {
	    
	    setminmaxvalues();
        long x = getlong("iterations?\n> ");

		if (x == 1) {
			printf("Random value: %d\n\n", giverandnum());
		}

		else {
			long arr[x];

			if (fillarraywithrandnumbers(arr, x) == 0) {
				printf("List of random values:\n");
				for (int i = 0; i < x; i++) {
					printf("%d\n", arr[i]);
				}
			}
			else {
				printf("Try again please!\n");
			}
		}
	}
}

/* 8 function declarations */
