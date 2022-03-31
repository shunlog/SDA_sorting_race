#ifndef KALAMAGHIN_HEAP_STANDARD_H_
#define KALAMAGHIN_HEAP_STANDARD_H_

void heapify(int *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l<n &&*(arr + l)> * (arr + largest)) {
        largest = l;
    }

    if (r<n &&*(arr + r)> * (arr + largest)) {
        largest = r;
    }

    if (largest != i) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + largest);
        *(arr + largest) = temp;

        heapify(arr, n, largest);
    }
}

void kalamaghin_heap_sort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    int temp;

    for (int i = n - 1; i > 0; i--) {
        temp = *arr;
        *arr = *(arr + i);
        *(arr + i) = temp;

        heapify(arr, i, 0);
    }
}

#endif // KALAMAGHIN_HEAP_STANDARD_H_
