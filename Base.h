#ifndef BASE_H
#define BASE_H

#include <list>
#include <string>
#include "Item.h"

using namespace std;
class Base{
public:
	Base(string name, int money);
	~Base();
	void printSelf();
	void addItem(Item item);
	void printItems();
	bool haveItem(Item tItem);
	bool haveItem(string itemName);
	void removeItem(string itemName);

	
protected:
	string _name;
	list<Item> _lItems;
	list<Item>::iterator _lIter;
	int _money;
	
public:
	//getters and setters
	int getMoney(){return _money;}
	void setMoney(int amount){_money = amount;}
	void addMoney(int amount){_money+=amount;}
};

#endif
