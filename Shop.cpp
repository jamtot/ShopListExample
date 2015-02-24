#include "Shop.h"

Shop::Shop(string name, int money) : _name(name), _money(money) {
}

Shop::~Shop(){}

void Shop::printShop(){
	int items = _lItems.size();	
	cout << "This Shop is " << _name << ", and it has " << _money << " Gold Pieces to trade with." << endl;
	cout << "To sell, we have " << items << " items." << endl;
	if (items > 0){
		printItems();
	}
	cout << endl;
}

void Shop::addItem(Item item){
	_lItems.push_back(item);
}

void Shop::printItems(){
	_lIter = _lItems.begin();
	for (;_lIter != _lItems.end(); _lIter++){
		(*_lIter).printItem();
	}
}
