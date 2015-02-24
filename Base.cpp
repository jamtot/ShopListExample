#include "Base.h"

Base::Base(string name, int money) : _name(name), _money(money){
}

Base::~Base(){}

//prints the name, money and items held.
void Base::printSelf(){
	int items = _lItems.size();	
	cout << _name << " has " << _money << " Gold Pieces, and " << 			items << " items." << endl;
	if (items > 0){
		printItems();
	}
	cout << endl;
}

//add an item
void Base::addItem(Item item){
	_lItems.push_back(item);
}

//print the items the base has
void Base::printItems(){
	_lIter = _lItems.begin();
	for (;_lIter != _lItems.end(); _lIter++){
		(*_lIter).printItem();
	}
}

//does the player have the item?
bool Base::haveItem(Item tItem){
	_lIter = _lItems.begin();
	for (;_lIter != _lItems.end(); _lIter++){
		if ( (*_lIter).getName() == tItem.getName()){
			return true;
		}
	}
	return false;
}
