#include"Deck.h"

Deck::Deck(int num_player){
	this->num_player=num_player;
	decktop=0;
	num_deck=(num_player-1)/4+1;
	num_card=52*num_deck;
	aDeck=new Card[num_card];
	for(int j=0;j<num_deck;j++){
		for(int i=0;i<52;i++)aDeck[j*52+i].setCard(i);
	}
}

void Deck::shuffleDeck(){
	for(int i=0;i<50;i++)swapCard(rand()%52,rand()%52);
}

void Deck::displayDeck(){
	for(int i=decktop;i<num_card;i++)aDeck[i].displayCard();
}

const Card Deck::dealCard(){
	if(decktop<num_player*5-1)decktop++;
	else{
		shuffleDeck();
		decktop=1;
	}
	
	return aDeck[decktop-1];
}

void Deck::swapCard(int a,int b){
	Card tmp=aDeck[a];
	aDeck[a]=aDeck[b];
	aDeck[b]=tmp;
}

int Deck::getNumCard(){
	return num_card;
}

ostream& operator << (ostream& out,const Card& c){
	out << c;
	return out;
}
