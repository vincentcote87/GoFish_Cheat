#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <memory>
#include <string>
#include "Card.h"
#include "Hand.h"

using std::string;
using std::shared_ptr;

/**
 * A template class representing a card game player.
 */
template<class THand> class Player
{
public:
    /**
     * Virtual destructor.
     */
    virtual ~Player() {}

    /**
     * Gets the hand of the player.
     *
     * @return The hand.
     */
    virtual shared_ptr<THand> getHand() = 0;

    /**
     * Gets the name of the player.
     *
     * @return A string of the name of the player.
     */
    virtual string getName() const = 0;
};

#endif // PLAYER_H_INCLUDED
