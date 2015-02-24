CC=g++
CFLAGS=-Wall -g

all: main main.o Player.o Shop.o Item.o
	
main: main.o Shop.o Player.o Item.o
	$(CC) $(CFLAGS) main.o Shop.o Player.o Item.o -o main

main.o: main.cpp Shop.cpp Player.cpp Item.cpp
	$(CC) $(CFLAGS) -c main.cpp

Player.o: Player.cpp Item.cpp
	$(CC) $(CFLAGS) -c Player.cpp

Shop.o: Shop.cpp Item.cpp
	$(CC) $(CFLAGS) -c Shop.cpp

Item.o: Item.cpp
	$(CC) $(CFLAGS) -c Item.cpp

clean:
	rm -f *o main
