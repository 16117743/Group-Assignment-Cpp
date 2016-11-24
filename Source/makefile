all: main.o BoardObject.o Character.o Item.o Inventory.o Enemy.o Wall.o Empty.o Player.o
	g++ -o program main.o BoardObject.o Character.o Item.o Inventory.o Enemy.o Wall.o Empty.o Player.o
	echo all

main.o: main.cpp
	g++ -Wall -g -c main.cpp
	echo main called

BoardObject.o: BoardObject.cpp BoardObject.h
	g++ -Wall -g -c BoardObject.cpp
	echo BoardObject

Character.o: Character.cpp Character.h Inventory.h Item.h
	g++ -Wall -g -c Character.cpp
	echo BoardObject

Item.o: Item.cpp Item.h
	g++ -Wall -g -c Item.cpp

Inventory.o: Inventory.cpp Inventory.h Item.o
	g++ -Wall -g -c Inventory.cpp

Enemy.o: Enemy.cpp Enemy.h
	g++ -Wall -g -c Enemy.cpp

Player.o: Player.cpp Player.h
	g++ -Wall -g -c Player.cpp

Wall.o: Wall.cpp Wall.h
	g++ -Wall -g -c Wall.cpp

Empty.o: Empty.cpp Empty.h
	g++ -Wall -g -c Empty.cpp
