# FAF 211's implementation of the 3 sorting algorithms

Each algorithm resides in its own header file. For benchmarking, we used [this library](https://github.com/google/benchmark) made by Google (reputable).

Example of a benchmark of all three algorithms:
```
--------------------------------------------------------------------------------
Benchmark                                      Time             CPU   Iterations
--------------------------------------------------------------------------------
Sort/Merge_sort/100000/min_time:1.000    7087368 ns      7087492 ns          190
Sort/Quick_sort/100000/min_time:1.000    3613398 ns      3613509 ns          379
Sort/Heap_sort/100000/min_time:1.000    15039755 ns     15040176 ns           90
```

Example of comparing two algorithms:
```
Comparing Sort/Merge_sort to Sort/Quick_sort (from results.json)
Benchmark                                                                     Time             CPU      Time Old      Time New       CPU Old       CPU New
----------------------------------------------------------------------------------------------------------------------------------------------------------
[Sort/Merge_sort vs. Sort/Quick_sort]/100000/min_time:1.000                -0.4902         -0.4902       7087368       3613398       7087492       3613509
OVERALL_GEOMEAN                                                            -0.4902         -0.4902             0             0             0             0
```
