run: bench
	./main

json: bench
	./main --benchmark_out=results.json --benchmark_out_format=json

bench: main.c *.h
	g++ main.c -std=c++11 -isystem benchmark/include \
	-Lbenchmark/build/src -lbenchmark -lpthread -o main

compare:
	~/Programs/google-benchmark/tools/compare.py filters results.json Sort/Merge_sort Sort/Merge_ins_sort
