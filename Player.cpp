#include "Player.h"

Player::Player(string name, int money) : _name(name), _money(money) {
}

Player::~Player(){}

void Player::printPlayer(){
	int items = _lItems.size();	
	cout << "Your name is " << _name << ", you have " << _money << " Gold Pieces." << endl;
	cout << "You have " << items << " items." << endl;
	if (items > 0){
		printItems();
	}
	cout << endl;
}

void Player::addItem(Item item){
	_lItems.push_back(item);
}

void Player::printItems(){
	_lIter = _lItems.begin();
	for (;_lIter != _lItems.end(); _lIter++){
		(*_lIter).printItem();
	}
}
