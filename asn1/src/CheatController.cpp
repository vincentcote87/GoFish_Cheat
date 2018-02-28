#include <iostream>
#include <algorithm>
#include "../include/CheatController.h"
#include "../include/StandardPlayer.h"

CheatController::CheatController():
    _view(shared_ptr<CheatView>()),
    _standardPlayerFactory(shared_ptr<StandardPlayerFactory>()),
    _standardDeckFactory(shared_ptr<StandardDeckFactory>()),
    _players(list<shared_ptr<StandardPlayer>>()),
    _deck(shared_ptr<StandardDeck>()) {}

CheatController::~CheatController() {}

void CheatController::setView(shared_ptr<CheatView> view) {
    this->_view = view;
}

void CheatController::setStandardPlayerFactory(shared_ptr<StandardPlayerFactory>
        standardPlayerFactory) {
    this->_standardPlayerFactory = standardPlayerFactory;
}

void CheatController::setStandardDeckFactory(shared_ptr<StandardDeckFactory>
        standardDeckFactory) {
    this->_standardDeckFactory = standardDeckFactory;
}

void CheatController::play() {
    init();

    list<shared_ptr<StandardPlayer>>::iterator playerIter = this->_players.begin();

    while (!hasGameEnded())
    {
        if (playerIter == this->_players.end())
        {
            playerIter = this->_players.begin();
        }

        shared_ptr<StandardPlayer> player = *playerIter;

        playerTurn(player);

        ++playerIter;
    }

    //Game has ended. Declare winner.

    // this->_view->gameWon(getWinner()->getName());
}

void CheatController::init() {
    list<string> names = requestNames();

    this->_players = constructPlayers(names);

    this->_deck = this->_standardDeckFactory->createStandardDeck();

    this->_deck->shuffle();

    deal();
}

void CheatController::deal() {
    // unsigned int cardCount = this -> _deck.use_count();

    // if (this->_players.size() < 4)
    // {
    //     cardCount = 7;
    // }
    // else
    // {
    //     cardCount = 5;
    // }
    while(!_deck -> isEmpty()){
        for (auto it = this->_players.begin(); it != this->_players.end(); ++it) {
            if(_deck -> isEmpty()) {
                break;
             }

            (*it)->getHand()->addCard(this->_deck->popTop());
        }
    }
}

list<string> CheatController::requestNames() const {
    list<string> names = list<string>();

    string name;

    do
    {
        name = this->_view->askForPlayerName();
        if (name.size() > 0)
        {
            bool alreadyContainsName = find(names.begin(), names.end(), name) != names.end();

            if (!alreadyContainsName)
            {
                names.push_back(name);
            }
            else
            {
                this->_view->nameAlreadyExists();
            }
        }
    } while (name.size() > 0 || names.size() < 2 || names.size() >= 10);

    return names;
}

list<shared_ptr<StandardPlayer>> CheatController::constructPlayers(
    list<string> names) const {
    list<shared_ptr<StandardPlayer>> players;

    for (list<string>::const_iterator it = names.cbegin(); it != names.cend(); ++it)
    {
        shared_ptr<StandardPlayer> player = this->_standardPlayerFactory->createStandardPlayer(*it);

        players.push_back(player);
    }

    return players;
}

bool CheatController::hasGameEnded() const {
    return false;
//     unsigned int remaining_players = 0;

//     for (list<shared_ptr<StandardPlayer>>::const_iterator it = this->_players.cbegin();
//         it != this->_players.cend(); ++it)
//     {
//         shared_ptr<StandardPlayer> player = *it;

//         if (!player->getHand()->isEmpty())
//         {
//             ++remaining_players;
//         }
//     }

//     return remaining_players < 2;
}

void CheatController::playerTurn(shared_ptr<StandardPlayer> player)
{

    // if (player->getHand()->isEmpty())
    // {
    //     //The player's hand is empty. Don't give them a turn.
    //     return;
    // }

    this->_view->playerTurn(player->getName());

    this->_view->showHand(player->getHand());



    // string requestedName;

    // unsigned int askedTimes = 0;

    // do
    // {
    //     if (++askedTimes > 1)
    //     {
    //         if (player->getName() == requestedName)
    //         {
    //             this->_view->enteredOwnName();
    //         }
    //         else
    //         {
    //             this->_view->invalidPlayerName();
    //         }
    //     }

    //     requestedName = this->_view->askPlayerNameToTakeFrom();
    // }
    // while (!isValidPlayer(player->getName(), requestedName));

    // shared_ptr<StandardPlayer> askedPlayer = getPlayer(requestedName);

    // string suit;

    // askedTimes = 0;

    // do
    // {
    //     if (++askedTimes > 1)
    //     {
    //         this->_view->invalidSuit(suit);
    //     }

    //     suit = this->_view->askForSuit();
    // }
    // while (!isValidSuit(suit));


    // string value;

    // askedTimes = 0;

    // do
    // {
    //     if (++askedTimes > 1)
    //     {
    //             this->_view->invalidValue(value);
    //     }

    //     value = this->_view->askForValue();
    // }
    // while (!isValidValue(value));

    // shared_ptr<StandardCard> card = getCard(suit, value);

    // if (askedPlayer->getHand()->containsCard(card))
    // {
    //     this->_view->playerHasA(true);

    //     askedPlayer->getHand()->removeCard(card);

    //     player->getHand()->addCard(card);
    // }
    // else
    // {
    //     this->_view->playerHasA(false);

    //     if (this->_deck->isEmpty())
    //     {
    //         this->_view->emptyDeck();
    //     }
    //     else
    //     {
    //         this->_view->drawCard();

    //         player->getHand()->addCard(this->_deck->popTop());
    //     }
    // }

    // this->_view->endTurn();
}