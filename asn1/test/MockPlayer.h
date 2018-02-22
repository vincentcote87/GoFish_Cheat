#ifndef MOCKPLAYER_H_INCLUDED
#define MOCKPLAYER_H_INCLUDED

#include <gmock/gmock.h>
#include "../include/StandardPlayer.h"

using std::string;
using std::shared_ptr;

class MockPlayer : public StandardPlayer
{
public:
    virtual ~MockPlayer() {}

    MOCK_METHOD0(getHand, shared_ptr<StandardHand>());

    MOCK_CONST_METHOD0(getName, string());
};

#endif // MOCKPLAYER_H_INCLUDED
