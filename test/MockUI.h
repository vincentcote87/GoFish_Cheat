#ifndef MOCKUI_H_INCLUDED
#define MOCKUI_H_INCLUDED

#include "GameUI.h"

class MockUI : public GameUI
{

public:
    MockUI() {}
    virtual ~MockUI() {}

    MOCK_METHOD1(requestCard, unsigned int(list<Card*>*));
    MOCK_METHOD0(playFailed, void());
    MOCK_METHOD0(playSucceeded, void());
    MOCK_METHOD2(choosePlayer, unsigned int(unsigned int, unsigned int));
    MOCK_METHOD1(showScores, void(vector<Player*>));
    MOCK_METHOD1(currentFace, void(char));
    MOCK_METHOD1(playerName, void(Player*));
    MOCK_METHOD1(callCheat, unsigned int(vector<Player*> players));
    MOCK_METHOD0(noCardsPlayed, void());
};


#endif // MOCKUI_H_INCLUDED
