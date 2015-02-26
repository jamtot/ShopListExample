#ifndef SHOP_H
#define SHOP_H

#include "Base.h"
#include "Player.h"

using namespace std;
class Shop:public Base{
private:
	
public:
	Shop(string name, int money);
	~Shop();
	
	bool sellItem(Player *p, string itemName);
	bool buyItem(Player *p);
};

#endif
