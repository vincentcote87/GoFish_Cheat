#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>

using namespace std;

class Card
{

public:
    enum Suit {CLUB,DIAMOND,SPADE,HEART};
    enum Rank {ACE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING};

    Card(Suit s, Rank r):suit(s), rank(r) {}

    /**
    * @return a character representing the card's rank.
    */
    static char getRank(Card::Rank r);

    /**
    * @return a character representing the card's suit.
    */

    static char getSuit(Card::Suit s);


    const Suit suit;
    const Rank rank;
};


#endif // CARD_H_INCLUDED
