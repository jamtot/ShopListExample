#include "Game.h"

Game::Game(){}
Game::~Game(){delete player;}

void Game::init(){//set up initial values
	
	cout << "*** Shop Explorer 0.1 ***" << endl << endl;
	playerSetup();
	shopSetup();
	printShops();

}

void Game::loop(){//the loop for the game
	//select a shop (akin to drugwars country)
	//roll to see if a random event happens (player finds a bigger backpack, 			finds a stash, drops something when confronted by someone, is attacked, 		etc.)
	//list shops goods and prices, allowing player to buy or sell
	//
}

void Game::playerSetup(){
	string playersName;
	cout << "Welcome young traveller, what is your name? ";
	cin >> playersName;

	player = new Player(playersName, 250);
	player->addItem(Item("Kitten", 50));
	player->addItem(Item("Tattered Shirt", 0));
	player->addItem(Item("Rotting Potato", -5, 5));
	player->addItem(Item("Pudding", 1));
	cout << endl;
	player->printSelf();
	player->removeItem("Pudding");
	player->printSelf();
}

void Game::shopSetup()
{
	lShops.push_back(Shop("Bill's Big Bad Bakery", 500));
	lShops.back().addItem(Item("Bangin' Bread", 10));
	lShops.back().addItem(Item("Badass Baguette", 6));
	lShops.back().addItem(Item("Delicious Doughnut", 2));
	lShops.back().addItem(Item("Curvaceous Croissant", 4));
	//etc.

	lShops.push_back(Shop("Friendly Fred's Fruitorium", 350));
	lShops.back().addItem(Item("Aromatic Apple", 2));
	lShops.back().addItem(Item("Bountiful Banana", 2));
	lShops.back().addItem(Item("Oversized Orange", 2));
	lShops.back().addItem(Item("Wholesome Watermelon", 3));
	//etc.
}

void Game::printShops(){
	lshIter = lShops.begin();
	for (;lshIter != lShops.end(); lshIter++){
		(*lshIter).printSelf();
	}
}
