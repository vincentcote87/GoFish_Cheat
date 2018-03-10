#include "Cheat.h"

void Cheat::dealCards(vector<Player*> players) {
    unsigned int numCards = deck -> size();

    if(deck->size() > 0) {
        unsigned int playerNum = 0;
        for(unsigned int i = 0; i < numCards; i++) {
            Player* p = players.at(playerNum);
            p->addCard(deck->getCard());
            playerNum = ++playerNum % players.size();
        }
    }
}

void Cheat::beforeCardPlayed(unsigned int playerNum, unsigned int numPlayers) {

    if(!firstMove) {
        //prompt players if they want to call bull shit
    }

    //UI shows what card face it is looking for

    // ui -> currentFace(face[currentFace + 1]);
        // ui -> currentFace('A');

    //currentFace = (currentFace + 1) % 13;

    // playerAsked = ui->choosePlayer(playerNum, numPlayers);
}

void Cheat::afterCardPlayed(Player* currentPlayer, vector<Player*> players, Card* played) {
    // list<Card*>* hand = players.at(playerAsked)->getHand();
    // list<Card*>::iterator card;
    // list<Card*> toRemove;
    // for(card = hand->begin(); card != hand->end(); ++card)
    // {
    //     if((*card)->rank == played->rank)
    //     {
    //         currentPlayer->getHand()->push_back(*card);
    //         toRemove.push_back(*card);
    //     }
    // }

    // if(toRemove.size() > 0)
    // {
    //     ui->playSucceeded();
    //     //cout << "Hand before: " << hand->size() << endl;
    //     for(list<Card*>::iterator card = toRemove.begin(); card != toRemove.end(); ++card)
    //         hand->remove(*card);
    //     //cout << "Hand after: " << hand->size() << endl;

    //     // Check if have a set of cards
    //     if(hasSet(currentPlayer->getHand()))
    //     {
    //         currentPlayer->addPoints(1);
    //     }
    // }
    // else
    // {
    //     ui->playFailed();
    //     Card* c = deck->getCard();
    //     //cout << "Drew: " << *c << endl;
    //     currentPlayer->addCard(c);
    //     if(hasSet(currentPlayer->getHand()))
    //     {
    //         currentPlayer->addPoints(1);
    //     }
    // }
}
