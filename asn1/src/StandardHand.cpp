#include <iterator>
#include "../include/StandardHand.h"
#include "../include/EmptyHandException.h"
#include "../include/OutOfBoundsException.h"
#include "../include/ElementNotFoundException.h"
#include "../include/CardAlreadyInHandException.h"

StandardHand::StandardHand():_cardList(vector<shared_ptr<StandardCard>>())
{

}

StandardHand::~StandardHand()
{

}

bool StandardHand::isEmpty() const
{
    return this->_cardList.empty();
}

unsigned int StandardHand::getCount() const
{
    return this->_cardList.size();
}

shared_ptr<StandardCard> StandardHand::addCard(shared_ptr<StandardCard> card)
{
    if (isCardInHand(card))
    {
        throw CardAlreadyInHandException();
    }

    this->_cardList.push_back(card);

    return card;
}

shared_ptr<StandardCard> StandardHand::removeCard(unsigned int index)
{
    if (isEmpty())
    {
        throw EmptyHandException();
    }

    unsigned int count = getCount();

    if (index >= count)
    {
        throw OutOfBoundsException(index, 0, count);
    }

    shared_ptr<StandardCard> card = this->_cardList[index];

    this->_cardList.erase(this->_cardList.begin() + index);

    return card;
}

shared_ptr<StandardCard> StandardHand::removeCard(shared_ptr<StandardCard> card)
{
    if (isEmpty())
    {
        throw EmptyHandException();
    }

    for (vector<shared_ptr<StandardCard>>::iterator it = this->_cardList.begin();
        it != this->_cardList.end(); ++it)
    {
        shared_ptr<StandardCard> handCard = *it;

        if (*handCard == *card)
        {
            this->_cardList.erase(it);

            return handCard;
        }
    }

    throw ElementNotFoundException();
}

shared_ptr<StandardCard> StandardHand::getCard(unsigned int index) const
{
    if (isEmpty())
    {
        throw EmptyHandException();
    }

    unsigned int count = getCount();

    if (index >= count)
    {
        throw OutOfBoundsException(index, 0    , count);
    }

    return this->_cardList[index];
}

shared_ptr<StandardCard> StandardHand::getCard(shared_ptr<StandardCard> card) const
{
    if (isEmpty())
    {
        throw EmptyHandException();
    }

    for (vector<shared_ptr<StandardCard>>::const_iterator it = this->_cardList.cbegin();
        it != this->_cardList.cend(); ++it)
    {
        shared_ptr<StandardCard> handCard = *it;

        if (*handCard == *card)
        {
            return handCard;
        }
    }

    throw ElementNotFoundException();
}

bool StandardHand::containsCard(shared_ptr<StandardCard> card) const
{
    return isCardInHand(card);
}

bool StandardHand::isCardInHand(shared_ptr<StandardCard> card) const
{
    if (isEmpty())
    {
        return false;
    }

    for (unsigned int i = 0; i < getCount(); i++)
    {
        const shared_ptr<StandardCard> handCard = getCard(i);

        if (*card == *handCard)
            return true;
    }

    return false;
}
