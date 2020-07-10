CC = gcc
CFLAGS = -O3 -Wall

all : molecules

molecules : molecules.c
	$(CC) $(CFLAGS) molecules.c -o molecules -lm

run : molecules
	./molecules

.PHONY : clean
clean :
	rm -f molecules