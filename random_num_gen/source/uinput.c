#include "uinput.h"

int setminmaxvalues() {

    min = getlong("min?\n> ");
    while ((max = getlong("max?\n> ")) == min) {
        printf("max(%d) value needs to be more than min(%d).\n");
    }
    return 0;
}

long getlong(char string[]) {
    while(1) {
        char arr[arrsize] = {"\0"};
        printf("%s", string);
        readstring(arr);
        if (checkifalldigit(arr) == 0) {
            return str2long(arr);
        }
        else {
            printf("Not a integer, try again!\n");
        }
    }
}

int createseed() {
    srand(time(NULL));
    return 0;
}

int giverandnum() {
    return min + rand() %max;
}

long fillarraywithrandnumbers(long arr[], long iterations) {

    long N = max - min;
    if (iterations >= N) {
        printf("Given range is too small for iterate %d times\n",iterations);
        return 1;
    }

    else {
        long im = 0;
        unsigned char is_used[N]; /* flags */

        for (long i = 0; i < N; i++) {
            is_used[i] = 0;
        }

        for (long in = N - iterations; in < N && im < iterations; ++in) {
            int r = rand() % (in + 1); /* generate a random number 'r' */

            if (is_used[r]) {
             /* we already have 'r' */
                r = in; /* use 'in' instead of the generated number */
            }

            assert(!is_used[r]);
            arr[im++] = r + 1 + min; /* +1 since your range begins from 1 */
            is_used[r] = 1;

        }

  assert(im == iterations);
  return 0;

    }
}
