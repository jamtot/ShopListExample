#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Item{
private:
	string _name;	
	int _value;
	int _damage;
	int _armour;
	//etc.
public:
	Item(string name, int value, int damage = 0, int armour = 0);
	~Item();
	void printItem();
	//getters & setters
	string getName(){return _name;}
};

#endif
