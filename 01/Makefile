CC=g++
FLAGS=--std=c++17

all: test_all

test_all: main.o Allocator.o
	$(CC) main.o Allocator.o $(FLAGS) -o test_all

Allocator.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

Allocator.o: Allocator.cpp Allocator.h
	$(CC) $(FLAGS) -c Allocator.cpp

clean:
	rm -f *.o test_all

test: test_all
	./test_all