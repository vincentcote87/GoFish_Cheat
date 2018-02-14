#include <gtest/gtest.h>
#include <memory>
#include "TestStandardHand.h"
#include "../include/CardAlreadyInHandException.h"
#include "../include/EmptyHandException.h"
#include "../include/OutOfBoundsException.h"
#include "../include/ElementNotFoundException.h"

TestStandardHand::TestStandardHand(): ::testing::Test(),_hand(std::shared_ptr<StandardHand>()),_ace_hearts(
    std::shared_ptr<StandardCard>()),_ace_spades(std::shared_ptr<StandardCard>())
{
    SetUp();
}

TestStandardHand::~TestStandardHand()
{
    TearDown();
}

void TestStandardHand::SetUp()
{
    this->_hand = std::shared_ptr<StandardHand>(new StandardHand());

    this->_ace_hearts = std::shared_ptr<StandardCard>(new StandardCard(
        CardSuite::HEART, CardValue::ACE));
    this->_ace_spades = std::shared_ptr<StandardCard>(new StandardCard(
        CardSuite::SPADE, CardValue::ACE));
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
        this->_hand->remove(0);
    }

    ASSERT_TRUE(this->_hand->isEmpty());
}

TEST_F(TestStandardHand, TestNotIsEmpty)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_FALSE(this->_hand->isEmpty());
}

TEST_F(TestStandardHand, TestEmpyGetCount)
{
    ASSERT_EQ(this->_hand->getCount(), 0);
}

TEST_F(TestStandardHand, TestAddGetCount)
{
    unsigned int count = this->_hand->getCount();

    this->_hand->add(this->_ace_hearts);

    ASSERT_EQ(count + 1, this->_hand->getCount());
}

TEST_F(TestStandardHand, TestAddRemoveGetCount)
{
    this->_hand->add(this->_ace_hearts);

    unsigned int count = this->_hand->getCount();

    this->_hand->remove(0);

    ASSERT_EQ(count - 1, this->_hand->getCount());
}

TEST_F(TestStandardHand, TestAdd)
{
    std::shared_ptr<StandardCard> card = this->_hand->add(this->_ace_hearts);

    ASSERT_EQ(*card, *(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestAddSameCard)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_THROW(this->_hand->add(this->_ace_hearts), CardAlreadyInHandException);
}

TEST_F(TestStandardHand, TestAddDiffCards)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_NO_THROW(this->_hand->add(this->_ace_spades));
}

TEST_F(TestStandardHand, TestRemoveIndex)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_EQ(*(this->_hand->remove(0)), *(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestRemoveCard)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_EQ(*(this->_hand->remove(this->_ace_hearts)), *(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestRemoveIndexEmpty)
{
    ASSERT_THROW(this->_hand->remove(0), EmptyHandException);
}

TEST_F(TestStandardHand, TestRemoveCardEmpty)
{
    ASSERT_THROW(this->_hand->remove(this->_ace_hearts), EmptyHandException);
}

TEST_F(TestStandardHand, TestRemoveNoSuchCard)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_THROW(this->_hand->remove(this->_ace_spades), ElementNotFoundException);
}

TEST_F(TestStandardHand, TestRemoveBadIndex)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_THROW(this->_hand->remove(1), OutOfBoundsException);
}

TEST_F(TestStandardHand, TestGetIndexEmpty)
{
    ASSERT_THROW(this->_hand->get(0), EmptyHandException);
}

TEST_F(TestStandardHand, TestGetBadIndex)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_THROW(this->_hand->get(1), OutOfBoundsException);
}

TEST_F(TestStandardHand, TestGetIndex)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_EQ(*(this->_hand->get(0)), *(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestGetEmpty)
{
    ASSERT_THROW(this->_hand->get(this->_ace_hearts), EmptyHandException);
}

TEST_F(TestStandardHand, TestGetGood)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_EQ(*(this->_hand->get(this->_ace_hearts)), *(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestGetBadCard)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_THROW(this->_hand->get(this->_ace_spades), ElementNotFoundException);
}

TEST_F(TestStandardHand, TestContainsValid)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_TRUE(this->_hand->contains(this->_ace_hearts));
}

TEST_F(TestStandardHand, TestContainsInvalid)
{
    this->_hand->add(this->_ace_hearts);

    ASSERT_FALSE(this->_hand->contains(this->_ace_spades));
}
