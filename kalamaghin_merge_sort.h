#ifndef KALAMAGHIN_MERGE_SORT_H_
#define KALAMAGHIN_MERGE_SORT_H_

#include "insertion_sort.h"

#include <stdlib.h>
// Standard Merge Sort: uses a lot of memory, but O(n * log2(n)).

void standart_merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    if (r < 1000) {
        insertion_sort(arr, r);
    } else {
        int *L = (int *)malloc(n1 * sizeof(int));
        int *R = (int *)malloc(n2 * sizeof(int));

        for (i = 0; i < n1; i++) {
            *(L + i) = *(arr + l + i);
        }
        for (j = 0; j < n2; j++) {
            *(R + j) = *(arr + m + 1 + j);
        }

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2) {
            if (*(L + i) <= *(R + j)) {
                *(arr + k) = *(L + i);
                i++;
            } else {
                *(arr + k) = *(R + j);
                j++;
            }

            k++;
        }

        while (i < n1) {
            *(arr + k) = *(L + i);
            i++;
            k++;
        }

        while (j < n2) {
            *(arr + k) = *(R + j);
            j++;
            k++;
        }

        free(L);
        free(R);
    }
}

// The function that provides recursive division of
// arrays and a function that provides recursive division of arrays
// and their sorting after small subarrays have been sorted by insertion.

void kalamaghin_merge(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        kalamaghin_merge(arr, l, m);
        kalamaghin_merge(arr, m + 1, r);

        standart_merge(arr, l, m, r);
    }
}

void kalamaghin_merge_sort(int *arr, int n) {
    kalamaghin_merge(arr, 0, n - 1);
}

#endif // KALAMAGHIN_MERGE_SORT_H_
