#ifndef STANDARDPLAYER_H_INCLUDED
#define STANDARDPLAYER_H_INCLUDED

#include "Player.h"
#include "StandardHand.h"

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
    explicit StandardPlayer(const std::string& name);

    /**
     * Virtual destructor.
     */
    virtual ~StandardPlayer();

    /**
     * Gets the hand of the player.
     *
     * @return A shared pointer to the hand.
     */
    virtual std::shared_ptr<StandardHand> getHand();

    /**
     * Gets the name of the player.
     *
     * @return A string containing the name of the player.
     */
    virtual std::string getName() const;
private:
    /**
     * The name of the player.
     */
    const std::string _name;

    /**
     * A shared pointer to the hand of the player.
     */
    std::shared_ptr<StandardHand> _hand;
};

#endif // STANDARDPLAYER_H_INCLUDED
