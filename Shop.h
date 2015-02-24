#ifndef SHOP_H
#define SHOP_H

#include <list>
#include <string>
#include "Item.h"
using namespace std;
class Shop{
private:
	string _name;
	list<Item> _lItems;
	list<Item>::iterator _lIter;
	int _money;
public:
	Shop(string name, int money);
	~Shop();
	void printShop();
	void addItem(Item item);
	void printItems();
};

#endif
