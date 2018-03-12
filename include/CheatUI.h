#ifndef CHEATUI_H
#define CHEATUI_H

#include "GameUI.h"
#include "Card.h"

class CheatUI : public GameUI {
public:
    CheatUI() {}
    ~CheatUI() {}

	/**
    *Ask a player for a card.
    *@param hand A card played.
    *@return The index of the card selected.
    */
    unsigned int requestCard(list<Card*>* hand);

    /**
    *Response when the player's turn was not successful.
    */
    void playFailed();

    /**
    *Response when the player's turn was successful.
    */
    void playSucceeded();
};

#endif 
