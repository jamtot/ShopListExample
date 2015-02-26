#include "Player.h"

Player::Player(string name, int money) : Base(name,money) {
	_loan = 5000;
	_maxItems = 40;
	_isAlive = true;
}

Player::~Player(){}

void Player::update(){
	_loan += (_loan/20);
}

bool Player::payLoan(){
	int toPay;	
	cout << "You currently owe " << _loan << ". How much would you like to pay? ";
	cin >> toPay;
	if (toPay <= _money){
		_money -= toPay;
		cout << "You have paid " << toPay << ". You now owe " << _loan << ". You have " << _money << " left." << endl;
		return true;
	} else {	
		cout << "You don't have enough to pay." << endl;
		return false;
	}
}

bool Player::getLoan(){
	int maxLoan = (_money * 5) - _loan;	
	int toGet;
	cout << "You currently have " << _money << " and owe " << _loan << ". How much would you like to borrow (maximum loan of " << maxLoan << ")?";
	cin >> toGet;
	if ( toGet <= maxLoan){
		_money += toGet;
		_loan += toGet;
		return true;
	} else {
		cout << "You already owe " << _loan << "!" << endl;
		return false;
	}
}

void Player::doubleCapacity(){
	_maxItems*=2;
}

void Player::addGun(){
	_guns+=1;
}
	
void Player::tossGuns(){
	_guns = 0;
}

void Player::doubleDebt(){
	_loan*=2;
}

void Player::wipeDebt(){
	_loan = 0;
}

void Player::halfDebt(){
	_loan/=2;
}

bool Player::dropItem(Item item){
	if (haveItem(item)){
		return true;
	} else { //no item to drop
		return false; 
	}
}
bool Player::dropItem(string itemName){
	if (haveItem(itemName)){
		return true;
	} else { //no item to drop
		return false; 
	}
}

int Player::getFinal(){
	if (_money < _loan)
		return 0;
	else
		return _money-=_loan;
}

void Player::deposit(int money){
	if (money <= _money){//can deposit
		_bank += money;
		_money -= money;	
		cout << "You now have "<<_money<<" money, "<<_bank<<" in the bank, and owe " << _loan << "." << endl;
	} else { 
		cout << "You don't got the dosh, bro. Can only deposit a max of " << _money << "." << endl;
	}
}

void Player::withdraw(int withdrawal){
	if (withdrawal <= _bank){//can withdraw
		_bank -= withdrawal;
		_money += withdrawal;
		cout << "You now have "<<_money<<" money, "<<_bank<<" in the bank, and owe " << _loan << "." << endl;
	} else { 
		cout << "You don't got the cash in the bank to make this withdrawal. Can only withdraw a max of " << _bank << "." << endl;
	}
}
