#include "Deck.h"
#include "GoFishUI.h"
#include "GoFish.h"
#include "Cheat.h"
#include <iostream>
#include <string>

using namespace std;

void addNewPlayers(int, int, Game*);

int main()
{

    int gameChoice;
    bool isValid = false;
    Deck* d = new Deck();
    d->createStandard();
    Game * g;


    while(!isValid) {
        cout<<"Which game would you like to play?"<<endl;
        cout<<"1)Go Fish\n2)Cheat"<<endl;
        cout<<"Please enter your choice: ";
        cin>>gameChoice;
        if(gameChoice == 1 || gameChoice == 2)
            isValid = true;
    }


    if(gameChoice == 1) {
        GameUI* ui = new GoFishUI();
        g = new GoFish(ui, d);
        addNewPlayers(2, 5, g);
    }
    else {
        GameUI* ui = new GoFishUI();
        g = new Cheat(ui, d);
        addNewPlayers(2, 10, g);
    }

    g->start();
return 0;

}


void addNewPlayers(int min, int max, Game* game) {
    int playerCount = 0;
    while(!(playerCount >= min && playerCount <= max)) {
        cout<<"How many players("<<min<<"-"<<max<<"): ";
        cin>>playerCount;
    }
    for(int i = 0; i < playerCount; i++) {
        string name;
        cout<<"Player "<<i+1<<", enter your name: ";
        cin>>name;
        game -> addPlayer(new Player(name));
    }

}
