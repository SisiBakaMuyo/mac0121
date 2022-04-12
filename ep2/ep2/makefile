CC     = gcc
CFLAGS = -Wall -ansi -pedantic -O2 -g
OBJECTS = palavra.o aloca.o imprime.o pilha.o

#------------------------------------------------

ep2: palavra.o aloca.o imprime.o pilha.o ep2.c
	$(CC) $(CFLAGS) palavra.o aloca.o imprime.o pilha.o ep2.c -o ep2 	

palavra.o: palavra.c palavra.h pilha.h
	$(CC) $(CFLAGS) -c palavra.c 

aloca.o: aloca.c aloca.h 
	$(CC) $(CFLAGS) -c aloca.c

imprime.o: imprime.c imprime.h 
	$(CC) $(CFLAGS) -c imprime.c	

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c	

clean :
	rm -rf  $(OBJECTS)