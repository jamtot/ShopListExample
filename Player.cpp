#include "Player.h"

Player::Player(string name, int money) : Base(name,money) {
}

Player::~Player(){}
/*
void Player::printPlayer(){
	int items = _lItems.size();	
	cout << "Your name is " << _name << ", you have " << _money << " Gold Pieces." << endl;
	cout << "You have " << items << " items." << endl;
	if (items > 0){
		printItems();
	}
	cout << endl;
}

//add an item
void Player::addItem(Item item){
	_lItems.push_back(item);
}

//print the items the player has
void Player::printItems(){
	_lIter = _lItems.begin();
	for (;_lIter != _lItems.end(); _lIter++){
		(*_lIter).printItem();
	}
}

//does the player have the item?
bool Player::haveItem(string itemName){
	_lIter = _lItems.begin();
	for (;_lIter != _lItems.end(); _lIter++){
		if ( (*_lIter).getName() == itemName){
			return true;
		}
	}
	return false;
}*/
