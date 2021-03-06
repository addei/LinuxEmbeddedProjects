#ifndef UINPUT_H
#define UINPUT_H

#include <time.h> /* used to create seed for the program */
#include <assert.h>
#include "strman.h"

static long min = 0;
static long max = 10;
#define arrsize 80
 
int setminmaxvalues(); /* set range for the randomizer function */
long getlong(char string[]); /* convert string into long safely*/
int getiterations(); /*  */
int createseed(); /* create seed for the random generation based on system time variable */
int giverandnum(); /* give random number between min max values */
long fillarraywithrandnumbers(long arr[], long iterations); /* modified The Floyd algorithm for unique random number generation */

#endif
