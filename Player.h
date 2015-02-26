#ifndef PLAYER_H
#define PLAYER_H

#include "Base.h"

class Player:public Base{
private:
	int _maxItems;
	int _loan;
public:
	Player(string name, int money);
	~Player();
	
	void update();
	bool payLoan();
	bool getLoan();
	void addMoney(int money);
	void doubleCapacity();

	//if item is droppable, drop and rtn true
	bool dropItem(Item item);	
	bool dropItem(string itemName);

	//getters and setters
	int getMaxItems(){ return _maxItems; }

	

};

#endif
