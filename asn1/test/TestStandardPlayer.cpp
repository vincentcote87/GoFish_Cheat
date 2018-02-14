#include <gtest/gtest.h>
#include <memory>
#include "../include/StandardPlayer.h"
#include "../include/StandardHand.h"

TEST(TestStandardPlayer, TestNewPlayer)
{
    std::shared_ptr<StandardPlayer> player(new StandardPlayer(std::string("Tyler")));

    player.reset();
}

TEST(TestStandardPlayer, TestGetName)
{
    std::string name("Tyler");

    std::shared_ptr<StandardPlayer> player(new StandardPlayer(name));

    ASSERT_EQ(name, player->getName());
}

TEST(TestStandardPlayer, TestGetHand)
{
    std::shared_ptr<StandardPlayer> player(new StandardPlayer(std::string("Tyler")));

    std::shared_ptr<StandardHand> hand = player->getHand();

    ASSERT_TRUE(hand != nullptr);
}
