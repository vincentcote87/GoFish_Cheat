#ifndef MOCKDECK_H_INCLUDED
#define MOCKDECK_H_INCLUDED

#include <gmock/gmock.h>
#include "../include/StandardDeck.h"

class MockDeck : public StandardDeck
{
public:
    virtual ~MockDeck() {}

    MOCK_METHOD0(shuffle, void());
    MOCK_CONST_METHOD0(isEmpty, bool());
    MOCK_CONST_METHOD0(getCount, unsigned int());
    MOCK_METHOD1(pushTop, void(std::shared_ptr<StandardCard> card));
    MOCK_METHOD0(popTop, std::shared_ptr<StandardCard>());
    MOCK_CONST_METHOD0(peekTop, std::shared_ptr<StandardCard>());
    MOCK_CONST_METHOD1(peek, std::shared_ptr<StandardCard>(unsigned int card));
    MOCK_CONST_METHOD1(isCardInDeck, bool(std::shared_ptr<StandardCard>));
};

#endif // MOCKDECK_H_INCLUDED
