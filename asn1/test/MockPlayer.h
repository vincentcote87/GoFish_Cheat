#ifndef MOCKPLAYER_H_INCLUDED
#define MOCKPLAYER_H_INCLUDED

#include <gmock/gmock.h>
#include "../include/StandardPlayer.h"

class MockPlayer : public StandardPlayer
{
public:
    virtual ~MockPlayer() {}

    MOCK_METHOD0(getHand, std::shared_ptr<StandardHand>());

    MOCK_CONST_METHOD0(getName, std::string());
};

#endif // MOCKPLAYER_H_INCLUDED
