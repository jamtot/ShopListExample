#include "Game.h"

Game::Game(){}
Game::~Game(){delete player;}

void Game::init(){//set up initial values
	srand(time(NULL));	
	daysLeft = 30;
	cout << "*** Shop Explorer 0.1 ***" << endl << endl;
	playerSetup();
	//printShops();
}

void Game::loop(){//the loop for the game
	//select a shop (akin to drugwars country)
	//roll to see if a random event happens (player finds a bigger backpack, 			finds a stash, drops something when confronted by someone, is attacked, 		etc.)
	//list shops goods and prices, allowing player to buy or sell
	//
	while (daysLeft > 0 && player->isAlive()){
		cout << "You have " << daysLeft << " days left." << endl;		
		string placeName;
		cout << "Where would you like to go? ";
		cin >> placeName;	
		multiplier = 1;
		if (isRandomEvent()){
			randomEvent();
		} 
		if (player->isAlive()){
			travelTo(placeName);
		} else {
			cout << "You don't arrive at " << placeName << "." << endl;
		}

		player->update();
		daysLeft--;
	}
	cout << "Out of time. You made " << player->getFinal() << ". " << endl;
}

void Game::playerSetup(){
	string playersName;
	cout << "Welcome young traveller, what is your name? ";
	cin >> playersName;

	player = new Player(playersName, 5000);
	player->printSelf();
}

void Game::printShops(){
	lshIter = lShops.begin();
	for (;lshIter != lShops.end(); lshIter++){
		(*lshIter)->printSelf();
	}
}

void Game::travelTo(string placeName){
	lShops.push_back( fillShop( generateShop( placeName ) ) );
	//get the last shop (end returns 1 after the end)
	currentShop = (--lShops.end());
	cout << "You arrive at " << placeName << "." << endl << "Available goods are:" << endl;
	(*currentShop)->printItems();
}


Shop* Game::generateShop(string shopName){
	return new Shop(shopName,10000000);
}

Shop* Game::fillShop(Shop *shop){
	if (famine){	
		shop->addItem(Item("Gold nugget", ( (rand() %250 ) + 250) * multiplier));
		shop->addItem(Item("Rare apple", ( (rand() %300 ) + 10) * multiplier));
		shop->addItem(Item("Opium", ( (rand() % 15000 ) + 10000) * multiplier));
		shop->addItem(Item("Medicine", ( (rand() %7500 ) + 2500) * multiplier));
		shop->addItem(Item("Blue rocks", ( (rand() %200 ) + 50) * multiplier));
		shop->addItem(Item("Slave", ( (rand() %75000 ) + 25000) * multiplier));
		shop->addItem(Item("Cart", ( (rand() %2500 ) + 2500) * multiplier));
		shop->addItem(Item("Meat", ( (rand() %290 ) + 10) * multiplier));
		shop->addItem(Item("Potatoes", ( (rand() %45 ) + 5) * multiplier));
		shop->addItem(Item("Donkey", ( (rand() %12500 ) + 2500) * multiplier));
	} else {
		shop->addItem(Item("Gold nugget", ( (rand() %250 ) + 250) / multiplier));
		shop->addItem(Item("Rare apple", ( (rand() %300 ) + 10) / multiplier));
		shop->addItem(Item("Opium", ( (rand() % 15000 ) + 10000) / multiplier));
		shop->addItem(Item("Medicine", ( (rand() %7500 ) + 2500) / multiplier));
		shop->addItem(Item("Blue rocks", ( (rand() %200 ) + 50) / multiplier));
		shop->addItem(Item("Slave", ( (rand() %75000 ) + 25000) / multiplier));
		shop->addItem(Item("Cart", ( (rand() %2500 ) + 2500) / multiplier));
		shop->addItem(Item("Meat", ( (rand() %290 ) + 10) / multiplier));
		shop->addItem(Item("Potatoes", ( (rand() %45 ) + 5) / multiplier));
		shop->addItem(Item("Donkey", ( (rand() %12500 ) + 2500) / multiplier));	
	}
	return shop;

}

bool Game::isRandomEvent(){
	int random = (rand() % 100) + 1;
	//2% chance of random event
	if (random >6 && random < 9){
		//randomEvent();
		return true;
	} else { return false; }
}

void Game::randomEvent(){
	int event = (rand() % 10) + 1;
	switch (event){
		case 1:
			//cops
			copAttack();
			break;
		case 2:
			//bumper crop, market flood
			bumperCrop();
			bumper = true;
			famine = false;
			break;
		case 3:
			//famine, sky high prices
			famineCrop();
			famine = true;	
			bumper = false;
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
	if (event == 2 || event == 3){
		multiplier = (rand()%9)+2;
	} else {
		bumper = false;
		famine = false;
		multiplier = 1;
	}
}

void Game::copAttack(){
	char choice;	
	cout << "A cop stops you, you look a little sweaty. \nA) Stay and chat, or \nB) flee. (A/B):" ;
	cin >> choice;
	if (choice == 'A' || choice == 'a'){
		cout << "You have a nice chat. You talk about sports or tv... or something. Not all cops assume the worst you know. He lets you on your way." << endl;
	} else {
		cout << "Have you actually ever watched worlds wildest police videos? The cops have helicopters. You are caught, obviously." << endl;
		player->setAlive(false);
	} 
}

void Game::bumperCrop(){
	cout << "A bumper crop of X floods the market. What is X? YOU DECIDE! (with implementation, of course.)" << endl;
}

void Game::famineCrop(){
	cout << "Demand soars for <insert purchasable here>! Implement this now!" << endl;
}

void Game::findBag(){
	player->doubleCapacity();	
	cout << "You found a new inventory bag! You can now store " << player->getMaxItems() << " items!" << endl;	
}

void Game::buyGun(){
	char buy;	
	cout << "You meet a 'gun broker'. Would you like to buy a gun for 2000?(y/n)";
	cin >> buy;
	if ((buy == 'y' || buy == 'Y')){
		if (player->getMoney() >= 2000){			
			player->addGun();
			player->addMoney(-2000);
			cout << "You now have " << player->getGuns() << " gun(s). You have " << player->getMoney() << " money left." << endl;
		} else {
			cout << "You don't have the funds m'dear." << endl;
		}
	} else {
		cout << "You tell him where to stick his guns." << endl;
	}
}

void Game::findStash(){
	cout << "You found a stash...implement your inventory please." << endl;
}

void Game::findMoney(){
	int freeMoney = (rand()%20000) + 5000;
	cout << "A rich person threw money at you! You got an extra " << freeMoney << endl;
	player->addMoney(freeMoney);
	
}

void Game::customs(){
	cout << "Customs, oh no! You toss your guns." << endl;
	player->tossGuns();
}

void Game::findGun(){
	player->addGun(); 	
	cout << "A panicked man running by shoves a gun into your hands. Free gun! You've got " << player->getGuns() << " gun(s) now." << endl;
	
}

//TODO change this to use guns to help kill chance
void Game::loanShark(){//what happens when you encounter the loan shark 
	char choice;	
	cout << "The loan shark wants his money. You have " << player->getMoney() << ", you owe " << player->getDebt() << ". Do you\nA) pay up (up to as much as you can pay), \nB) flee (80\% chance succesful, 20\%fail, doubles debt), or \nC) attack (5\% chance to kill and wipe debt, 50\% chance to get killed yourself, 45\% chance to wound and magically half the debt)? (A/B/C): ";
	cin >> choice;

	int chances = getNum1to100();

	if (choice == 'b' || choice == 'B'){//fleeing
		if (chances < 81){
			cout << "You successfully flee!" << endl;
		} else {
			player->doubleDebt();		
			cout << "You trip trying to skip out on the shark.\nHe doesn't like that.\nYou owe double now to avoid a kneecapping. You now owe " << player->getDebt() << ". Happy?" << endl; 
		}

	} else if (choice == 'c' || choice == 'C') {
		if (chances < 6){//attack the shark
			player->wipeDebt();			
			cout << "What kind of shark does his own dirty work? THE DEAD KIND. You owe nothing." << endl;
		} else if (chances < 56) {
			cout << "You attempt fire on the shark, but your sweaty hands cause you to drop the weapon.\nYour face turns red as he blows your face in." << endl;
			player->setAlive(false);//kill the player
		} else {
			player->halfDebt();			
			cout << "You wound the shark before you run out of bullets.\nAs he lies crying in his own blood he offers to half your debt if you let him live.\nYou're no murderer.\nDeal." << endl;
		}

	} else {//you're paying up if you hit a, or anything else
		if (player->getMoney() >= player->getDebt()){//if player has enough to pay all off
			player->addMoney( (player->getDebt()) * -1);
			player->setDebt(0);
			cout << "Really? All it took was him to show up for you to pay up? Pfft." << endl;
		} else {//if you don't have enough, pay all you can
			player->addDebt(player->getMoney() * - 1);
			player->setMoney(0);
			cout << "Looks like you don't have enough. He takes all you have. You still need to pay up, but you've bought some time." << endl;
			
		}
	}
	if (player->isAlive())
		cout << "You now owe " << player->getDebt() << "." << endl;
}

int Game::getNum1to100(){
	return ((rand()%100) + 1);
}
