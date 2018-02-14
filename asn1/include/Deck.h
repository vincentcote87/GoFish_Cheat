#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <memory>
#include "Card.h"

/**
 * A template interface representing a deck of cards (of class TCard).
 */
template<class TCard> class Deck
{
public:
    /**
     * Virtual destructor.
     */
    virtual ~Deck() {}

    /**
     * Shuffles the deck. The deck should not be empty if this is to be called.
     *
     * @throw EmptyDeckException Thrown if we try to shuffle an empty deck.
     */
    virtual void shuffle() = 0;

    /**
     * Determines if the deck is empty.
     *
     * @return True if empty, false if not.
     */
    virtual bool isEmpty() const = 0;

    /**
     * Determines the amount of cards in the deck.
     *
     * @return The amount of cards in the deck.
     */
    virtual unsigned int getCount() const = 0;

    /**
     * Puts a card on the top of a deck.
     *
     * @param card The card to put on the top of the deck.
     */
    virtual void pushTop(std::shared_ptr<TCard> card) = 0;

    /**
     * Draws a card from the top of a deck.
     *
     * @return The card which was drawn from the top of the deck.
     *
     * @throw EmptyDeckException If there are no cards available to be drawn.
     */
    virtual std::shared_ptr<TCard> popTop() = 0;

    /**
     * Peeks at the card from the top of a deck.
     *
     * @return The card on the top of the deck.
     *
     * @throw EmptyDeckException If there are no cards in the deck.
     */
    virtual std::shared_ptr<TCard> peekTop() const = 0;

    /**
     * Peeks at a desired card from the deck, based on the card's index.
     *
     * @param index The index of the card to peek at. Index <code>0</code> corresponds
     *              with the card at the bottom of the deck.
     *
     * @return The card at the specified index in the deck.
     *
     * @throw EmptyDeckException If the deck is empty.
     * @throw OutOfBoundsException If the deck is not empty, but the index is not in
     *        the range of the valid card indices.
     */
    virtual std::shared_ptr<TCard> peek(unsigned int index) const = 0;
};

#endif // DECK_H_INCLUDED
