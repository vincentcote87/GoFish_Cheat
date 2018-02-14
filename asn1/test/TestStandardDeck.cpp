#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "TestStandardDeck.h"
#include "../include/StandardDeck.h"
#include "../include/CardAlreadyInDeckException.h"
#include "../include/EmptyDeckException.h"
#include "../include/OutOfBoundsException.h"

TestStandardDeck::TestStandardDeck(): ::testing::Test(),_deck(std::shared_ptr<StandardDeck>())
{
    SetUp();
}

TestStandardDeck::~TestStandardDeck()
{
    TearDown();
}

void TestStandardDeck::SetUp()
{
    this->_deck = std::shared_ptr<StandardDeck>(new StandardDeck());
}

void TestStandardDeck::TearDown()
{
    this->_deck.reset();
}

/**
 * Tests to make sure the new deck is not empty, when its expected to not be empty.
 */
TEST_F(TestStandardDeck, TestNonEmptyFullDeck)
{
    ASSERT_FALSE(_deck->isEmpty());
}

/**
 * Tests to make sure the new deck has 52 cards, meaning it's a full, standard deck.
 */
TEST_F(TestStandardDeck, TestFullDeckSize)
{
    ASSERT_EQ(_deck->getCount(), 52);
}

/**
 * Tests to make sure that we get a CardAlreadyInDeckException when we try to push
 * a new card to the top of a full, standard deck.
 */
TEST_F(TestStandardDeck, TestPushToFullDeck)
{
    std::shared_ptr<StandardCard> card = std::shared_ptr<StandardCard>
        (new StandardCard(CardSuite::CLUB, CardValue::EIGHT));

    ASSERT_THROW(_deck->pushTop(card), CardAlreadyInDeckException);

    card.reset();
}

/**
 * Tests to make sure that peeking at the top of a full, standard deck does not return
 * a null pointer.
 */
TEST_F(TestStandardDeck, TestPopValid)
{
    ASSERT_TRUE(_deck->popTop().get() != nullptr);
}

/**
 * Tests to make sure that when we draw a card which we just pushed to the top of
 * the deck, the drawn card is equal to the one we just recently pushed.
 */
TEST_F(TestStandardDeck, TestPopPushEqual)
{
    // Draw a card from the top of the deck
    std::shared_ptr<StandardCard> card = _deck->popTop();

    // Put it back on the top
    ASSERT_NO_THROW(_deck->pushTop(card));

    // Draw it again
    std::shared_ptr<StandardCard> card2 = _deck->popTop();

    // card and card2 should be equal

    ASSERT_EQ(*card, *card2);

    card.reset();
    card2.reset();
}

/**
 * Tests to make sure we can draw all cards from the deck without failing, and
 * that when we draw all the cards, StandardDeck#isEmpty() should return true.
 */
TEST_F(TestStandardDeck, TestPopAll)
{
    while (!_deck->isEmpty())
    {
        ASSERT_NO_THROW(_deck->popTop());
    }

    ASSERT_TRUE(_deck->isEmpty());
}

/**
 * Tests to make sure that when we try to draw a card from the top of an empty
 * deck that an EmptyDeckException is thrown.
 */
TEST_F(TestStandardDeck, TestEmptyDeckPop)
{
    while (!_deck->isEmpty())
    {
        ASSERT_NO_THROW(_deck->popTop());
    }

    ASSERT_THROW(_deck->popTop(), EmptyDeckException);
}

/**
 * Tests to make sure that the card we peek at at the top of the deck is not a
 * null pointer.
 */
TEST_F(TestStandardDeck, TestPeekTopValid)
{
    ASSERT_TRUE(_deck->peekTop().get() != nullptr);
}

/**
 * Tests to make sure that the card we peek at at the bottom of the deck is not
 * a null pointer.
 */
TEST_F(TestStandardDeck, TestPeekValid)
{
    ASSERT_TRUE(_deck->peek(0).get() != nullptr);
}

/**
 * Tests that we are able to peek at all the cards in a full deck without error.
 */
TEST_F(TestStandardDeck, TestValidPeek)
{
    unsigned int count = _deck->getCount();

    for (unsigned int i = 0; i < count; i++)
    {
        EXPECT_NO_THROW(_deck->peek(i));
    }
}

/**
 * Tests that when we try to peek at a card at an invalid index, that an
 * OutOfBoundsException is thrown.
 */
TEST_F(TestStandardDeck, TestInvalidPeek)
{
    unsigned int count = _deck->getCount();

    ASSERT_THROW(_deck->peek(count), OutOfBoundsException);
}

/**
 * Tests that when we try to peek at card at index 0 of an empty deck, an
 * EmptyDeckException is thrown.
 */
TEST_F(TestStandardDeck, TestEmptyDeckPeekIndexZero)
{
    while (!_deck->isEmpty())
    {
        _deck->popTop();
    }

    EXPECT_THROW(_deck->peek(0), EmptyDeckException);
}

/**
 * Tests that when we try to peek at card at the top of an empty deck, an
 * EmptyDeckException is thrown.
 */
TEST_F(TestStandardDeck, TestEmptyDeckPeek)
{
    while (!_deck->isEmpty())
    {
        _deck->popTop();
    }

    EXPECT_THROW(_deck->peekTop(), EmptyDeckException);
}

/**
 * Tests that the amount of cards in a deck is updated after we draw a card from
 * the top of the deck.
 */
TEST_F(TestStandardDeck, TestGetCountAfterPop)
{
    unsigned int count1 = _deck->getCount();

    _deck->popTop();

    ASSERT_EQ(count1, _deck->getCount() + 1);
}

/**
 * Tests that when we shuffle a non-empty deck, the ordering of the cards changes.
 */
TEST_F(TestStandardDeck, TestShuffle)
{
    std::vector<std::shared_ptr<StandardCard>> first_ordered;

    unsigned int count = _deck->getCount();

    for (unsigned int i = 0; i < count; i++)
    {
        ASSERT_NO_THROW(first_ordered.push_back(_deck->peek(i)));
    }

    _deck->shuffle();

    ASSERT_EQ(count, _deck->getCount());

    bool all_equal = true;

    for (unsigned int i = 0; i < count; i++)
    {
        if (*(_deck->peek(i)) != *(first_ordered[i]))
        {
            all_equal = false;

            break;
        }
    }

    ASSERT_FALSE(all_equal);
}

/**
 * Tests that when we try shuffling an empty deck, an EmptyDeckException is thrown.
 */
TEST_F(TestStandardDeck, TestEmptyDeckShuffle)
{
    while (!_deck->isEmpty())
    {
        _deck->popTop();
    }

    ASSERT_THROW(_deck->shuffle(), EmptyDeckException);
}
