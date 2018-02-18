#include "../include/StandardCard.h"

StandardCard::StandardCard(const CardSuit suit, const CardValue value):_suit(suit),_value(value)
{

}

StandardCard::~StandardCard()
{

}

CardSuit StandardCard::getSuit() const
{
    return this->_suit;
}

CardValue StandardCard::getValue() const {
    return this->_value;
}

bool StandardCard::operator==(const StandardCard& card) const
{
    return getSuit() == card.getSuit() && getValue() == card.getValue();
}

bool StandardCard::operator!=(const StandardCard& card) const
{
    return !(operator==(card));
}
