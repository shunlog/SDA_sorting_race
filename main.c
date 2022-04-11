#include "benchmark/benchmark.h"
#include "heap_sort.h"
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

int min_size = 1e5;
int max_size = 1e5;
int mul = 10;
int min_time = 1;
/* BENCHMARK_CAPTURE(Sort, Merge_sort, merge_sort) */
/*     ->RangeMultiplier(mul) */
/*     ->Range(min_size, max_size) */
/*     ->MinTime(min_time); */
BENCHMARK_CAPTURE(Sort, Merge_sort, merge_ins_sort)
    ->RangeMultiplier(mul)
    ->Range(min_size, max_size)
    ->MinTime(min_time);
/* BENCHMARK_CAPTURE(Sort, Quick_sort, quick_sort) */
/*     ->RangeMultiplier(mul) */
/*     ->Range(min_size, max_size) */
/*     ->MinTime(min_time); */
BENCHMARK_CAPTURE(Sort, Quick_sort, quick_ins_sort)
    ->RangeMultiplier(mul)
    ->Range(min_size, max_size)
    ->MinTime(min_time);
BENCHMARK_CAPTURE(Sort, Heap_sort, heap_sort)
    ->RangeMultiplier(mul)
    ->Range(min_size, max_size)
    ->MinTime(min_time);

BENCHMARK_MAIN();
