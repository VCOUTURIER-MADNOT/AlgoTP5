CC = gcc -Wall -O3 -ansi -pedantic

all: main clean

main: main.o graphe.o liste.o cellule.o
	$(CC) -o main main.o graphe.o liste.o cellule.o -lm

main.o: main.c
	$(CC) -o main.o -c main.c

graphe.o: graphe.c
	$(CC) -o graphe.o -c graphe.c

liste.o: liste.c
	$(CC) -o liste.o -c liste.c

cellule.o: cellule.c
	$(CC) -o cellule.o -c cellule.c

clean:
	rm -rf *.o