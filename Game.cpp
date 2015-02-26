#include "Game.h"

Game::Game(){}
Game::~Game(){delete player;}

void Game::init(){//set up initial values
	srand(time(NULL));	
	daysLeft = 30;
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
	int i = 31;
	while (daysLeft > 0 && player->isAlive()){
		cout << "You have " << daysLeft << " days left." << endl;		
		int event = 0;	
		if (isRandomEvent()){
			event = randomEvent();
		}

		daysLeft--;
	}
	cout << "Out of time. You made " << player->getMoney() << ". " << endl;
	
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

	

}

bool Game::isRandomEvent(){
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

}
void Game::findMoney(){
	int freeMoney = (rand()%20000) + 5000;
	cout << "A rich person threw money at you! You got an extra " << freeMoney << endl;
	player->addMoney(freeMoney);
	
}
void Game::customs(){

}
void Game::findGun(){
	player->addGun(); 	
	cout << "A panicked man running by shoves a gun into your hands. Free gun! You've now got " << player->getGuns() << " guns now." << endl;
	
}
void Game::loanShark(){//what happens when you encounter the loan shark 
	char choice;	
	cout << "The loan shark wants his money. You have " << player->getMoney() << ", you owe " << player->getLoan() << ". Do you\n A) pay up (up to as much as you can pay), \nB) flee (80%\ chance succesful, 20%\fail, doubles debt), or \nC) attack (5%\ chance to kill and wipe debt, 50%\ chance to get killed yourself, 45%\ chance to wound and magically half the debt)? (a/b/c)";
	cin >> choice;

	int chances = getNum1to100();

	if (choice == 'b' || choice == 'B'){//fleeing
		if (chances < 81){
			cout << "You successfully flee!" << endl;
		} else {
			player->doubleDebt();		
			cout << "You trip trying to skip out on the shark.\nHe doesn't like that.\nYou owe double now to avoid a kneecapping. You now owe " << player->getLoan() << ". Happy?" << endl; 
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
	cout << "You now owe " << player->getLoan() << "." << endl;
}

int getNum1to100(){
	return ((rand()%100) + 1);
}
