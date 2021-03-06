#ifndef STRMAN_H
#define STRMAN_H

/* strman = string + string manipulation */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define arrsize 80 /* size of the string buffer */

char readstring(char string[]); /* reads user input (string) and returns pointer to it */
int checkifalldigit(char string[]); /* returns 1 if string elemets are all digit */
long str2long(char string[]); /* takes carray and converts char digits to interger in a safe manner */

#endif
