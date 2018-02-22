#ifndef STANDARDPLAYER_H_INCLUDED
#define STANDARDPLAYER_H_INCLUDED

#include "Player.h"
#include "StandardHand.h"

using std::string;
using std::shared_ptr;

/**
 * A class representing a standard player whose hand can contain standard cards.
 */
class StandardPlayer : public Player<StandardHand>
{
public:
    /**
     * Constructs a new StandardPlayer. Initializes the hand to contain no cards.
     *
     * @name The name of the player.
     */
    explicit StandardPlayer(const string& name);

    /**
     * Virtual destructor.
     */
    virtual ~StandardPlayer();

    /**
     * Gets the hand of the player.
     *
     * @return A shared pointer to the hand.
     */
    virtual shared_ptr<StandardHand> getHand();

    /**
     * Gets the name of the player.
     *
     * @return A string containing the name of the player.
     */
    virtual string getName() const;
private:
    /**
     * The name of the player.
     */
    const string _name;

    /**
     * A shared pointer to the hand of the player.
     */
    shared_ptr<StandardHand> _hand;
};

#endif // STANDARDPLAYER_H_INCLUDED
