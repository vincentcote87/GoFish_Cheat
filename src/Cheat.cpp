#include "Cheat.h"

void Cheat::dealCards(vector<Player*> players) {
    unsigned int numCards = deck -> size();

    if(deck->size() > 0) {
        unsigned int playerNum = 0;
        for(unsigned int i = 0; i < numCards; i++) {
            Player* p = players.at(playerNum);
            p->addCard(deck->getCard());
            playerNum = ++playerNum % players.size();
        }
    }
}

void Cheat::beforeCardPlayed(unsigned int playerNum, unsigned int numPlayers) {

    ui -> playerName(players.at(playerNum));
    ui -> currentFace(face[currentFace + 1]);
    currentFace = (currentFace + 1) % 13;
    lastCardsPlayed.clear();
    // firstMove = false;

}

void Cheat::afterCardPlayed(Player* currentPlayer, vector<Player*> players, Card* played) {

    currentPlayer -> getHand() -> remove(played);
    lastCardsPlayed.push_back(played);
}

void Cheat::start() {
    if(players.empty())
        throw game_init_error("No players for game");

    // Deal cards
    deck->shuffle();
    dealCards(players);

    unsigned int turn = 0;
    Player* p = players.front();
    while(!isOver())
    {
        p = players.at(turn);
        beforeCardPlayed(turn, players.size());
        int cardsDiscarded = 0;
        while(true) {
            int index = ui->requestCard(p->getHand());
            if(index == 54 && lastCardsPlayed.size() == 0) {
                ui -> noCardsPlayed();
            }
            else if((index == 54 || cardsDiscarded == 3) && (lastCardsPlayed.size() != 0)){
                break;
            }
            else {
                Card* c = p->getCard(index);
                if(valid(c)) {
                    cardsDiscarded++;
                    afterCardPlayed(p, players, c);
                }
            }
        }

        didCheat = didLastCheat();
        for(int i = 0; i < lastCardsPlayed.size(); i++) {
            discardPile.push_back(lastCardsPlayed[i]);
        }    
        int callCheatIndex = ui -> callCheat(players);
        if(callCheatIndex < players.size()) {
            if(didCheat) {
                ui -> playSucceeded();
                for(int i = 0; i < discardPile.size(); i++)
                    p -> addCard(discardPile[i]);
            }
            else {
                ui -> playFailed();
                for(int i = 0; i < discardPile.size(); i++) {
                    players[callCheatIndex] -> addCard(discardPile[i]);
                }
            }
        }

        turn = ++turn % players.size();
    }
    ui->showScores(players);
}

bool Cheat::didLastCheat() {
    for(int i = 0; i < lastCardsPlayed.size(); i++) {
        if (lastCardsPlayed[i] -> rank != currentFace -1) {
            return true;
        }
    }
    return false;
}