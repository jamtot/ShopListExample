#include "Player.h"

Player::Player(string name, int money) : Base(name,money) {
}

Player::~Player(){}

bool Player::dropItem(Item item){
	if (haveItem(item)){
		return true;
	} else { //no item to drop
		return false; 
	}
}
bool Player::dropItem(string itemName){
	if (haveItem(itemName)){
		return true;
	} else { //no item to drop
		return false; 
	}
}
