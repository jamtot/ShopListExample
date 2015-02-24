#ifndef SHOP_H
#define SHOP_H

#include "Base.h"
//#include <list>
//#include <string>
//#include "Item.h"
#include "Player.h"

using namespace std;
class Shop:public Base{
private:
	//string _name;
	//list<Item> _lItems;
	//list<Item>::iterator _lIter;
	//int _money;
public:
	Shop(string name, int money);
	~Shop();
	//void printShop();
	//void addItem(Item item);
	//void printItems();
	bool sellItem(Player *p, string itemName);
	bool buyItem(Player *p);
};

#endif
