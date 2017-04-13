CC=gcc
CFLAGS=-g -Wall

burster: main.o listas.o matriz.o graph.o
	$(CC) $(CFLAGS) -o burster main.o listas.o matriz.o graph.o

main.o: main.c listas.h matriz.h graph.h
	$(CC) -c $(CFLAGS) main.c

matriz.o: matriz.c matriz.h
	$(CC) -c $(CFLAGS) matriz.c

listas.o: listas.c listas.h matriz.c
	$(CC) -c $(CFLAGS) listas.c

graph.o: graph.c graph.h
	$(CC) -c $(CFLAGS) graph.c

clean::
	    rm -f *.o core a.out burster *~



