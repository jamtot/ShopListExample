#include <list>
#include <string>
#include "Item.h"

class Shop{
private:
	string name;
	list<Item> lItems;
public:
	Shop();
	~Shop();
};
