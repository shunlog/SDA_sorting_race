#ifndef KALAMAGHIN_MERGE_SORT_H_
#define KALAMAGHIN_MERGE_SORT_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// If the dimension of "subarray" is less than a few thousands of elements, it
// is better to use insertion sort practice shows that this speeds up the
// sorting process by 10-20%.
void insertion(int *arr, int n, int s) {
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

// "In-place" variation: uses much less memory because we in fact do not have
// subarrays, BUT it is much slower - O(n^2 * log2(n)).
void in_place_merge(int *arr, int s1, int m, int e) {
    int s2 = m + 1;
    if (e - s1 < 10000) {
        insertion(arr, e - s1 + 1, s1);
    } else {
        while (s1 <= m && s2 <= e) {
            if (*(arr + s1) <= *(arr + s2)) {
                s1++;
            } else {
                int value = *(arr + s2);
                int index = s2;
                while (index != s1) {
                    *(arr + index) = *(arr + index - 1);
                    index--;
                }
                *(arr + s1) = value;
                s1++;
                m++;
                s2++;
            }
        }
    }
}

// Standard Merge Sort: uses a lot of memory, but O(n * log2(n)).
void standart_merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    if (r < 100) {
        insertion(arr, r, 0);
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

// The function a function that provides recursive division of
// arrays and a function that provides recursive division of arrays
// and their sorting after small subarrays have been sorted by insertion.
void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        standart_merge(arr, l, m, r);
    }
}

void kalamaghin_merge_sort(int *arr, int n) {
    mergeSort(arr, 0, n);
}

#endif // KALAMAGHIN_MERGE_SORT_H_
