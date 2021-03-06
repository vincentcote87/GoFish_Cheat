#include "GoFish.h"

void GoFish::dealCards(vector<Player*> players)
{


    unsigned int numCards;
    if(players.size() < 4)
        numCards = NUM_CARDS_SMALL;
    else
        numCards = NUM_CARDS_LARGE;

    if(deck->size() >= players.size() * numCards)
    {
        unsigned int playerNum = 0;
        for(unsigned int i = 0; i < players.size() * numCards; i++)
        {
            Player* p = players.at(playerNum);
            p->addCard(deck->getCard());
            playerNum = ++playerNum % players.size();
        }
    }
}

void GoFish::beforeCardPlayed(unsigned int playerNum, unsigned int numPlayers)
{
    playerAsked = ui->choosePlayer(playerNum, numPlayers);
}

void GoFish::afterCardPlayed(Player* currentPlayer, vector<Player*> players, Card* played)
{
    list<Card*>* hand = players.at(playerAsked)->getHand();
    list<Card*>::iterator card;
    list<Card*> toRemove;
    for(card = hand->begin(); card != hand->end(); ++card)
    {
        if((*card)->rank == played->rank)
        {
            currentPlayer->getHand()->push_back(*card);
            toRemove.push_back(*card);
        }
    }

    if(toRemove.size() > 0)
    {
        ui->playSucceeded();
        //cout << "Hand before: " << hand->size() << endl;
        for(list<Card*>::iterator card = toRemove.begin(); card != toRemove.end(); ++card)
            hand->remove(*card);
        //cout << "Hand after: " << hand->size() << endl;

        // Check if have a set of cards
        if(hasSet(currentPlayer->getHand()))
        {
            currentPlayer->addPoints(1);
        }
    }
    else
    {
        ui->playFailed();
        Card* c = deck->getCard();
        //cout << "Drew: " << *c << endl;
        currentPlayer->addCard(c);
        if(hasSet(currentPlayer->getHand()))
        {
            currentPlayer->addPoints(1);
        }
    }
}

bool GoFish::hasSet(list<Card*>* hand)
{
    list<Card*> toRemove;
    for(list<Card*>::iterator checking = hand->begin(); checking != hand->end(); ++checking)
    {
        toRemove.clear();
        unsigned int count = 0;
        for(list<Card*>::iterator card = hand->begin(); card != hand->end(); ++card)
        {
            if((*checking)->rank == (*card)->rank)
            {
                count++;
                toRemove.push_back(*card);
            }
        }

        if(count == 4)
        {
            //cout << "Hand before: " << hand->size() << endl;
            for(list<Card*>::iterator card = toRemove.begin(); card != toRemove.end(); ++card)
                hand->remove(*card);
            //cout << "Hand after: " << hand->size() << endl;
            return true;
        }
    }
    return false;
}

