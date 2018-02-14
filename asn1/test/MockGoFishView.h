#ifndef MOCKGOFISHVIEW_H_INCLUDED
#define MOCKGOFISHVIEW_H_INCLUDED

#include <gmock/gmock.h>
#include "../include/GoFishView.h"

class MockGoFishView : public GoFishView
{
public:
    virtual ~MockGoFishView() {}

    MOCK_METHOD0(askForPlayerName, std::string());
    MOCK_METHOD0(nameAlreadyExists, void());
    MOCK_METHOD1(playerTurn, void(const std::string& name));
    MOCK_METHOD1(showHand, void(std::shared_ptr<StandardHand> hand));
    MOCK_METHOD0(askPlayerNameToTakeFrom, std::string());
    MOCK_METHOD0(invalidPlayerName, void());
    MOCK_METHOD0(enteredOwnName, void());
    MOCK_METHOD0(askForSuite, std::string());
    MOCK_METHOD0(askForValue, std::string());
    MOCK_METHOD1(invalidSuite, void(std::string& suite));
    MOCK_METHOD1(invalidValue, void(std::string& value));
    MOCK_METHOD1(playerHasA, void(bool has));
    MOCK_METHOD0(drawCard, void());
    MOCK_METHOD0(emptyDeck, void());
    MOCK_METHOD0(endTurn, void());
    MOCK_METHOD1(gameWon, void(std::string name));
};

#endif // MOCKGOFISHVIEW_H_INCLUDED
