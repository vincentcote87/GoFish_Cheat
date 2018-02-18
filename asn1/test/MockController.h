#ifndef MOCKCONTROLLER_H_INCLUDED
#define MOCKCONTROLLER_H_INCLUDED

#include <gmock/gmock.h>
#include "../include/GoFishController.h"

using std::list;
using std::string;
using std::shared_ptr;

class MockController : public GoFishController
{
public:
    virtual ~MockController() {}

    MOCK_METHOD1(setView, void(shared_ptr<GoFishView> view));
    MOCK_METHOD1(setStandardPlayerFactory, void(shared_ptr<StandardPlayerFactory>
        standardPlayerFactory));
    MOCK_METHOD1(setStandardDeckFactory, void(shared_ptr<StandardDeckFactory>
        standardDeckFactory));
    MOCK_METHOD0(play, void());
    MOCK_METHOD0(init, void());
    MOCK_METHOD0(deal, void());
    MOCK_CONST_METHOD0(requestNames, list<string>());
    MOCK_CONST_METHOD1(constructPlayers, list<shared_ptr<StandardPlayer>>(
        list<string> names));
    MOCK_CONST_METHOD0(hasGameEnded, bool());
    MOCK_METHOD0(getWinner, shared_ptr<StandardPlayer>());
    MOCK_METHOD1(playerTurn, void(shared_ptr<StandardPlayer> player));
    MOCK_METHOD2(isValidPlayer, bool(string currentPlayerName, string& name));
    MOCK_METHOD2(getCard, shared_ptr<StandardCard>(string& suite, string& value));
    MOCK_METHOD1(getPlayer, shared_ptr<StandardPlayer>(string& name));
    MOCK_METHOD1(isValidSuite, bool(string& suite));
    MOCK_METHOD1(isValidValue, bool(string& value));
};

#endif // MOCKCONTROLLER_H_INCLUDED
