#ifndef MOCKSTANDARDPLAYERFACTORY_H_INCLUDED
#define MOCKSTANDARDPLAYERFACTORY_H_INCLUDED

#include <gmock/gmock.h>
#include "../include/StandardPlayerFactory.h"

class MockStandardPlayerFactory : public StandardPlayerFactory
{
public:
    virtual ~MockStandardPlayerFactory() {}

    MOCK_METHOD1(createPlayer, std::shared_ptr<StandardPlayer>(std::string));
};

#endif // MOCKSTANDARDPLAYERFACTORY_H_INCLUDED
