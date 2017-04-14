CC=gcc
CFLAGS=-Wall -ansi -O3

burster: main.o listas.o matriz.o 
	$(CC) $(CFLAGS) -o burster main.o listas.o matriz.o 

main.o: main.c listas.h matriz.h 
	$(CC) -c $(CFLAGS) main.c

matriz.o: matriz.c matriz.h
	$(CC) -c $(CFLAGS) matriz.c

listas.o: listas.c listas.h matriz.c
	$(CC) -c $(CFLAGS) listas.c


clean::
	    rm -f *.o core a.out burster *~



