#ifndef RAND_ARR_H_
#define RAND_ARR_H_

#include <stdlib.h>
#include <time.h>

void init_rand_arr(int *arr, int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % 100;
    }
}

#endif // RAND_ARR_H_
