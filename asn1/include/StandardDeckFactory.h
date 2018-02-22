#ifndef STANDARDDECKFACTORY_H_INCLUDED
#define STANDARDDECKFACTORY_H_INCLUDED

#include <memory>
#include "StandardDeck.h"

using std::shared_ptr;

/**
 * A factory class for creating new standard decks.
 */
class StandardDeckFactory
{
public:
    /**
     * Creates the factory.
     */
    StandardDeckFactory();

    /**
     * Virtual destructor.
     */
    virtual ~StandardDeckFactory() {}

    /**
     * Creates a new standard deck.
     *
     * @return A shared pointer to the newly created standard deck.
     */
    virtual shared_ptr<StandardDeck> createStandardDeck();
};

#endif // STANDARDDECKFACTORY_H_INCLUDED
