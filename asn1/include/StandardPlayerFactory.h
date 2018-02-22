#ifndef STANDARDPLAYERFACTORY_H_INCLUDED
#define STANDARDPLAYERFACTORY_H_INCLUDED

#include <memory>
#include <string>
#include "StandardPlayer.h"

using std::string;
using std::shared_ptr;

/**
 * A factory class for creating new standard players.
 */
class StandardPlayerFactory
{
public:
    /**
     * Creates the factory.
     */
    StandardPlayerFactory();

    /**
     * Virtual destructor.
     */
    virtual ~StandardPlayerFactory() {};

    /**
     * Creates a new standard player.
     *
     * @param name The name of the new player.
     *
     * @return A shared pointer to the newly created standard player.
     */
    virtual shared_ptr<StandardPlayer> createStandardPlayer(string name);
};

#endif // STANDARDPLAYERFACTORY_H_INCLUDED
