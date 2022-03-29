#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

void quick_sort(int *A, int len) {
    if (len < 2)
        return;

    int pivot = A[len / 2];

    int i, j;
    for (i = 0, j = len - 1;; i++, j--) {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;

        if (i >= j)
            break;

        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    quick_sort(A, i);
    quick_sort(A + i, len - i);
}

#endif // QUICK_SORT_H_
