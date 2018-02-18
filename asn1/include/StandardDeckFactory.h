#ifndef STANDARDDECKFACTORY_H_INCLUDED
#define STANDARDDECKFACTORY_H_INCLUDED

#include <memory>
#include "StandardDeck.h"

using std::shared_ptr;

class StandardDeckFactory
{
public:
    StandardDeckFactory();

    virtual ~StandardDeckFactory() {}

    virtual shared_ptr<StandardDeck> createStandardDeck();
};

#endif // STANDARDDECKFACTORY_H_INCLUDED
