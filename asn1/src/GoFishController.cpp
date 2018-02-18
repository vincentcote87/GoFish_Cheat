#include <iostream>
#include <algorithm>
#include "../include/GoFishController.h"
#include "../include/StandardPlayer.h"

GoFishController::GoFishController():
    _view(shared_ptr<GoFishView>()),
    _standardPlayerFactory(shared_ptr<StandardPlayerFactory>()),
    _standardDeckFactory(shared_ptr<StandardDeckFactory>()),
    _players(list<shared_ptr<StandardPlayer>>()),
    _deck(shared_ptr<StandardDeck>())
{

}

GoFishController::~GoFishController()
{

}

void GoFishController::setView(shared_ptr<GoFishView> view)
{
    this->_view = view;
}

void GoFishController::setStandardPlayerFactory(shared_ptr<StandardPlayerFactory>
        standardPlayerFactory)
{
    this->_standardPlayerFactory = standardPlayerFactory;
}

void GoFishController::setStandardDeckFactory(shared_ptr<StandardDeckFactory>
        standardDeckFactory)
{
    this->_standardDeckFactory = standardDeckFactory;
}

void GoFishController::play()
{
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

    this->_view->gameWon(getWinner()->getName());
}

void GoFishController::init()
{
    list<string> names = requestNames();

    this->_players = constructPlayers(names);

    this->_deck = this->_standardDeckFactory->createStandardDeck();

    this->_deck->shuffle();

    deal();
}

void GoFishController::deal()
{
    unsigned int cardCount;

    if (this->_players.size() < 4)
    {
        cardCount = 7;
    }
    else
    {
        cardCount = 5;
    }

    for (auto it = this->_players.begin(); it != this->_players.end(); ++it)
    {
        for (unsigned int i = 0; i < cardCount; i++)
        {
            (*it)->getHand()->addCard(this->_deck->popTop());
        }
    }
}

list<string> GoFishController::requestNames() const
{
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
    } while (name.size() > 0 || names.size() < 2 || names.size() >= 5);

    return names;
}

list<shared_ptr<StandardPlayer>> GoFishController::constructPlayers(
    list<string> names) const
{
    list<shared_ptr<StandardPlayer>> players;

    for (list<string>::const_iterator it = names.cbegin(); it != names.cend(); ++it)
    {
        shared_ptr<StandardPlayer> player = this->_standardPlayerFactory->createPlayer(*it);

        players.push_back(player);
    }

    return players;
}

bool GoFishController::hasGameEnded() const
{
    unsigned int remaining_players = 0;

    for (list<shared_ptr<StandardPlayer>>::const_iterator it = this->_players.cbegin();
        it != this->_players.cend(); ++it)
    {
        shared_ptr<StandardPlayer> player = *it;

        if (!player->getHand()->isEmpty())
        {
            ++remaining_players;
        }
    }

    return remaining_players < 2;
}

shared_ptr<StandardPlayer> GoFishController::getWinner()
{
    for (list<shared_ptr<StandardPlayer>>::const_iterator it = this->_players.cbegin();
        it != this->_players.cend(); ++it)
    {
        shared_ptr<StandardPlayer> player = *it;

        if (!player->getHand()->isEmpty())
        {
            return player;
        }
    }

    return *(this->_players.begin());
}

void GoFishController::playerTurn(shared_ptr<StandardPlayer> player)
{
    if (player->getHand()->isEmpty())
    {
        //The player's hand is empty. Don't give them a turn.
        return;
    }

    this->_view->playerTurn(player->getName());

    this->_view->showHand(player->getHand());


    string requestedName;

    unsigned int askedTimes = 0;

    do
    {
        if (++askedTimes > 1)
        {
            if (player->getName() == requestedName)
            {
                this->_view->enteredOwnName();
            }
            else
            {
                this->_view->invalidPlayerName();
            }
        }

        requestedName = this->_view->askPlayerNameToTakeFrom();
    }
    while (!isValidPlayer(player->getName(), requestedName));

    shared_ptr<StandardPlayer> askedPlayer = getPlayer(requestedName);

    string suit;

    askedTimes = 0;

    do
    {
        if (++askedTimes > 1)
        {
            this->_view->invalidSuit(suit);
        }

        suit = this->_view->askForSuit();
    }
    while (!isValidSuit(suit));


    string value;

    askedTimes = 0;

    do
    {
        if (++askedTimes > 1)
        {
                this->_view->invalidValue(value);
        }

        value = this->_view->askForValue();
    }
    while (!isValidValue(value));

    shared_ptr<StandardCard> card = getCard(suit, value);

    if (askedPlayer->getHand()->containsCard(card))
    {
        this->_view->playerHasA(true);

        askedPlayer->getHand()->removeCard(card);

        player->getHand()->addCard(card);
    }
    else
    {
        this->_view->playerHasA(false);

        if (this->_deck->isEmpty())
        {
            this->_view->emptyDeck();
        }
        else
        {
            this->_view->drawCard();

            player->getHand()->addCard(this->_deck->popTop());
        }
    }

    this->_view->endTurn();
}

bool GoFishController::isValidPlayer(string currentPlayerName, string& name)
{
    if (currentPlayerName == name)
    {
        return false;
    }

    for (auto it = this->_players.cbegin(); it != this->_players.cend(); ++it)
    {
        auto player = *it;

        if (player->getName() == name)
        {
            return true;
        }
    }

    return false;
}

shared_ptr<StandardPlayer> GoFishController::getPlayer(string& name)
{
    for (auto it = this->_players.cbegin(); it != this->_players.cend(); ++it)
    {
        auto player = *it;

        if (player->getName() == name)
        {
            return player;
        }
    }

    return shared_ptr<StandardPlayer>(nullptr);
}

shared_ptr<StandardCard> GoFishController::getCard(string& suit, string& value)
{
    CardValue cvalue;
    CardSuit csuit;

    for (string::size_type i = 0; i < suit.length(); ++i)
    {
        suit[i] = tolower(suit[i]);
    }

    for (string::size_type i = 0; i < value.length(); ++i)
    {
        value[i] = tolower(value[i]);
    }

    if (value == "ace")
    {
        cvalue = CardValue::ACE;
    }
    else if (value == "two")
    {
        cvalue = CardValue::TWO;
    }
    else if (value == "three")
    {
        cvalue = CardValue::THREE;
    }
    else if (value == "four")
    {
        cvalue = CardValue::FOUR;
    }
    else if (value == "five")
    {
        cvalue = CardValue::FIVE;
    }
    else if (value == "six")
    {
        cvalue = CardValue::SIX;
    }
    else if (value == "seven")
    {
        cvalue = CardValue::SEVEN;
    }
    else if (value == "eight")
    {
        cvalue = CardValue::EIGHT;
    }
    else if (value == "nine")
    {
        cvalue = CardValue::NINE;
    }
    else if (value == "ten")
    {
        cvalue = CardValue::TEN;
    }
    else if (value == "jack")
    {
        cvalue = CardValue::JACK;
    }
    else if (value == "queen")
    {
        cvalue = CardValue::QUEEN;
    }
    else if (value == "king")
    {
        cvalue = CardValue::KING;
    }
    else
    {
        cvalue = CardValue::ACE;
    }

    if (suit == "heart" || suit == "hearts")
    {
        csuit = CardSuit::HEART;
    }
    else if (suit == "spade" || suit == "spades")
    {
        csuit = CardSuit::SPADE;
    }
    else if (suit == "club" || suit == "clubs")
    {
        csuit = CardSuit::CLUB;
    }
    else if (suit == "diamond" || suit == "diamonds")
    {
        csuit = CardSuit::DIAMOND;
    }
    else
    {
        csuit = CardSuit::HEART;
    }

    return shared_ptr<StandardCard>(new StandardCard(csuit, cvalue));
}

bool GoFishController::isValidSuit(string& suit)
{
    for (string::size_type i = 0; i < suit.length(); ++i)
    {
        suit[i] = tolower(suit[i]);
    }

    return suit == "heart" || suit == "hearts" || suit == "spade" || suit == "spades" ||
        suit == "diamond" || suit == "diamonds" || suit == "club" || suit == "clubs";
}

bool GoFishController::isValidValue(string& value)
{
    for (string::size_type i = 0; i < value.length(); ++i)
    {
        value[i] = tolower(value[i]);
    }

    return value == "ace" || value == "two" || value == "three" || value == "four" ||
        value == "five" || value == "six" || value == "seven" || value == "eight" ||
        value == "nine" || value == "ten" || value == "jack" || value == "queen" ||
        value == "king";
}
