#include"Player.h"

Player::Player(){
    string names[]={"Mike","Bob","Shine","Angelica","Brenda","Celestine"\
        ,"Elizabeth","Hortensia","June","Natasha","Sandra","Winifred","Natalie","Lucinda"\
            ,"Lauretta","Edwin","Ferdinand","Jarvis","Nicholas","Theodore","Winston"};
    name=names[rand()%21];
    bankroll=rand()%1000;
    bet=0;
    totalPoint=0;
	num_handCard=0;
	round_win=0;
	//cout << "create a player!" << endl;
}

string Player::getName(){
    return name;
}

int Player::getBet(){
	return bet;
}

void Player::setBet(int newBet){
	bet=newBet;
}

int Player::getBankroll(){
	return bankroll;
}

void Player::setBankroll(int newBankroll){
	bankroll=newBankroll;
}

void Player::setName(string name){
	this->name=name;
}

//about hand card
Card Player::getHandCard(int idx){
	//cout << handCard[idx];
	return handCard[idx];
}

void Player::setHandCard(const Card &newCard){
	handCard[num_handCard]=newCard;
	num_handCard++;
}

void Player::resetHandCard(){
	num_handCard=0;	
}

int Player::getNumHandCard(){
	return num_handCard;
}

void Player::computeTotalPoint(){
	int sum=0;
	int value=0;
	for(int i=0;i<getNumHandCard();i++){
		value=getHandCard(i).getValue()+1;
		if(value>0 && value<10)sum+=value;
		else if(value>9)sum+=10;
		else if(value==1){
			if((sum+11)>21)sum+=1;
			else if((sum+11)>18)sum+=11;
			else sum+=1;
		}
	}
	totalPoint=sum;
}

int Player::getTotalPoint(){
	return totalPoint;
}

int Player::getRoundWin(){
	return round_win;
}

int Player::judge(int point_dealer){
	if(getTotalPoint()>21 && point_dealer<=21){
		round_win=0;
		bankroll-=bet;
		cout << "Ouch! " << getName() << " loses $" << bet << endl;
		return bet;
	}
	else if(getTotalPoint()<=21 && point_dealer>21){
		round_win++;
        bankroll+=bet;
		cout << "Yowzah! " << getName() << " wins $" << bet << endl;
        return -bet;
	}
	else if(getTotalPoint()<=21 && point_dealer<=21){
		if(getTotalPoint()>point_dealer){
			round_win++;
			bankroll+=bet;
			cout << "Yowzah! " << getName() << " wins $" << bet << endl;
			return -bet;
		}
		else if(getTotalPoint()<point_dealer){
			round_win=0;
			bankroll-=bet;
			cout << "Ouch! " << getName() << " loses $" << bet << endl;
			return bet;
		}
		else {
			round_win=0;
			cout << getName() << " get equal" << endl;
			return 0;
		}
	}
	else {
		round_win=0;
		cout << getName() << " get equal" << endl;
		return 0;
	}
}

