#ifndef GAME_H
#define GAME_H

#include <list>
#include "Player.h"
#include "Shop.h"

class Game{
public:
	Game();
	~Game();
	void init();
	void loop();
private:
	Player *player;
	list<Shop> lShops;
	list<Shop>::iterator lshIter;

	void playerSetup();
	void shopSetup();
	void printShops();


};

#endif
