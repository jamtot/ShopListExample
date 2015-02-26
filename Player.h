#ifndef PLAYER_H
#define PLAYER_H

#include "Base.h"

class Player:public Base{
private:
	int _maxItems;
	int _loan;
	int _bank;
	int _guns;
	bool _isAlive;
public:
	Player(string name, int money);
	~Player();
	
	void update();
	bool payLoan();
	bool getLoan();
	void doubleCapacity();
	void addGun();
	void tossGuns();
	void doubleDebt();
	void wipeDebt();
	void halfDebt();

	//if item is droppable, drop and rtn true
	bool dropItem(Item item);	
	bool dropItem(string itemName);

	//getters and setters
	int getMaxItems(){ return _maxItems; }
	int getGuns(){return _guns;}	
	bool isAlive(){return _isAlive;}
	void setAlive(bool alive){_isAlive = alive;}
	void addDebt(int amount){ _loan+=amount; }
	void setDebt(int amount){ _loan = amount; }
	int getDebt(){return _loan;}
	int getFinal();
	
	void deposit(int money);
	void withdraw(int withdrawal);
	

};

#endif
