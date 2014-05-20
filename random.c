#include <stdlib.h>
#include <time.h>
#include "random.h"

void init_rand() {
    srand(time(NULL));
}

int rand_lim(int limit) {
    int divisor = RAND_MAX/(limit+1);
    int result;

    do { 
        result = rand() / divisor;
    } while (result > limit);

    return result;
}
