#include "CheatUI.h"
#include <iostream>

unsigned int CheatUI::requestCard(list<Card*>* hand) {
    cout << "Your hand:" << endl;
    unsigned int index = 0;
    for(list<Card*>::iterator i = hand->begin(); i != hand->end(); ++i) {
        Card::Rank r = (*i)->rank;
        cout << "\tChoice " << (++index) << ") " << Card::getRank(r);
        if(index % 2 == 0)
            cout << endl;
    }
    

    unsigned int selection;
    string strSelection;

    while(true) {
        try {
            cout << endl << "Select a choice (hit 55 to end your turn): ";
            cin>>strSelection;
            selection = std::stoi(strSelection);
            break;
        } catch(...) {
            cout<<"Invalid input, try again"<<endl;
        }
    }

    return selection-1;
}

void CheatUI::playFailed() {
    cout<<"Last player did not cheat, please pick up the discard pile for yourself!"<<endl;
}

void CheatUI::playSucceeded() {
    cout<<"last player cheated and received the discard pile!"<<endl;
}
