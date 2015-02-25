#ifndef PLAYER_H
#define PLAYER_H

#include "Base.h"

class Player:public Base{
private:
	int _maxItems;
public:
	Player(string name, int money);
	~Player();
	
	//if item is droppable, drop and rtn true
	bool dropItem(Item item);	
	bool dropItem(string itemName);

};

#endif
