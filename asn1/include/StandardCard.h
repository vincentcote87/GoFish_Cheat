#ifndef STANDARDCARD_H_INCLUDED
#define STANDARDCARD_H_INCLUDED

#include "Card.h"
#include "CardSuit.h"
#include "CardValue.h"

/**
 * An immutable class representing a standard card which uses CardSuit as the card
 * suit, and CardValue as the card value.
 */
class StandardCard : public Card<CardSuit, CardValue>
{
public:
    /**
     * Constructs a new StandardCard.
     *
     * @param suit The card suit.
     * @param value The card value.
     */
    StandardCard(const CardSuit suit, const CardValue value);

    /**
     * Virtual destructor.
     */
    virtual ~StandardCard();

    /**
     * Gets the suit of this card.
     *
     * @return The suit of this card.
     */
    virtual CardSuit getSuit() const;

    /**
     * Gets the value of this card.
     *
     * @return The value of this card.
     */
    virtual CardValue getValue() const;

    /**
     * Checks for equality of two standard cards. Compares the equality of the suits
     * returned by CardSuit#getSuit and the values returned by CardValue#getValue.
     *
     * @param card The card to compare against this card.
     *
     * @return True if this card equals <code>card</code>, false if not.
     */
    bool operator==(const StandardCard& card) const;

    /**
     * Checks for non-equality of two standard cards. Compares the non-equality of the
     * suits returned by CardSuit#getSuit and the values returned by CardValue#getValue.
     *
     * @param card The card to compare against this card.
     *
     * @return True if this card equals <code>card</code>, false if not.
     */
    bool operator!=(const StandardCard&) const;
private:
    /**
     * The card suit.
     */
    const CardSuit _suit;

    /**
     * The card value.
     */
    const CardValue _value;

    /**
     * Copy constructor, which is being disabled.
     */
    StandardCard(const StandardCard&);

    /**
     * Disables copying of standard cards.
     */
    StandardCard& operator=(const StandardCard&);
};

#endif // STANDARDCARD_H_INCLUDED
