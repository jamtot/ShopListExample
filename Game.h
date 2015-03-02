#ifndef GAME_H
#define GAME_H

#include <list>
#include "Player.h"
#include "Shop.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Game{
public:
	Game();
	~Game();
	void init();
	void loop();
private:
	Player *player;
	list<Shop*> lShops;
	list<Shop*>::iterator lshIter;
	list<Shop*>::iterator currentShop;
	int daysLeft;
	int multiplier;

	bool famine, bumper;

	void playerSetup();
	void printShops();

	void travelTo(string placeName);
	Shop* generateShop(string shopName);
	Shop* fillShop(Shop* shop);
	bool isRandomEvent();
	void randomEvent();


	//random events
	void copAttack();
	void bumperCrop();
	void famineCrop();
	void findBag();
	void buyGun();
	void findStash();
	void findMoney();
	void customs();
	void findGun();
	void loanShark();

	int getNum1to100();
};

#endif
