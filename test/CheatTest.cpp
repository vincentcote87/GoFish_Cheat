#include "gtest/gtest.h"

#include "MockDeck.h"
#include "MockUI.h"

#include "Deck.h"
#include "Card.h"
#include "Game.h"
#include "Cheat.h"

TEST(CheatTest, dealCards) {
	MockDeck deck;
	MockUI ui;

	Game* game = new Cheat(&ui, &deck);

	game -> addPlayer(new Player("Vincent"));
	game -> addPlayer(new Player("Krista"));

	EXPECT_CALL(deck, getCard())
	.Times(10)
	.WillRepeatedly(Return (new Card(Card::HEART, Card::KING)));

	EXPECT_CALL(deck, size())
	.Times(2)
	.WillRepeatedly(Return(10));

	

	game -> dealCards(game -> getPlayers());

	for(Player* players : game -> getPlayers())
		EXPECT_TRUE(players -> getHand() -> size() == 5);
}

TEST(CheatTest, runningGame) {
	MockDeck deck;
	MockUI ui;

	Player* p1 = new Player("Vincent");
	Player* p2 = new Player("Krista");

	EXPECT_CALL(deck, shuffle())
	.Times(1);

	EXPECT_CALL(deck, size())
	.Times(2)
	.WillRepeatedly(Return(3));

	EXPECT_CALL(deck, getCard())
	.Times(3)
	.WillOnce(Return(new Card(Card::HEART, Card::ACE)))
	.WillOnce(Return(new Card(Card::HEART, Card::TWO)))
	.WillOnce(Return(new Card(Card::HEART, Card::SIX)));

	EXPECT_CALL(ui, playerName(_))
	.Times(AtLeast(1));

	EXPECT_CALL(ui, currentFace(_))
	.Times(AtLeast(1));

	EXPECT_CALL(ui, noCardsPlayed())
	.Times(1);

	EXPECT_CALL(ui, requestCard(_))
	.Times(AtLeast(1))
	.WillOnce(Return(54))
	.WillOnce(Return(0))
	.WillOnce(Return(0))
	.WillOnce(Return(54))
	.WillOnce(Return(0))
	.WillOnce(Return(54))
	.WillOnce(Return(0))
	.WillRepeatedly(Return(54));

	EXPECT_CALL(ui, callCheat(_))
	.Times(AtLeast(1))
	.WillOnce(Return(1))
	.WillOnce(Return(0))
	.WillRepeatedly(Return(2));

	EXPECT_CALL(ui, playSucceeded())
	.Times(1);

	EXPECT_CALL(ui, playFailed())
	.Times(1);

	EXPECT_CALL(ui, showScores(_))
	.Times(1);


	Game* game = new Cheat(&ui, &deck);

	game -> addPlayer(p1);
	game -> addPlayer(p2);

	game -> start();

	EXPECT_EQ(0, p1 -> getScore());
	EXPECT_EQ(1, p2 -> getScore());
}

TEST (CheatTest, NoPlayers){

    Game* game = new Cheat(nullptr, nullptr);
    EXPECT_THROW(game->start(), game_init_error);

}