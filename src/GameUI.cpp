#include "GameUI.h"
#include <iostream>

unsigned int GameUI::choosePlayer(unsigned int playerNum, unsigned int numPlayers) {
    unsigned int selection = playerNum;
    cout << "You are Player #" << playerNum << endl;
    while(selection == playerNum || selection >= numPlayers)
    {
        cout << "Which player (0-" << numPlayers-1 << ")? ";
        cin >> selection;
        if(selection == playerNum)
            cout << "That is you! Please choose another player." << endl;
        if(selection >= numPlayers)
            cout << "Player #" << selection << " doesn't exist! Please choose another player." << endl;
    }
    return selection;

}

void GameUI::showScores(vector<Player*> players){
    cout << "---- Scores ----" << endl;
    for(Player* player : players)
    cout << player->name << ": " << player->getScore() << endl;
}

ostream& operator<<(ostream& os, const Card& c)
{
    os << Card::getRank(c.rank) << ":" << Card::getSuit(c.suit);
    return os;
}

void GameUI::currentFace(char face) {
    cout<<"Do you have any "<<face<<"'s?"<<endl;
}

void GameUI::playerName(Player* player) {
    cout<<player -> name<<" it's your turn"<<endl;
}

unsigned int GameUI::callCheat(vector<Player*> players) {
    unsigned int selection = 0;
    string strSelection;

    cout<<"Does anyone want to call cheat?"<<endl;
    for(int i = 0; i < players.size(); i++) {
        cout<<"Choice "<<i<<") "<<players[i] -> name<<" wants to call cheat"<<endl;
    }
    cout<<"Choice "<<players.size()<<") Nobody calls cheat"<<endl;
    
    while(true) {
        try {
            cout<<"Your selection: ";
            cin>>strSelection;
            selection = stoi(strSelection);
            break;
        } catch(...) {
            cout<<"Invalid input, try again"<<endl;
        }
    }
    
    

    return selection;
}

void GameUI::noCardsPlayed() {
    cout<<"you must discard at least one card"<<endl;
}