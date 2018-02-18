#ifndef MOCKSTANDARDPLAYERFACTORY_H_INCLUDED
#define MOCKSTANDARDPLAYERFACTORY_H_INCLUDED

#include <gmock/gmock.h>
#include "../include/StandardPlayerFactory.h"

using std::string;
using std::shared_ptr;

class MockStandardPlayerFactory : public StandardPlayerFactory
{
public:
    virtual ~MockStandardPlayerFactory() {}

    MOCK_METHOD1(createStandardPlayer, shared_ptr<StandardPlayer>(string));
};

#endif // MOCKSTANDARDPLAYERFACTORY_H_INCLUDED
