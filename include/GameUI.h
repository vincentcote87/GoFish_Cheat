#ifndef GAMEUI_H_INCLUDED
#define GAMEUI_H_INCLUDED

#include <list>
#include <vector>
#include <typeinfo>
#include "Card.h"
#include "Player.h"

using namespace std;

class GameUI
{

public:
    GameUI(){}
    virtual ~GameUI() {}

    /**
    * Ask a player for a card.
    * @param hand A card played.
    * @return The index of the card selected.
    */
    virtual unsigned int requestCard(list<Card*>* hand) = 0;

    /**
    * @return Response when the player's turn was not successful.
    */
    virtual void playFailed() = 0;

    /**
    * @return Response when the player's turn was successful.
    */
    virtual void playSucceeded() = 0;

    /**
    * Ask a player to select another player.
    * @param playerNum Index of the current player.
    * @param numPlayers The total number of players.
    * @return The index of the chosen player.
    */
    virtual unsigned int choosePlayer(unsigned int playerNum, unsigned int numPlayers);

    /**
    * Show the scores of the players.
    * @param players The players.
    */
    virtual void showScores(vector<Player*> players);

    /**
    * Output which face value is needed for a round
    * @param a character representing a face value
    */
    virtual void currentFace(char face);

    /**
    * Output the name of a player
    * @param a Player pointer
    */
    virtual void playerName(Player* player);

    /**
    * Prompts users if they want to call cheat after each player takes a turn
    * @param a vector of current Players in the game
    */
    virtual unsigned int callCheat(vector<Player*> players);

    /**
    * Output a message telling the player he must discard at least one card
    */
    virtual void noCardsPlayed();

    /**
    * Output a representation of a card.
    * @param os The output stream.
    * @param c The card to represent.
    */
    friend ostream& operator<<(ostream& os, const Card& c);
};

#endif // GAMEUI_H_INCLUDED
