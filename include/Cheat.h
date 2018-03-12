#ifndef CHEAT_H
#define CHEAT_H

#include <Game.h>
#include <map>

class Cheat : public Game {
public:
    /**
    * A game of Cheat.
    * @param ui The UI to use for communication.
    * @param d The card deck to use.
    */
    Cheat(GameUI* ui, Deck* d) : Game(ui, d) {}
    virtual ~Cheat() {}

    /**
    *Deal cards to the players
    *@param a vector of players to deal cards to
    */
    void dealCards(vector<Player*> p);

    /**
    *Actions done before a card is played
    *@param playerNum The index of the current player.
    *@param numPlayers the number of players in the game.
    */
    void beforeCardPlayed(unsigned int playerNum, unsigned int numPlayers);

    /**
    *Actions done after a card is played
    *@param currentPlayer The current player.
    *@param players The players in the game.
    *@param played The card that was just played by the player.
    */
    void afterCardPlayed(Player* currentPlayer, vector<Player*> players, Card* played);

    /**
    *Initialize and runs the game
    */
    void start();

    /**
    *Looks to see if last player who played cheated
    *@return true or fale if they cheated
    */
    bool didLastCheat();


protected:
    unsigned int playerAsked = -1;

private:
    bool didCheat = false;
    map<int, char> face = {{1, 'A'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'},
                            {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, 'T'},
                            {11, 'J'}, {12, 'Q'}, {13, 'K'}};
    int currentFace = 0;
    vector<Card*> lastCardsPlayed;
    vector<Card*> discardPile;

};

#endif