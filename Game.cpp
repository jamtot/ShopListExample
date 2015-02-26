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

	player = new Player(playersName, 5000);
	player->printSelf();
}

void Game::shopSetup()
{
	generateShop("Trafalgar");
}

void Game::printShops(){
	lshIter = lShops.begin();
	for (;lshIter != lShops.end(); lshIter++){
		(*lshIter)->printSelf();
	}
}

void Game::travelTo(string placeName){
	lShops.push_back( generateShop(placeName) );
	fillShop(lShops.back());
}


Shop* Game::generateShop(string shopName){
	return new Shop(shopName,1000000);
}

void Game::fillShop(Shop *shop){
	srand(time(NULL));
	int event = 0;
	if (isRandomEvent()){
		event = randomEvent();
	}
	

}

bool Game::isRandomEvent(){
	srand(time(NULL));
	int random = (rand() % 100) + 1;
	//2% chance of random event
	if (random >6 && random < 9){
		randomEvent();
		return true;
	} else { return false; }
}

int Game::randomEvent(){
	int event = (rand() % 10) + 1;
	switch (event){
		case 1:
			//cops
			copAttack();
			break;
		case 2:
			//bumper crop, market flood
			bumperCrop();
			break;
		case 3:
			//famine, sky high prices
			famineCrop();
			break;
		case 4:
			//find a bigger bag
			findBag();
			break;
		case 5:
			//buy a gun
			buyGun();
			break;
		case 6:
			//find a stash
			findStash();
			break;
		case 7:
			//find money
			findMoney();
			break;
		case 8:
			//customs
			customs();
			break;
		case 9:
			//find gun
			findGun();
			break;
		case 10:
			//loanshark coming to break legs
			loanShark();
			break;
		default:
			//nothing
			findMoney();
	}
	return event;
}



void Game::copAttack(){

}

void Game::bumperCrop(){

}
void Game::famineCrop(){

}
void Game::findBag(){
	player->doubleCapacity();	
	cout << "You found a new inventory bag! You can now store " << player->getMaxItems() << " items!" << endl;	
	
}
void Game::buyGun(){

}
void Game::findStash(){

}
void Game::findMoney(){
	int freeMoney = (rand()%20000) + 5000;
	cout << "A rich person threw money at you! You got an extra " << freeMoney << endl;
	player->addMoney(freeMoney);
	
}
void Game::customs(){

}
void Game::findGun(){

}
void Game::loanShark(){

}
