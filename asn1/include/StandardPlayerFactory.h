#ifndef STANDARDPLAYERFACTORY_H_INCLUDED
#define STANDARDPLAYERFACTORY_H_INCLUDED

#include <memory>
#include <string>
#include "StandardPlayer.h"

using std::string;
using std::shared_ptr;

class StandardPlayerFactory
{
public:
    StandardPlayerFactory();

    virtual ~StandardPlayerFactory() {};

    virtual shared_ptr<StandardPlayer> createPlayer(string name);
};

#endif // STANDARDPLAYERFACTORY_H_INCLUDED
