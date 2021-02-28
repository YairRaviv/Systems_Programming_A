all: frequency

frequency: frequency.o
	gcc -o frequency frequency.o

frequency.o: frequency.c
	gcc -c frequency.c


clean:
	rm frequency *.o
