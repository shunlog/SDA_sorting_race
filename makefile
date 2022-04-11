run: bench
	./main --benchmark_out=results.json --benchmark_out_format=json | tee results.txt

bench: main.c *.h
	g++ main.c -std=c++11 -isystem benchmark/include \
	-Lbenchmark/build/src -lbenchmark -lpthread -o main

compare:
	~/Programs/google-benchmark/tools/compare.py --no-color filters results.json Sort/Merge_sort Sort/Quick_sort | tee comparison.txt
