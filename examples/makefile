CC = clang++ -std=c++11

t2: KTable.o ktable_test2.cpp
	$(CC) -o t2 ktable_test2.cpp KTable.o -lIEGA
	./t2

calc: KTable.o MC33063A_calculator.cpp
	$(CC) -o calc MC33063A_calculator.cpp KTable.o -lIEGA
	./calc

all: KTable.o ktable_test.cpp
	$(CC) -o ktable_test ktable_test.cpp KTable.o -lIEGA

KTable.o: KTable.cpp
	$(CC) -c KTable.cpp
