#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include <string>
#include <list>
#include "Card.h"
#include "Exceptions.h"

class Player
{
    public:
        explicit Player(const string& n) : name(n) {}
        virtual ~Player() {}

        /**
        * Add a card to the player's hand
        * @param c the card to be added
        */
        void addCard(Card* c);

        /**
        * Get a card from the player's hand
        * @param index the index of the card to get
        * @exception hand_exception if the card cannot be returned
        */
        Card* getCard(unsigned int index);

        /**
        * Get the player's hand
        */
        list<Card*>* getHand();

        /**
        * Add points to the player's score
        * @param points the number of points to add
        */
        void addPoints(unsigned int points);

        /**
        * Get the player's score
        */
        unsigned int getScore();

        /**
        * Name of the player
        */
        const string name;

    private:
        list<Card*> hand;
        unsigned int score = 0;
};

#endif // PLAYER_H
