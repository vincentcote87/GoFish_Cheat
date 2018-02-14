#include "../include/StandardCard.h"

StandardCard::StandardCard(const CardSuite suite, const CardValue value):_suite(suite),_value(value)
{

}

StandardCard::~StandardCard()
{

}

CardSuite StandardCard::getSuite() const
{
    return this->_suite;
}

CardValue StandardCard::getValue() const {
    return this->_value;
}

bool StandardCard::operator==(const StandardCard& card) const
{
    return getSuite() == card.getSuite() && getValue() == card.getValue();
}

bool StandardCard::operator!=(const StandardCard& card) const
{
    return !(operator==(card));
}
