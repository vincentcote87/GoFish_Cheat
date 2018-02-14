#include <iostream>
#include <sstream>
#include "../include/GoFishView.h"

GoFishView::GoFishView()
{

}

GoFishView::~GoFishView()
{

}

std::string GoFishView::askForPlayerName()
{
    std::cout << "Please enter a player name (enter if you don't want to add another player): ";

    std::string name;

    getline(std::cin, name);

    return name;
}

void GoFishView::nameAlreadyExists()
{
    std::cout << "You've tried to enter a player name which has already been specified." << std::endl;
}

void GoFishView::playerTurn(const std::string& name)
{
    system("clear");

    std::cout << "It's name " << name << "'s turn. Press enter when ready." << std::endl;

    std::string line;

    getline(std::cin, line);
}

void GoFishView::showHand(std::shared_ptr<StandardHand> hand)
{
    std::cout << "Your hand: ";

    unsigned int count = hand->getCount();

    for (unsigned int i = 0; i < count; ++i)
    {
        std::shared_ptr<StandardCard> card = hand->get(i);

        printCard(card);

        if (i < count - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
}

void GoFishView::printCard(std::shared_ptr<StandardCard> card)
{
    std::string suite;
    std::string value;

    switch (card->getSuite())
    {
    case CardSuite::CLUB:
        suite = "Clubs";

        break;
    case CardSuite::DIAMOND:
        suite = "Diamonds";

        break;
    case CardSuite::HEART:
        suite = "Hearts";

        break;
    case CardSuite::SPADE:
        suite = "Spades";

        break;
    default:
        suite = "Unknown Suite";

        break;
    }

    switch (card->getValue())
    {
    case CardValue::ACE:
        value = "Ace";

        break;
    case CardValue::TWO:
        value = "Two";

        break;
    case CardValue::THREE:
        value = "Three";

        break;
    case CardValue::FOUR:
        value = "Four";

        break;
    case CardValue::FIVE:
        value = "Five";

        break;
    case CardValue::SIX:
        value = "Six";

        break;
    case CardValue::SEVEN:
        value = "Seven";

        break;
    case CardValue::EIGHT:
        value = "Eight";

        break;
    case CardValue::NINE:
        value = "Nine";

        break;
    case CardValue::TEN:
        value = "Ten";

        break;
    case CardValue::JACK:
        value = "Jack";

        break;
    case CardValue::QUEEN:
        value = "Queen";

        break;
    case CardValue::KING:
        value = "King";

        break;
    default:
        value = "Unknown Value";

        break;
    }

    std::cout << value << " of " << suite;
}

std::string GoFishView::askPlayerNameToTakeFrom()
{
    std::cout << "Whom would you like to ask for a card? Please enter their name: ";

    std::string name;

    getline(std::cin, name);

    return name;
}

void GoFishView::invalidPlayerName()
{
    std::cout << "There's no player with that name." << std::endl;
}

std::string GoFishView::askForSuite()
{
    std::cout << "Enter the suite of the card you'd like to ask for: ";

    std::string str;

    getline(std::cin, str);

    return str;
}

void GoFishView::enteredOwnName()
{
    std::cout << "You tried entering your own name." << std::endl;
}

std::string GoFishView::askForValue()
{
    std::cout << "Enter the value of the card you'd like to ask for: ";

    std::string str;

    getline(std::cin, str);

    return str;
}

void GoFishView::invalidSuite(std::string& suite)
{
    std::cout << "Invalid card suite: " << suite << "." << std::endl;
}

void GoFishView::invalidValue(std::string& value)
{
    std::cout << "Invalid card value: " << value << "." << std::endl;
}

void GoFishView::playerHasA(bool has)
{
    if (has)
    {
        std::cout << "The player has that card! You took it for yourself!" << std::endl;
    }
    else
    {
        std::cout << "\"Go fish!\"" << std::endl;
    }
}

void GoFishView::drawCard()
{
    std::cout << "You draw a card from the deck." << std::endl;
}

void GoFishView::emptyDeck()
{
    std::cout << "The deck is empty! You are enable to draw a card from the deck." << std::endl;
}

void GoFishView::endTurn()
{
    std::cout << "Please press enter to end your turn." << std::endl;

    std::string line;

    getline(std::cin, line);
}

void GoFishView::gameWon(std::string name)
{
    std::cout << name << " has won the game!";

    std::string line;

    getline(std::cin, line);
}
