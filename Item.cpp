#include "Item.h"

Item::Item(string name, int value, int damage, int armour) : _name(name), _value(value), _damage(damage), _armour(armour) {

}

Item::~Item(){}

void Item::printItem(){
	cout << "Item name: " << _name << "  ";
	cout << "Item value: " << _value << "  ";
	if (_damage > 0) cout << "Damage: " << _damage;
	if (_armour > 0) cout << "  " << "Armour: " << _armour;
	cout << endl;
}
