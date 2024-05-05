# Makefile

# Define compiler
CC=g++

# Define compile flags
CFLAGS=-c

all: program

program: program.o swap.o
	$(CC) program.o swap.o -o program

program.o: program.cpp
	$(CC) $(CFLAGS) program.cpp -o program.o

swap.o: swap.cpp
	$(CC) $(CFLAGS) swap.cpp -o swap.o

clean:
	rm -rf *.o program
