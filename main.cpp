#include"Card.h"
#include"BlackJack.h"
using namespace std;

int main(){
	srand(time(NULL));
	//set Game
	int num_humans=0;
    int num_computers=0;
	cout << "How many human players :";
    cin >> num_humans;
	cout << "How many computer players :";
	cin >> num_computers;

	BlackJack game(num_humans,num_computers);
	
	while(1){
		game.betting();
		game.dealing();
		game.humanTurn();
		game.computerTurn();
		game.settling();
		game.showLastMoney();
		if(game.reset())return 0;
	}
	return 0;
}
