#ifndef MOCKSTANDARDDECKFACTORY_H_INCLUDED
#define MOCKSTANDARDDECKFACTORY_H_INCLUDED

#include <gmock/gmock.h>
#include "../include/StandardDeckFactory.h"

using std::shared_ptr;

class MockStandardDeckFactory : public StandardDeckFactory
{
public:
    virtual ~MockStandardDeckFactory() {}

    MOCK_METHOD0(createStandardDeck, shared_ptr<StandardDeck>());
};

#endif // MOCKSTANDARDDECKFACTORY_H_INCLUDED
