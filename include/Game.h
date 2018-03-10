#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include "Card.h"
#include "Deck.h"
#include "GameUI.h"
#include "Player.h"

class Game
{

public:

    /**
    * Deal cards to the players.
    * @param p A list of players to deal the cards to.
    */

    virtual void dealCards(vector<Player*> p) = 0;
    /**
    * Allows a subclass to perform any actions before a card is played.
    * @param playerNum The index of the current player.
    * @param numPlayers the number of players in the game.
    */

    virtual void beforeCardPlayed(unsigned int playerNum, unsigned int numPlayers) = 0;

    /**
    * Allows a subclass to perform any actions after a card is played.
    * @param currentPlayer The current player.
    * @param players The players in the game.
    * @param played The card that was just played by the player.
    */
    virtual void afterCardPlayed(Player* currentPlayer, vector<Player*> players, Card* played) = 0;

    Game(GameUI* ui, Deck* d):deck(d),ui(ui) {};
    virtual ~Game() {}

    /**
    * @param c A card played.
    * @return If playing c was allowed.
    */
    virtual bool valid(Card* c);

    /**
    * @return Indicate if the game is finished.
    */
    virtual bool isOver() const;

    /**
    * @param p A player to add to the game.
    */

    void addPlayer(Player* p);

    /**
    * @return The players in the game.
    */
    vector<Player*> getPlayers();

    /**
    * Start playing the game.
    */
    virtual void start();



protected:
    vector<Player*> players;
    Deck* deck;
    GameUI* ui;
};

#endif // GAME_H_INCLUDED
