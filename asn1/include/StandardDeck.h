#ifndef STANDARDDECK_H_INCLUDED
#define STANDARDDECK_H_INCLUDED

#include <deque>
#include "Deck.h"
#include "StandardCard.h"

using std::deque;
using std::shared_ptr;

/**
 * A class representing a deck of cards using StandardCard. The deck cannot
 * contain multiple cards of the same type (as in same suit and value). This
 * implicitly means the deck will never contain more than 52 cards while using
 * standard cards.
 */
class StandardDeck : public Deck<StandardCard>
{
public:
    /**
     * Constructs a new standard deck, containing 52 cards of the suits
     * spades, clubs, diamonds, and hearts. The card values contain all
     * standard card values (aces to kings).
     * </br></br>
     * The cards are not initially shuffled.
     */
    StandardDeck();

    /**
     * Virtual destructor.
     */
    virtual ~StandardDeck();

    /**
     * Randomly Shuffles the deck. The deck should not be empty if this is
     * to be called.
     *
     * @throw EmptyDeckException Thrown if we try to shuffle an empty deck.
     */
    virtual void shuffle();

    /**
     * Determines if the deck is empty or not.
     *
     * @return False if the deck is not empty, true if it is.
     */
    virtual bool isEmpty() const;

    /**
     * Determines the amount of cards in the deck.
     *
     * @return The amount of cards in the deck.
     */
    virtual unsigned int getCount() const;

    /**
     * Puts a card on the top of a deck. The <code>card</code> should not
     * already be in the deck.
     *
     * @param card The card to put on the top of the deck.
     *
     * @throw CardAlreadyInDeckException Thrown if we try to add a
     *        card to the deck which is already in there.
     */
    virtual void pushTop(shared_ptr<StandardCard> card);

    /**
     * Draws a card from the top of a deck.
     *
     * @return The card which was drawn from the top of the deck.
     *
     * @throw EmptyDeckException If there are no cards available to be drawn.
     */
    virtual shared_ptr<StandardCard> popTop();

    /**
     * Peeks at the card from the top of a deck.
     *
     * @return The card on the top of the deck.
     *
     * @throw EmptyDeckException If there are no cards in the deck.
     */
    virtual shared_ptr<StandardCard> peekTop() const;

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
    virtual shared_ptr<StandardCard> peek(unsigned int card) const;
protected:
    /**
     * Checks if a card is already in the deck.
     *
     * @param card The card we are looking for in the deck.
     *
     * @return True if the card is already in the deck, false if not.
     */
    virtual bool isCardInDeck(shared_ptr<StandardCard> card) const;
private:
    deque<shared_ptr<StandardCard>> _cardList;

    /**
     * Disables the copy constructor.
     */
    StandardDeck(const StandardDeck&);

    /**
     * Disables the copying of decks.
     */
    StandardDeck& operator=(const StandardDeck&);
};

#endif // STANDARDDECK_H_INCLUDED
