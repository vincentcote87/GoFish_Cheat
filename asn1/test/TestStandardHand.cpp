#include <gtest/gtest.h>
#include <memory>
#include "TestStandardHand.h"
#include "../include/CardAlreadyInHandException.h"
#include "../include/EmptyHandException.h"
#include "../include/OutOfBoundsException.h"
#include "../include/ElementNotFoundException.h"

TestStandardHand::TestStandardHand(): ::testing::Test(),_hand(shared_ptr<StandardHand>()),_ace_hearts(
    shared_ptr<StandardCard>()),_ace_spades(shared_ptr<StandardCard>())
{
    SetUp();
}

TestStandardHand::~TestStandardHand()
{
    TearDown();
}

void TestStandardHand::SetUp()
{
    this->_hand = shared_ptr<StandardHand>(new StandardHand());

    this->_ace_hearts = shared_ptr<StandardCard>(new StandardCard(
        CardSuit::HEART, CardValue::ACE));
    this->_ace_spades = shared_ptr<StandardCard>(new StandardCard(
        CardSuit::SPADE, CardValue::ACE));
}

void TestStandardHand::TearDown()
{
    this->_hand.reset();
}

TEST_F(TestStandardHand, HandStartsEmpty)
{
    ASSERT_TRUE(this->_hand->isEmpty());
}

TEST_F(TestStandardHand, TestIsEmpty)
{
    while (!this->_hand->isEmpty())
    {
        this->_hand->removeCard(0);
    }

    ASSERT_TRUE(this->_hand->isEmpty());
}

TEST_F(TestStandardHand, TestNotIsEmpty)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_FALSE(this->_hand->isEmpty());
}

TEST_F(TestStandardHand, TestEmpyGetCount)
{
    ASSERT_EQ(this->_hand->getCount(), 0);
}

TEST_F(TestStandardHand, TestAddGetCount)
{
    unsigned int count = this->_hand->getCount();

    this->_hand->addCard(this->_ace_hearts);

    ASSERT_EQ(count + 1, this->_hand->getCount());
}

TEST_F(TestStandardHand, TestAddRemoveGetCount)
{
    this->_hand->addCard(this->_ace_hearts);

    unsigned int count = this->_hand->getCount();

    this->_hand->removeCard(0);

    ASSERT_EQ(count - 1, this->_hand->getCount());
}

TEST_F(TestStandardHand, TestAdd)
{
    shared_ptr<StandardCard> card = this->_hand->addCard(this->_ace_hearts);

    ASSERT_EQ(*card, *(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestAddSameCard)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_THROW(this->_hand->addCard(this->_ace_hearts), CardAlreadyInHandException);
}

TEST_F(TestStandardHand, TestAddDiffCards)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_NO_THROW(this->_hand->addCard(this->_ace_spades));
}

TEST_F(TestStandardHand, TestRemoveIndex)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_EQ(*(this->_hand->removeCard(0)), *(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestRemoveCard)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_EQ(*(this->_hand->removeCard(this->_ace_hearts)), *(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestRemoveIndexEmpty)
{
    ASSERT_THROW(this->_hand->removeCard(0), EmptyHandException);
}

TEST_F(TestStandardHand, TestRemoveCardEmpty)
{
    ASSERT_THROW(this->_hand->removeCard(this->_ace_hearts), EmptyHandException);
}

TEST_F(TestStandardHand, TestRemoveNoSuchCard)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_THROW(this->_hand->removeCard(this->_ace_spades), ElementNotFoundException);
}

TEST_F(TestStandardHand, TestRemoveBadIndex)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_THROW(this->_hand->removeCard(1), OutOfBoundsException);
}

TEST_F(TestStandardHand, TestGetIndexEmpty)
{
    ASSERT_THROW(this->_hand->getCard(0), EmptyHandException);
}

TEST_F(TestStandardHand, TestGetBadIndex)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_THROW(this->_hand->getCard(1), OutOfBoundsException);
}

TEST_F(TestStandardHand, TestGetIndex)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_EQ(*(this->_hand->getCard(0)), *(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestGetEmpty)
{
    ASSERT_THROW(this->_hand->getCard(this->_ace_hearts), EmptyHandException);
}

TEST_F(TestStandardHand, TestGetGood)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_EQ(*(this->_hand->getCard(this->_ace_hearts)), *(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestGetBadCard)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_THROW(this->_hand->getCard(this->_ace_spades), ElementNotFoundException);
}

TEST_F(TestStandardHand, TestContainsValid)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_TRUE(this->_hand->containsCard(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestContainsInvalid)
{
    this->_hand->addCard(this->_ace_hearts);

    ASSERT_FALSE(this->_hand->containsCard(this->_ace_spades));
}
