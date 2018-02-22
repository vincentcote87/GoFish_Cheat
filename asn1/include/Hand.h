#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED

#include <memory>
#include "Card.h"

using std::shared_ptr;

/**
 * A template interface representing a hand of cards (of class TCard).
 */
template<class TCard> class Hand
{
public:
    /**
     * Virtual destructor.
     */
    virtual ~Hand() {}

    /**
     * Determines if the hand is empty.
     *
     * @return True if empty, false if not.
     */
    virtual bool isEmpty() const = 0;

    /**
     * Determines the amount of cards in the hand.
     *
     * @return The amount of cards in the hand.
     */
    virtual unsigned int getCount() const = 0;

    /**
     * Adds a card to the hand.
     *
     * @param card The card to add.
     */
    virtual shared_ptr<TCard> addCard(shared_ptr<TCard> card) = 0;

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
    virtual shared_ptr<TCard> removeCard(unsigned int index) = 0;

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
    virtual shared_ptr<TCard> removeCard(shared_ptr<TCard> card) = 0;

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
    virtual shared_ptr<TCard> getCard(unsigned int index) const = 0;

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
    virtual shared_ptr<TCard> getCard(shared_ptr<TCard> card) const = 0;

    /**
     * Determines if the hand contains <code>card</code>.
     *
     * @param card The card to check for.
     *
     * @return bool True if the hand contains the card, false if not.
     */
    virtual bool containsCard(shared_ptr<TCard> card) const = 0;
};

#endif // HAND_H_INCLUDED
