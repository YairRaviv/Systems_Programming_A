CC=gcc
FLAGS= -Wall
AR=ar

all: mains maind

mymaths: libmyMath.a

mymathd: libmyMath.so

mains: main.o libmyMath.a
	$(CC) $(FLAGS) -o mains main.o libmyMath.a

maind: main.o libmyMath.so
	$(CC) $(FLAGS) -o maind main.o ./libmyMath.so

libmyMath.a: power.o basicMath.o
	$(AR) -rcs libmyMath.a power.o basicMath.o

libmyMath.so: power.o basicMath.o
	$(CC) -shared -o libmyMath.so basicMath.o power.o

basicMath.o: basicMath.c
	$(CC) $(FLAGS) -c basicMath.c

power.o: power.c 
	$(CC) $(FLAGS) -c power.c

main.o: main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all mymaths mymathd

clean: 
	rm main.o basicMath.o power.o libmyMath.so libmyMath.a maind mains 
