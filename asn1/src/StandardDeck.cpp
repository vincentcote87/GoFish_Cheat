#include <vector>
#include <algorithm>
#include "../include/StandardDeck.h"
#include "../include/EmptyDeckException.h"
#include "../include/OutOfBoundsException.h"
#include "../include/CardAlreadyInDeckException.h"

using std::vector;

const vector<CardSuit> all_suits { CardSuit::CLUB, CardSuit::DIAMOND, CardSuit::HEART, CardSuit::SPADE };

const vector<CardValue> all_card_values { CardValue::ACE, CardValue::TWO, CardValue::THREE,
          CardValue::FOUR, CardValue::FIVE, CardValue::SIX, CardValue::SEVEN, CardValue::EIGHT,
          CardValue::NINE, CardValue::TEN, CardValue::JACK, CardValue::QUEEN, CardValue::KING };

StandardDeck::StandardDeck():_cardList(deque<shared_ptr<StandardCard>>())
{
    for (CardSuit suit : all_suits)
    {
        for (CardValue value : all_card_values)
        {
            pushTop(shared_ptr<StandardCard>(new StandardCard(suit, value)));
        }
    }
}

StandardDeck::~StandardDeck()
{
    this->_cardList.clear();
}

void StandardDeck::shuffle()
{
    if (isEmpty())
    {
        throw EmptyDeckException();
    }

    random_shuffle(_cardList.begin(), _cardList.end());
}

bool StandardDeck::isEmpty() const
{
    return this->_cardList.empty();
}

unsigned int StandardDeck::getCount() const
{
    return static_cast<unsigned int>(this->_cardList.size());
}

bool StandardDeck::isCardInDeck(shared_ptr<StandardCard> card) const
{
    if (isEmpty())
    {
        return false;
    }

    for (unsigned int i = 0; i < getCount(); i++)
    {
        const shared_ptr<StandardCard> deckCard = peek(i);

        if (*card == *deckCard)
            return true;
    }

    return false;
}

void StandardDeck::pushTop(shared_ptr<StandardCard> card)
{
    if (isCardInDeck(card))
    {
        throw CardAlreadyInDeckException();
    }

    this->_cardList.push_back(card);
}

shared_ptr<StandardCard> StandardDeck::popTop()
{
    if (isEmpty())
    {
        throw EmptyDeckException();
    }

    shared_ptr<StandardCard> top = this->_cardList.back();

    this->_cardList.pop_back();

    return top;
}

shared_ptr<StandardCard> StandardDeck::peekTop() const
{
    if (isEmpty())
    {
        throw EmptyDeckException();
    }

    return this->_cardList.back();
}

shared_ptr<StandardCard> StandardDeck::peek(unsigned int index) const
{
    if (isEmpty())
    {
        throw EmptyDeckException();
    }

    if (index >= getCount())
    {
        throw OutOfBoundsException(index, 0, getCount());
    }

    return this->_cardList[index];
}
