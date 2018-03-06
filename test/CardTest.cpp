#include "gtest/gtest.h"
#include "Card.h"

TEST (CardTest, RankText)
{
    EXPECT_EQ('A', Card::getRank(Card::ACE));
    EXPECT_EQ('2', Card::getRank(Card::TWO));
    EXPECT_EQ('3', Card::getRank(Card::THREE));
    EXPECT_EQ('4', Card::getRank(Card::FOUR));
    EXPECT_EQ('5', Card::getRank(Card::FIVE));
    EXPECT_EQ('6', Card::getRank(Card::SIX));
    EXPECT_EQ('7', Card::getRank(Card::SEVEN));
    EXPECT_EQ('8', Card::getRank(Card::EIGHT));
    EXPECT_EQ('9', Card::getRank(Card::NINE));
    EXPECT_EQ('T', Card::getRank(Card::TEN));
    EXPECT_EQ('J', Card::getRank(Card::JACK));
    EXPECT_EQ('Q', Card::getRank(Card::QUEEN));
    EXPECT_EQ('K', Card::getRank(Card::KING));
}

TEST (CardTest, SuitText)
{
    EXPECT_EQ('C', Card::getSuit(Card::CLUB));
    EXPECT_EQ('S', Card::getSuit(Card::SPADE));
    EXPECT_EQ('D', Card::getSuit(Card::DIAMOND));
    EXPECT_EQ('H', Card::getSuit(Card::HEART));
}


