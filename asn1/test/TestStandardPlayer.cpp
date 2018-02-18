#include <gtest/gtest.h>
#include <memory>
#include "../include/StandardPlayer.h"
#include "../include/StandardHand.h"

TEST(TestStandardPlayer, TestNewPlayer)
{
    shared_ptr<StandardPlayer> player(new StandardPlayer(string("Tyler")));

    player.reset();
}

TEST(TestStandardPlayer, TestGetName)
{
    string name("Tyler");

    shared_ptr<StandardPlayer> player(new StandardPlayer(name));

    ASSERT_EQ(name, player->getName());
}

TEST(TestStandardPlayer, TestGetHand)
{
    shared_ptr<StandardPlayer> player(new StandardPlayer(string("Tyler")));

    shared_ptr<StandardHand> hand = player->getHand();

    ASSERT_TRUE(hand != nullptr);
}
