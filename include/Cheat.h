#ifndef CHEAT_H
#define CHEAT_H

#include <Game.h>

class Cheat : public Game {
public:
    /**
    * A game of Go Fish.
    * @param ui The UI to use for communication.
    * @param d The card deck to use.
    */
    Cheat(GameUI* ui, Deck* d) : Game(ui, d) {}
    virtual ~Cheat() {}

    void dealCards(vector<Player*> p);
    void beforeCardPlayed(unsigned int playerNum, unsigned int numPlayers);
    void afterCardPlayed(Player* currentPlayer, vector<Player*> players, Card* played);

protected:
    unsigned int playerAsked = -1;

private:

};

#endif