
#include "merge_sort.h"
#include "quick_sort.h"
#include "rand_arr.h"
#include <stdio.h>

using namespace std;

int main() {
    int arr_size = 5;
    int *arr = (int *)malloc(arr_size * sizeof(int));
    init_rand_arr(arr, arr_size);
    for (int i = 0; i < arr_size; i++) {
        printf("%d\n", arr[i]);
    }

    merge_ins_sort(arr, arr_size);
    puts("Sorted:");

    for (int i = 0; i < arr_size; i++) {
        printf("%d\n", arr[i]);
    }
}
