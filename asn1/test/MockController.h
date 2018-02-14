#ifndef MOCKCONTROLLER_H_INCLUDED
#define MOCKCONTROLLER_H_INCLUDED

#include <gmock/gmock.h>
#include "../include/GoFishController.h"

class MockController : public GoFishController
{
public:
    virtual ~MockController() {}

    MOCK_METHOD1(setView, void(std::shared_ptr<GoFishView> view));
    MOCK_METHOD1(setStandardPlayerFactory, void(std::shared_ptr<StandardPlayerFactory>
        standardPlayerFactory));
    MOCK_METHOD1(setStandardDeckFactory, void(std::shared_ptr<StandardDeckFactory>
        standardDeckFactory));
    MOCK_METHOD0(play, void());
    MOCK_METHOD0(init, void());
    MOCK_METHOD0(deal, void());
    MOCK_CONST_METHOD0(requestNames, std::list<std::string>());
    MOCK_CONST_METHOD1(constructPlayers, std::list<std::shared_ptr<StandardPlayer>>(
        std::list<std::string> names));
    MOCK_CONST_METHOD0(hasGameEnded, bool());
    MOCK_METHOD0(getWinner, std::shared_ptr<StandardPlayer>());
    MOCK_METHOD1(playerTurn, void(std::shared_ptr<StandardPlayer> player));
    MOCK_METHOD2(isValidPlayer, bool(std::string currentPlayerName, std::string& name));
    MOCK_METHOD2(getCard, std::shared_ptr<StandardCard>(std::string& suite, std::string& value));
    MOCK_METHOD1(getPlayer, std::shared_ptr<StandardPlayer>(std::string& name));
    MOCK_METHOD1(isValidSuite, bool(std::string& suite));
    MOCK_METHOD1(isValidValue, bool(std::string& value));
};

#endif // MOCKCONTROLLER_H_INCLUDED
