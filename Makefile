CC=g++
CFLAGS=-Wall -g

all: main main.o Game.o Base.o Player.o Shop.o Item.o
	
main: main.o Game.o Base.o Shop.o Player.o Item.o
	$(CC) $(CFLAGS) main.o Game.o Base.o Shop.o Player.o Item.o -o main

main.o: main.cpp Game.cpp
	$(CC) $(CFLAGS) -c main.cpp

Game.o: Game.cpp Player.cpp Shop.cpp
	$(CC) $(CFLAGS) -c Game.cpp

Base.o: Base.cpp Item.cpp
	$(CC) $(CFLAGS) -c Base.cpp

Player.o: Player.cpp Item.cpp
	$(CC) $(CFLAGS) -c Player.cpp

Shop.o: Shop.cpp Item.cpp
	$(CC) $(CFLAGS) -c Shop.cpp

Item.o: Item.cpp
	$(CC) $(CFLAGS) -c Item.cpp

clean:
	rm -f *o main
