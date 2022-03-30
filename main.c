#include "benchmark/benchmark.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_ins_sort.h"
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

int min_size = 100;
int max_size = 100000;
int mul = 1000;
/* BENCHMARK_CAPTURE(Sort, Insertion_sort, insertion_sort) */
/*     ->RangeMultiplier(mul) */
/*     ->Range(min_size, max_size); */
BENCHMARK_CAPTURE(Sort, Merge_sort, merge_sort)
    ->RangeMultiplier(mul)
    ->Range(min_size, max_size);
BENCHMARK_CAPTURE(Sort, Merge_ins_sort, merge_ins_sort)
    ->RangeMultiplier(mul)
    ->Range(min_size, max_size);
BENCHMARK_CAPTURE(Sort, Quick_sort, quick_sort)
    ->RangeMultiplier(mul)
    ->Range(min_size, max_size);
BENCHMARK_CAPTURE(Sort, Heap_sort, heap_sort)
    ->RangeMultiplier(mul)
    ->Range(min_size, max_size);

BENCHMARK_MAIN();
