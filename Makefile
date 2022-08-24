flags = -Wall -std=c99 -lm
name = myht
objects = hash.o main.o

all: $(name)

$(name): $(objects)
	gcc -o $(name) $(objects) $(flags)

main.o: main.c
	gcc -c main.c $(flags)

hash.o: hash.c
	gcc -c hash.c $(flags)

clean:
	rm -f *~ *.o

purge: clean
	rm -f $(name)