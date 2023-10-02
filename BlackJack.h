#ifndef BLACKJACK_H
#define BLACKJACK_H

#include"Deck.h"
#include"Player.h"
#include"Human.h"
#include"Computer.h"

class BlackJack:public Deck{
    private:
    int num_humans;
    int num_computers;
    Human *humans;
    Computer *computers;

    public:
    BlackJack(int,int);
    void betting();
    void dealing();
    void humanTurn();
    void computerTurn();
    void settling();
    void showLastMoney();
    bool reset();
};
#endif