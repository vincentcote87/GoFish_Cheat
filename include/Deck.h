#ifndef DECK_H
#define DECK_H

using namespace std;

#include "Card.h"
#include <list>

class Deck
{
public:

    virtual ~Deck() {}

    /**
    * Shuffle the deck.
    */
    virtual void shuffle();
    /**
    * Adds a card to the deck.
    * @param card the card to add.
    */

    void addCard(Card* card);

    /**
    * @return A card from the deck.
    */
    virtual Card* getCard();

    /**
    * Create a deck of the standard 52 cards.
    */
    virtual void createStandard();

    /**
    * @return The size of the deck.
    */
    virtual unsigned int size();

private:
    list<Card*> deck;

};

#endif // DECK_H
