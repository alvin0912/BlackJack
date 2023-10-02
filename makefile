all:main.o Card.o Deck.o Player.o Human.o Computer.o BlackJack.o
	g++ -o a.out main.o Card.o Deck.o Player.o Human.o Computer.o BlackJack.o
main.o:main.cpp
	g++ -c main.cpp
BlackJack.o:BlackJack.h BlackJack.cpp
	g++ -c BlackJack.cpp
Card.o:Card.h Card.cpp
	g++ -c Card.cpp
Deck.o:Deck.h Deck.cpp
	g++ -c Deck.cpp
Human.o:Human.h Human.cpp
	g++ -c Human.cpp
Computer.o:Computer.h Computer.cpp
	g++ -c Computer.cpp
Player.o:Player.h Player.cpp
	g++ -c Player.cpp
clean:
	rm main.o Card.o Deck.o Player.o Human.o Computer.o BlackJack.o a.out
