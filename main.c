#include "benchmark/benchmark.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "kalamaghin_merge_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "rand_arr.h"
#include <cstring>

template <class... Args> void Sort(benchmark::State &state, Args &&... args) {
    auto args_tuple = std::make_tuple(std::move(args)...);
    int arr_size = state.range(0);
    int *arr = (int *)malloc(arr_size * sizeof(int));
    init_rand_arr(arr, arr_size);
    for (auto _ : state) {
        std::get<0>(args_tuple)(arr, arr_size);
    }
}

int max_size = 1000;
BENCHMARK_CAPTURE(Sort, Insertion_sort, insertion_sort)
    ->RangeMultiplier(10)
    ->Range(10, max_size);
BENCHMARK_CAPTURE(Sort, Merge_sort, merge_sort)
    ->RangeMultiplier(10)
    ->Range(10, max_size);
BENCHMARK_CAPTURE(Sort, Kalamaghin_Merge_sort, kalamaghin_merge_sort)
    ->RangeMultiplier(10)
    ->Range(10, max_size);
BENCHMARK_CAPTURE(Sort, Quick_sort, quick_sort)
    ->RangeMultiplier(10)
    ->Range(10, max_size);
BENCHMARK_CAPTURE(Sort, Heap_sort, heap_sort)
    ->RangeMultiplier(10)
    ->Range(10, max_size);

BENCHMARK_MAIN();
