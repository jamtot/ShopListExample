/* 	***Shop Explorer***
	What I want to eventually achieve with this game
	is a rough clone of the game drug wars.
	
	The aim of drugwars is to make as much money as 
	you can over a 30 day period. You start off with
	a loan, which if not payed back, grows larger each
	day, due to interest. The player travels to 
	different countries to buy and sell their goods.
	Each trip is a day, and prices/good fluctuate 
	between countries. The player can bank their money
	and withdraw it for buys. There are random events
	such as police interrupting deals, customs inter-
	vening and such. 

	So my aim is to do a non-drug related version.
	I'll start with getting the player and the shops
	working, then I'll move onto the game logic, the
	random events, the fluctuating prices, the loan-	
	shark, the banking system.

	This started as a simple exercise in lists, hope I 
	haven't bitten off more than I can chew.

	-Jonathan Morris
*/

#include <list>
#include "Player.h"
#include "Shop.h"

Player* playerSetup();
void shopSetup(list<Shop> &shplst);
void printShops(list<Shop> &shplst, list<Shop>::iterator &shplstiter);

int main()
{
	cout << "*** Shop Explorer 0.1 ***" << endl << endl;
	Player *player = playerSetup();

	list<Shop> lShops;
	list<Shop>::iterator lshIter;

	shopSetup(lShops);
	printShops(lShops, lshIter);
	
	
	
	return 0;
}

Player* playerSetup(){
	string playersName;
	cout << "Welcome young traveller, what is your name? ";
	cin >> playersName;

	Player * p = new Player(playersName, 250);
	p->addItem(Item("Kitten", 50));
	p->addItem(Item("Tattered Shirt", 0));
	p->addItem(Item("Rotting Potato", -5, 5));
	p->printPlayer();
	return p;
}

void shopSetup(list<Shop> &shplst)
{
	shplst.push_back(Shop("Bill's Big Bad Bakery", 500));
	shplst.back().addItem(Item("Bangin' Bread", 10));
	shplst.back().addItem(Item("Badass Baguette", 6));
	shplst.back().addItem(Item("Delicious Doughnut", 2));
	shplst.back().addItem(Item("Curvaceous Croissant", 4));
	//etc.

	shplst.push_back(Shop("Friendly Fred's Fruitorium", 350));
	shplst.back().addItem(Item("Aromatic Apple", 2));
	shplst.back().addItem(Item("Bountiful Banana", 2));
	shplst.back().addItem(Item("Oversized Orange", 2));
	shplst.back().addItem(Item("Wholesome Watermelon", 3));
	//etc.
}

void printShops(list<Shop> &shplst, list<Shop>::iterator &shplstiter){
	shplstiter = shplst.begin();
	for (;shplstiter != shplst.end(); shplstiter++){
		(*shplstiter).printShop();
	}
}
