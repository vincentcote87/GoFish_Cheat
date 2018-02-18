#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include "../include/StandardCard.h"
#include "../include/CardSuite.h"
#include "../include/CardValue.h"

using std::vector;
using std::unique_ptr;
using std::shared_ptr;

const vector<CardSuite> all_suites { CardSuite::CLUB, CardSuite::DIAMOND, CardSuite::HEART, CardSuite::SPADE };

const vector<CardValue> all_card_values { CardValue::ACE, CardValue::TWO, CardValue::THREE,
          CardValue::FOUR, CardValue::FIVE, CardValue::SIX, CardValue::SEVEN, CardValue::EIGHT,
          CardValue::NINE, CardValue::TEN, CardValue::JACK, CardValue::QUEEN, CardValue::KING };

/**
 * Tests to make sure all cards we construct return the expected suite and value.
 */
TEST(TestStandardCard, TestCardConstruction)
{
    for (const CardSuite suite : all_suites)
    {
        for (const CardValue value : all_card_values)
        {
            unique_ptr<StandardCard> card(new StandardCard(suite, value));

            EXPECT_EQ(suite, card->getSuite());
            EXPECT_EQ(value, card->getValue());

            card.reset();
        }
    }
}

/**
 * Tests to make sure two different card instances whom have the same suite and value
 * return that they are equal.
 */
TEST(TestStandardCard, TestSameCardsEqual)
{
    shared_ptr<StandardCard> card1(new StandardCard(CardSuite::CLUB, CardValue::ACE));
    shared_ptr<StandardCard> card2(new StandardCard(CardSuite::CLUB, CardValue::ACE));

    ASSERT_EQ(*card1, *card2);
}

/**
 * Tests to make sure two different card instances whom have the same suite, but different
 * values return that they are not equal.
 */
TEST(TestStandardCard, TestSameCardsNotEqual1)
{
    shared_ptr<StandardCard> card1(new StandardCard(CardSuite::CLUB, CardValue::ACE));
    shared_ptr<StandardCard> card2(new StandardCard(CardSuite::CLUB, CardValue::TWO));

    ASSERT_NE(*card1, *card2);
}

/**
 * Tests to make sure two different card instances whom have different suites, but the
 * same values return that they are not equal.
 *
 */
TEST(TestStandardCard, TestSameCardsNotEqual2)
{
    shared_ptr<StandardCard> card1(new StandardCard(CardSuite::CLUB, CardValue::ACE));
    shared_ptr<StandardCard> card2(new StandardCard(CardSuite::SPADE, CardValue::ACE));

    ASSERT_NE(*card1, *card2);
}

/**
 * Tests to make sure two different card instances whom have different suites and different
 * values return that they are not equal.
 *
 */
TEST(TestStandardCard, TestSameCardsNotEqual3)
{
    shared_ptr<StandardCard> card1(new StandardCard(CardSuite::CLUB, CardValue::ACE));
    shared_ptr<StandardCard> card2(new StandardCard(CardSuite::SPADE, CardValue::THREE));

    ASSERT_NE(*card1, *card2);
}
