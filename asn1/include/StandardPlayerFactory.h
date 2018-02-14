#ifndef STANDARDPLAYERFACTORY_H_INCLUDED
#define STANDARDPLAYERFACTORY_H_INCLUDED

#include <memory>
#include <string>
#include "StandardPlayer.h"

class StandardPlayerFactory
{
public:
    StandardPlayerFactory();

    virtual ~StandardPlayerFactory() {};

    virtual std::shared_ptr<StandardPlayer> createPlayer(std::string name);
};

#endif // STANDARDPLAYERFACTORY_H_INCLUDED
