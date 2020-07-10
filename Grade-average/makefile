CC = gcc
CFLAGS = -O3 -Wall

all : average

average : average.c
	$(CC) $(CFLAGS) average.c -o average -lm

run : average
	./average

.PHONY : clean
clean :
	rm -f average