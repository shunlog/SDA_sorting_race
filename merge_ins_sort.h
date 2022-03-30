#ifndef MERGE_INS_SORT_H_
#define MERGE_INS_SORT_H_

#include <stdio.h>
#include <stdlib.h>

void insertion2(int *arr, int n, int s) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = *(arr + s + i);
        j = i - 1;
        while (j >= 0 && *(arr + s + j) > key) {
            *(arr + s + j + 1) = *(arr + s + j);
            j = j - 1;
        }
        *(arr + s + j + 1) = key;
    }
}

void merge_ins(int *a, int n, int m) {
    int i, j, k;
    if (n < 100) {
        insertion2(a, n, 0);
        return;
    }
    int *x = (int *)malloc(n * sizeof(int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] =
            j == n ? a[i++] : i == m ? a[j++] : a[j] < a[i] ? a[j++] : a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}

void merge_ins_sort(int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_ins_sort(a, m);
    merge_ins_sort(a + m, n - m);
    merge_ins(a, n, m);
}

#endif // MERGE_INS_SORT_H_
