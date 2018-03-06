#include "gtest/gtest.h"
#include "Card.h"
#include "Player.h"

TEST (PlayerTest, getCard)
{
    Player* p = new Player("Bill");
    p->addCard(new Card(Card::CLUB, Card::ACE));
    p->addCard(new Card(Card::SPADE, Card::QUEEN));
    p->addCard(new Card(Card::DIAMOND, Card::SIX));

    EXPECT_EQ(Card::CLUB, p->getCard(0)->suit);
    EXPECT_EQ(Card::SPADE, p->getCard(1)->suit);
    EXPECT_EQ(Card::DIAMOND, p->getCard(2)->suit);
    EXPECT_THROW(p->getCard(3), hand_exception);
}
