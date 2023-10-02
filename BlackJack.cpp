#include"BlackJack.h"

BlackJack::BlackJack(int num_humans,int num_computers):Deck(num_humans+num_computers){
    //int num_players;
	this->num_humans=num_humans;
    this->num_computers=num_computers;

    humans = new Human[num_humans];
	computers = new Computer[num_computers];

	computers[num_computers-1].setDealer();
	shuffleDeck();

    //check player list
	/*
	for(int i=0;i<num_humans;i++)
		cout << humans[i].getName() << "--" << humans[i].getBankroll() << endl;
	for(int i=0;i<num_computers;i++)
		cout << computers[i].getName() << "(" << computers[i].getPersonality() << ")" << "--" << computers[i].getBankroll() << endl;
	*/
}

void BlackJack::betting(){
	cout << endl;
	cout << "Okay,time for betting!" << endl;
	cout << "----------------------" << endl;
	
	for(int i=0;i<num_humans;i++){
		cout << humans[i].getName() << ",how much would you like to bet?";
		humans[i].decideBet();
	}
	for(int i=0;i<num_humans;i++)cout << humans[i].getName() << " bets $" << humans[i].getBet() << endl;

	for(int i=0;i<num_computers;i++){
		computers[i].decideBet();
		cout << computers[i].getName() << " bets $" << computers[i].getBet() << endl;
	}
	cout << endl;
}

void BlackJack::dealing(){
	cout << "The initial starting cards are:" << endl;
    cout << "-------------------------------" << endl;
	for(int i=0;i<num_humans;i++){
		for(int j=0;j<2;j++)humans[i].setHandCard(dealCard());
		cout << humans[i].getName() << "'s current hand:[??]";
		(humans[i].getHandCard(1)).displayCard();
		cout << endl;
	}

	for(int i=0;i<num_computers;i++){
		for(int j=0;j<2;j++)computers[i].setHandCard(dealCard());
		cout << computers[i].getName() << "'s current hand:[??]";
		(computers[i].getHandCard(1)).displayCard();
		cout << endl;
	}
	cout << endl;
}

void BlackJack::humanTurn(){
	for(int i=0;i<num_humans;i++){
		cout << humans[i].getName() << "'s turn:" << endl;
		cout << "----------------------" << endl;
		while(1){
			cout << humans[i].getName() << "'s current hand:";
			for(int j=0;j<humans[i].getNumHandCard();j++)(humans[i].getHandCard(j)).displayCard();
			humans[i].computeTotalPoint();
			cout << "(" << humans[i].getTotalPoint() << ")" <<endl;

			if(humans[i].decideDraw()){
				cout << humans[i].getName() << " chooses to draw." << endl;
				humans[i].setHandCard(dealCard());
				humans[i].computeTotalPoint();
				if(humans[i].getTotalPoint()>21){
					cout << humans[i].getName() << " busted at " << humans[i].getTotalPoint() << endl;
					for(int j=0;j<humans[i].getNumHandCard();j++)(humans[i].getHandCard(j)).displayCard();
					cout << endl;
					cout << endl;
					break;
				}
			}
			else{
				cout << humans[i].getName() << " chooses to stay." << endl;
				cout << endl;
				break;
			}
		}
	}
}

void BlackJack::computerTurn(){
	for(int i=0;i<num_computers;i++){
		cout << computers[i].getName() << "'s turn:" << endl;
		cout << "----------------------" << endl;
		while(1){
			cout << computers[i].getName() << "'s current hand:";
			for(int j=0;j<computers[i].getNumHandCard();j++)(computers[i].getHandCard(j)).displayCard();
			computers[i].computeTotalPoint();
			cout << "(" << computers[i].getTotalPoint() << ")" <<endl;

			if(computers[i].decideDraw()){
				cout << computers[i].getName() << " chooses to draw." << endl;
				computers[i].setHandCard(dealCard());
				computers[i].computeTotalPoint();
				if(computers[i].getTotalPoint()>21){
					cout << computers[i].getName() << " busted at " << computers[i].getTotalPoint() << endl;
					for(int j=0;j<computers[i].getNumHandCard();j++)(computers[i].getHandCard(j)).displayCard();
					cout << endl;
					cout << endl;
					break;
				}
			}
			else{
				cout << computers[i].getName() << " chooses to stay." << endl;
				cout << endl;
				break;
			}
		}
	}
}

void BlackJack::settling(){
	cout << "Let's see how it turned out:" << endl;
    cout << "----------------------------" << endl;
	int Dealer_sum=0;
	for(int i=0;i<num_humans;i++)Dealer_sum+=humans[i].judge(computers[num_computers-1].getTotalPoint());
	for(int i=0;i<num_computers-1;i++)Dealer_sum+=computers[i].judge(computers[num_computers-1].getTotalPoint());
	Dealer_sum+=computers[num_computers-1].getBankroll();
	computers[num_computers-1].setBankroll(Dealer_sum);
	cout << endl;
}

void BlackJack::showLastMoney(){
	cout << "The standings so far:" << endl;
    cout << "---------------------" << endl;
	for(int i=0;i<num_humans;i++)cout << humans[i].getName() << " $" << humans[i].getBankroll() << endl;
	for(int i=0;i<num_computers;i++)cout << computers[i].getName() << " $" << computers[i].getBankroll() << endl;
	cout << endl;
}

bool BlackJack::reset(){
	string answer;
	while(1){
		cout << "Another round?(Y op N):";
		cin >> answer;
		if(answer!="N" && answer!="Y")cout << "invalid input!" << endl;
		else if(answer=="N")return true;
		else{
			for(int i=0;i<num_humans;i++)humans[i].resetHandCard();
			for(int i=0;i<num_computers;i++)computers[i].resetHandCard();
			return false;				
		}
	}
}
