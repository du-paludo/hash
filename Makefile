CC = gcc
CFLAGS = -Wall -g -D_DEFAULT_SOURCE

objects = hash.o main.o

all: main

main: $(objects)
	$(CC) $(objects) -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

hash.o: hash.c hash.h
	$(CC) $(CFLAGS) -c hash.c

clean:
	rm -f $(objects)

purge: clean
	rm main