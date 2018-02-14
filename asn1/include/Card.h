#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

/**
 * A template interface representing a card.
 */
template<class TCardSuite, class TCardValue> class Card
{
public:
    /**
     * Virtual destructor.
     */
    virtual ~Card() {};

    /**
     * Gets the suite of the card.
     *
     * @return The suite of the card.
     */
    virtual TCardSuite getSuite() const = 0;

    /**
     * Gets the value of the card.
     *
     * @return The value of the card.
     */
    virtual TCardValue getValue() const = 0;
};

#endif // CARD_H_INCLUDED
