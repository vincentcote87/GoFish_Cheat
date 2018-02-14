#ifndef STANDARDCARD_H_INCLUDED
#define STANDARDCARD_H_INCLUDED

#include "Card.h"
#include "CardSuite.h"
#include "CardValue.h"

/**
 * An immutable class representing a standard card which uses CardSuite as the card
 * suite, and CardValue as the card value.
 */
class StandardCard : public Card<CardSuite, CardValue>
{
public:
    /**
     * Constructs a new StandardCard.
     *
     * @param suite The card suite.
     * @param value The card value.
     */
    StandardCard(const CardSuite suite, const CardValue value);

    /**
     * Virtual destructor.
     */
    virtual ~StandardCard();

    /**
     * Gets the suite of this card.
     *
     * @return The suite of this card.
     */
    virtual CardSuite getSuite() const;

    /**
     * Gets the value of this card.
     *
     * @return The value of this card.
     */
    virtual CardValue getValue() const;

    /**
     * Checks for equality of two standard cards. Compares the equality of the suites
     * returned by CardSuite#getSuite and the values returned by CardValue#getValue.
     *
     * @param card The card to compare against this card.
     *
     * @return True if this card equals <code>card</code>, false if not.
     */
    bool operator==(const StandardCard& card) const;

    /**
     * Checks for non-equality of two standard cards. Compares the non-equality of the
     * suites returned by CardSuite#getSuite and the values returned by CardValue#getValue.
     *
     * @param card The card to compare against this card.
     *
     * @return True if this card equals <code>card</code>, false if not.
     */
    bool operator!=(const StandardCard&) const;
private:
    /**
     * The card suite.
     */
    const CardSuite _suite;

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
