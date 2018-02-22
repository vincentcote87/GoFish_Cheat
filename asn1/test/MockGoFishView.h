#ifndef MOCKGOFISHVIEW_H_INCLUDED
#define MOCKGOFISHVIEW_H_INCLUDED

#include <gmock/gmock.h>
#include "../include/GoFishView.h"

using std::string;
using std::shared_ptr;

class MockGoFishView : public GoFishView
{
public:
    virtual ~MockGoFishView() {}

    MOCK_METHOD0(askForPlayerName, string());
    MOCK_METHOD0(nameAlreadyExists, void());
    MOCK_METHOD1(playerTurn, void(const string& name));
    MOCK_METHOD1(showHand, void(shared_ptr<StandardHand> hand));
    MOCK_METHOD0(askPlayerNameToTakeFrom, string());
    MOCK_METHOD0(invalidPlayerName, void());
    MOCK_METHOD0(enteredOwnName, void());
    MOCK_METHOD0(askForSuit, string());
    MOCK_METHOD0(askForValue, string());
    MOCK_METHOD1(invalidSuit, void(string& suit));
    MOCK_METHOD1(invalidValue, void(string& value));
    MOCK_METHOD1(playerHasA, void(bool has));
    MOCK_METHOD0(drawCard, void());
    MOCK_METHOD0(emptyDeck, void());
    MOCK_METHOD0(endTurn, void());
    MOCK_METHOD1(gameWon, void(string name));
};

#endif // MOCKGOFISHVIEW_H_INCLUDED
