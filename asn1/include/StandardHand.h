#ifndef STANDARDHAND_H_INCLUDED
#define STANDARDHAND_H_INCLUDED

#include <vector>
#include "Hand.h"
#include "StandardCard.h"

using std::vector;
using std::shared_ptr;

/**
 * A class representing a hand of standard cards.
 */
class StandardHand : public Hand<StandardCard>
{
public:
    /**
     * Constructs a new standard hand containing no initial cards.
     */
    StandardHand();

    /**
     * Virtual destructor.
     */
    virtual ~StandardHand();

    /**
     * Determines if the hand is empty.
     *
     * @return True if empty, false if not.
     */
    virtual bool isEmpty() const;

    /**
     * Determines the amount of cards in the hand.
     *
     * @return The amount of cards in the hand.
     */
    virtual unsigned int getCount() const;

    /**
     * Adds a card to the hand.
     *
     * @param card The card to add.
     *
     * @return The same card which has been added (<code>card</code).
     *
     * @throw CardAlreadyInHandException If <code>card</code> is already in the hand.
     */
    virtual shared_ptr<StandardCard> add(shared_ptr<StandardCard> card);

    /**
     * Removes a card at index <code>index</code>.
     *
     * @param index The index of the card.
     *
     * @return The card which has been removed.
     *
     * @throw EmptyHandException If the hand is empty.
     * @throw OutOfBoundsException If the <code>index</code> is out of range.
     */
    virtual shared_ptr<StandardCard> remove(unsigned int index);

    /**
     * Removes <code>card</code> from the hand.
     *
     * @param card The card to remove.
     *
     * @return The removed card.
     *
     * @throw EmptyHandException If the hand is empty.
     * @throw ElementNotFoundException If the card is not in the hand.
     */
    virtual shared_ptr<StandardCard> remove(shared_ptr<StandardCard> card);

    /**
     * Gets a card at index <code>index</code>.
     *
     * @param index The index of the card.
     *
     * @return The card at <code>index</code>.
     *
     * @throw EmptyHandException If the hand is empty.
     * @throw OutOfBoundsException If the <code>index</code> is out of range.
     */
    virtual shared_ptr<StandardCard> get(unsigned int index) const;

    /**
     * Gets <code>card</code> from the hand.
     *
     * @param card The card to get.
     *
     * @return The card.
     *
     * @throw EmptyHandException If the hand is empty.
     * @throw ElementNotFoundException If <code>card</code> is not in the hand.
     *
     */
    virtual shared_ptr<StandardCard> get(shared_ptr<StandardCard> card) const;

    /**
     * Determines if the hand contains <code>card</code>.
     *
     * @param card The card to check for.
     *
     * @return bool True if the hand contains the card, false if not.
     */
    virtual bool contains(shared_ptr<StandardCard> card) const;
protected:
    /**
     * Checks if a card is already in the hand.
     *
     * @param card The card we are looking for in the hand.
     *
     * @return True if the card is already in the hand, false if not.
     */
    virtual bool isCardInHand(shared_ptr<StandardCard> card) const;
private:
    /**
     * A vector of the cards in the hand.
     */
    vector<shared_ptr<StandardCard>> _cardList;
};

#endif // STANDARDHAND_H_INCLUDED
