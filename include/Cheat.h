#ifndef CHEAT_H
#define CHEAT_H

#include <Game.h>
#include <map>

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
    void start();
    bool didLastCheat();


protected:
    unsigned int playerAsked = -1;

private:
    // bool firstMove = true;
    bool didCheat = false;
    map<int, char> face = {{1, 'A'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'},
                            {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, 'T'},
                            {11, 'J'}, {12, 'Q'}, {13, 'K'}};
    int currentFace = 0;
    vector<Card*> lastCardsPlayed;
    vector<Card*> discardPile;

};

#endif