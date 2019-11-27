CC=gcc
OPT=-Wall -std=c11 

all: mes_fonctions.o main.o
	$(CC) $(OPT) mes_fonctions.o main.o
	
mes_fonctions.o:
	$(CC) $(OPT) -c mes_fonctions.c
		
main.o:
	$(CC) $(OPT) -c main.c

clean:
	rm -f *.o
