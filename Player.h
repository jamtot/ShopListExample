#include <list>
#include "Item.h"

class Player{
private:
	string name;
	list<Item> lItems;
public:
	Player();
	~Player();
};
