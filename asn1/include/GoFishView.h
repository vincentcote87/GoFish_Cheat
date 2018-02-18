#ifndef GOFISHVIEW_H_INCLUDED
#define GOFISHVIEW_H_INCLUDED

#include <string>
#include <memory>
#include "StandardHand.h"

using std::string;
using std::shared_ptr;

class GoFishView
{
public:
    GoFishView();

    virtual ~GoFishView();

    string askForPlayerName();

    void nameAlreadyExists();

    void playerTurn(const string& name);

    void showHand(shared_ptr<StandardHand> hand);

    string askPlayerNameToTakeFrom();

    void invalidPlayerName();

    void enteredOwnName();

    string askForSuit();

    string askForValue();

    void invalidSuit(string& suit);

    void invalidValue(string& value);

    void playerHasA(bool has);

    void drawCard();

    void emptyDeck();

    void endTurn();

    void gameWon(string name);
private:
    void printCard(shared_ptr<StandardCard> card);
};

#endif // GOFISHVIEW_H_INCLUDED
