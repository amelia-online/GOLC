CC ?= gcc
CFLAGS ?= -Wall -fsanitize=undefined -fsanitize=address -g

Demo: main.o world.o cell.o
	$(CC) $(CFLAGS) -o Demo main.o world.o cell.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

world.o: world.h world.c
	$(CC) $(CFLAGS) -c world.c

cell.o: cell.h cell.c
	$(CC) $(CFLAGS) -c cell.c

test:
	./Demo

clean:
	rm ./Demo *.o

