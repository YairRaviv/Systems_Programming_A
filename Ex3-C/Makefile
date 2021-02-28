all: isort txtfind

isort: main.o insertion_sort.o
	gcc -Wall -g -o isort main.o insertion_sort.o

main.o: main.c
	gcc -Wall -g -c main.c

insertion_sort.o: insertion_sort.c
	gcc -Wall -g -c insertion_sort.c
	
txtfind: txtfind.o
	gcc -Wall -g -o txtfind txtfind.o

txtfind.o: txtfind.c
	gcc -Wall -g -c txtfind.c
	
clean:
	rm isort txtfind *.o
