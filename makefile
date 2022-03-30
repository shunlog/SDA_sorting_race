run: bench
	./main

bench: main.c *.h
	g++ main.c -std=c++11 -isystem benchmark/include \
	-Lbenchmark/build/src -lbenchmark -lpthread -o main
