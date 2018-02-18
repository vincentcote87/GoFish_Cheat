#include <gtest/gtest.h>
#include "../include/StandardPlayerFactory.h"
#include "../include/StandardDeckFactory.h"

using std::string;
using std::shared_ptr;

TEST(TestFactories, TestStandardPlayerFactory)
{
    shared_ptr<StandardPlayerFactory> factory(new StandardPlayerFactory());

    string name("Player1");

    shared_ptr<StandardPlayer> player = factory->createStandardPlayer(name);

    ASSERT_FALSE(player.get() == nullptr);
    ASSERT_TRUE(player->getName() == name);

    player.reset();
    factory.reset();
}

TEST(TestFactories, TestStandardDeckFactory)
{
    shared_ptr<StandardDeckFactory> factory(new StandardDeckFactory());

    shared_ptr<StandardDeck> deck = factory->createStandardDeck();

    ASSERT_FALSE(deck.get() == nullptr);
    ASSERT_EQ(deck->getCount(), 52);

    deck.reset();
    factory.reset();
}
