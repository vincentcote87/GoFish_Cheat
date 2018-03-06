#ifndef GOFISH_H
#define GOFISH_H

#include <Game.h>

class GoFish : public Game
{
public:
    /**
    * A game of Go Fish.
    * @param ui The UI to use for communication.
    * @param d The card deck to use.
    */
    GoFish(GameUI* ui, Deck* d) : Game(ui, d) {}
    virtual ~GoFish() {}

    void dealCards(vector<Player*> p);
    void beforeCardPlayed(unsigned int playerNum, unsigned int numPlayers);
    void afterCardPlayed(Player* currentPlayer, vector<Player*> players, Card* played);

    /**
    * @param hand A player's hand.
    * @return If the player has a set of cards.
    */
    bool hasSet(list<Card*>* hand);

protected:
    unsigned int playerAsked = -1;

private:
    const unsigned int NUM_CARDS_SMALL = 7;
    const unsigned int NUM_CARDS_LARGE = 5;

};

#endif // GOFISH_H
