#ifndef DECK_H
#define DECK_H

#include"Card.h"
using namespace std;

class Deck{
	friend ostream& operator << (ostream&,const Card&);
	
	private:
	Card *aDeck;
	int decktop;
	int num_deck;
	int num_card;
	int num_player;

	public:
	Deck(int);
	void shuffleDeck();
	void displayDeck();
	const Card dealCard();
	void swapCard(int,int);
	int getNumCard();
};
#endif
