#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

/**
 * A template interface representing a card.
 */
template<class TCardSuit, class TCardValue> class Card
{
public:
    /**
     * Virtual destructor.
     */
    virtual ~Card() {};

    /**
     * Gets the suit of the card.
     *
     * @return The suit of the card.
     */
    virtual TCardSuit getSuit() const = 0;

    /**
     * Gets the value of the card.
     *
     * @return The value of the card.
     */
    virtual TCardValue getValue() const = 0;
};

#endif // CARD_H_INCLUDED
