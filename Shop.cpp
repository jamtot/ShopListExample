#include "Shop.h"

Shop::Shop(string name, int money) : Base(name,money) {
}

Shop::~Shop(){}


bool Shop::sellItem(Player *p, string itemName){
	//int i = 0;
	_lIter = _lItems.begin();
	for (;_lIter != _lItems.end(); _lIter++){
		(*_lIter).printItem();
	}	
	//if the player has the money to buy

	//does the player have the item already?

	//if so, add to the current items, take the cash

	//if not, add item to the list
	return false;
}
bool Shop::buyItem(Player *p){
	//if the shop have the money to buy
	
	//does the shop already have the item?

	//if so, increment that item, take the money

	//if not, add the item to the list
	return false;
}
