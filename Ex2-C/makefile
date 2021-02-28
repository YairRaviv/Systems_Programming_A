CC=gcc
FLAGS= -Wall

all: mains

mains: main.o myBank.o
	$(CC) $(FLAGS) -o mains main.o myBank.o

main.o: main.c
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c
	$(CC) $(FLAGS) -c myBank.c

.PHONY: clean all

clean: 
	rm *.o mains
