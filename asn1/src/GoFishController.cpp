#include <iostream>
#include <algorithm>
#include "../include/GoFishController.h"
#include "../include/StandardPlayer.h"

GoFishController::GoFishController():
    _view(std::shared_ptr<GoFishView>()),
    _standardPlayerFactory(std::shared_ptr<StandardPlayerFactory>()),
    _standardDeckFactory(std::shared_ptr<StandardDeckFactory>()),
    _players(std::list<std::shared_ptr<StandardPlayer>>()),
    _deck(std::shared_ptr<StandardDeck>())
{

}

GoFishController::~GoFishController()
{

}

void GoFishController::setView(std::shared_ptr<GoFishView> view)
{
    this->_view = view;
}

void GoFishController::setStandardPlayerFactory(std::shared_ptr<StandardPlayerFactory>
        standardPlayerFactory)
{
    this->_standardPlayerFactory = standardPlayerFactory;
}

void GoFishController::setStandardDeckFactory(std::shared_ptr<StandardDeckFactory>
        standardDeckFactory)
{
    this->_standardDeckFactory = standardDeckFactory;
}

void GoFishController::play()
{
    init();

    std::list<std::shared_ptr<StandardPlayer>>::iterator playerIter = this->_players.begin();

    while (!hasGameEnded())
    {
        if (playerIter == this->_players.end())
        {
            playerIter = this->_players.begin();
        }

        std::shared_ptr<StandardPlayer> player = *playerIter;

        playerTurn(player);

        ++playerIter;
    }

    //Game has ended. Declare winner.

    this->_view->gameWon(getWinner()->getName());
}

void GoFishController::init()
{
    std::list<std::string> names = requestNames();

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
            (*it)->getHand()->add(this->_deck->popTop());
        }
    }
}

std::list<std::string> GoFishController::requestNames() const
{
    std::list<std::string> names = std::list<std::string>();

    std::string name;

    do
    {
        name = this->_view->askForPlayerName();
        if (name.size() > 0)
        {
            bool alreadyContainsName = std::find(names.begin(), names.end(), name) != names.end();

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

std::list<std::shared_ptr<StandardPlayer>> GoFishController::constructPlayers(
    std::list<std::string> names) const
{
    std::list<std::shared_ptr<StandardPlayer>> players;

    for (std::list<std::string>::const_iterator it = names.cbegin(); it != names.cend(); ++it)
    {
        std::shared_ptr<StandardPlayer> player = this->_standardPlayerFactory->createPlayer(*it);

        players.push_back(player);
    }

    return players;
}

bool GoFishController::hasGameEnded() const
{
    unsigned int remaining_players = 0;

    for (std::list<std::shared_ptr<StandardPlayer>>::const_iterator it = this->_players.cbegin();
        it != this->_players.cend(); ++it)
    {
        std::shared_ptr<StandardPlayer> player = *it;

        if (!player->getHand()->isEmpty())
        {
            ++remaining_players;
        }
    }

    return remaining_players < 2;
}

std::shared_ptr<StandardPlayer> GoFishController::getWinner()
{
    for (std::list<std::shared_ptr<StandardPlayer>>::const_iterator it = this->_players.cbegin();
        it != this->_players.cend(); ++it)
    {
        std::shared_ptr<StandardPlayer> player = *it;

        if (!player->getHand()->isEmpty())
        {
            return player;
        }
    }

    return *(this->_players.begin());
}

void GoFishController::playerTurn(std::shared_ptr<StandardPlayer> player)
{
    if (player->getHand()->isEmpty())
    {
        //The player's hand is empty. Don't give them a turn.
        return;
    }

    this->_view->playerTurn(player->getName());

    this->_view->showHand(player->getHand());


    std::string requestedName;

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

    std::shared_ptr<StandardPlayer> askedPlayer = getPlayer(requestedName);

    std::string suite;

    askedTimes = 0;

    do
    {
        if (++askedTimes > 1)
        {
            this->_view->invalidSuite(suite);
        }

        suite = this->_view->askForSuite();
    }
    while (!isValidSuite(suite));


    std::string value;

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

    std::shared_ptr<StandardCard> card = getCard(suite, value);

    if (askedPlayer->getHand()->contains(card))
    {
        this->_view->playerHasA(true);

        askedPlayer->getHand()->remove(card);

        player->getHand()->add(card);
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

            player->getHand()->add(this->_deck->popTop());
        }
    }

    this->_view->endTurn();
}

bool GoFishController::isValidPlayer(std::string currentPlayerName, std::string& name)
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

std::shared_ptr<StandardPlayer> GoFishController::getPlayer(std::string& name)
{
    for (auto it = this->_players.cbegin(); it != this->_players.cend(); ++it)
    {
        auto player = *it;

        if (player->getName() == name)
        {
            return player;
        }
    }

    return std::shared_ptr<StandardPlayer>(nullptr);
}

std::shared_ptr<StandardCard> GoFishController::getCard(std::string& suite, std::string& value)
{
    CardValue cvalue;
    CardSuite csuite;

    for (std::string::size_type i = 0; i < suite.length(); ++i)
    {
        suite[i] = std::tolower(suite[i]);
    }

    for (std::string::size_type i = 0; i < value.length(); ++i)
    {
        value[i] = std::tolower(value[i]);
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

    if (suite == "heart" || suite == "hearts")
    {
        csuite = CardSuite::HEART;
    }
    else if (suite == "spade" || suite == "spades")
    {
        csuite = CardSuite::SPADE;
    }
    else if (suite == "club" || suite == "clubs")
    {
        csuite = CardSuite::CLUB;
    }
    else if (suite == "diamond" || suite == "diamonds")
    {
        csuite = CardSuite::DIAMOND;
    }
    else
    {
        csuite = CardSuite::HEART;
    }

    return std::shared_ptr<StandardCard>(new StandardCard(csuite, cvalue));
}

bool GoFishController::isValidSuite(std::string& suite)
{
    for (std::string::size_type i = 0; i < suite.length(); ++i)
    {
        suite[i] = std::tolower(suite[i]);
    }

    return suite == "heart" || suite == "hearts" || suite == "spade" || suite == "spades" ||
        suite == "diamond" || suite == "diamonds" || suite == "club" || suite == "clubs";
}

bool GoFishController::isValidValue(std::string& value)
{
    for (std::string::size_type i = 0; i < value.length(); ++i)
    {
        value[i] = std::tolower(value[i]);
    }

    return value == "ace" || value == "two" || value == "three" || value == "four" ||
        value == "five" || value == "six" || value == "seven" || value == "eight" ||
        value == "nine" || value == "ten" || value == "jack" || value == "queen" ||
        value == "king";
}
