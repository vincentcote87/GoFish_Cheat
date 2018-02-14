#ifndef STANDARDDECKFACTORY_H_INCLUDED
#define STANDARDDECKFACTORY_H_INCLUDED

#include <memory>
#include "StandardDeck.h"

class StandardDeckFactory
{
public:
    StandardDeckFactory();

    virtual ~StandardDeckFactory() {}

    virtual std::shared_ptr<StandardDeck> createStandardDeck();
};

#endif // STANDARDDECKFACTORY_H_INCLUDED
