#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <string>
#include "Item.h"
using namespace std;
class Player{
private:
	string _name;
	list<Item> _lItems;
	list<Item>::iterator _lIter;
	int _money;
public:
	Player(string name, int money);
	~Player();
	void printPlayer();
	void addItem(Item item);
	void printItems();
};

#endif
