#ifndef GOFISHVIEW_H_INCLUDED
#define GOFISHVIEW_H_INCLUDED

#include <string>
#include <memory>
#include "StandardHand.h"

class GoFishView
{
public:
    GoFishView();

    virtual ~GoFishView();

    std::string askForPlayerName();

    void nameAlreadyExists();

    void playerTurn(const std::string& name);

    void showHand(std::shared_ptr<StandardHand> hand);

    std::string askPlayerNameToTakeFrom();

    void invalidPlayerName();

    void enteredOwnName();

    std::string askForSuite();

    std::string askForValue();

    void invalidSuite(std::string& suite);

    void invalidValue(std::string& value);

    void playerHasA(bool has);

    void drawCard();

    void emptyDeck();

    void endTurn();

    void gameWon(std::string name);
private:
    void printCard(std::shared_ptr<StandardCard> card);
};

#endif // GOFISHVIEW_H_INCLUDED
