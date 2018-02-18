#include <iostream>
#include <sstream>
#include "../include/GoFishView.h"

using std::cin;
using std::cout;
using std::endl;

GoFishView::GoFishView()
{

}

GoFishView::~GoFishView()
{

}

string GoFishView::askForPlayerName()
{
    cout << "Please enter a player name (enter if you don't want to add another player): ";

    string name;

    getline(cin, name);

    return name;
}

void GoFishView::nameAlreadyExists()
{
    cout << "You've tried to enter a player name which has already been specified." << endl;
}

void GoFishView::playerTurn(const string& name)
{
    system("clear");

    cout << "It's name " << name << "'s turn. Press enter when ready." << endl;

    string line;

    getline(cin, line);
}

void GoFishView::showHand(shared_ptr<StandardHand> hand)
{
    cout << "Your hand: ";

    unsigned int count = hand->getCount();

    for (unsigned int i = 0; i < count; ++i)
    {
        shared_ptr<StandardCard> card = hand->get(i);

        printCard(card);

        if (i < count - 1)
        {
            cout << ", ";
        }
    }

    cout << endl;
}

void GoFishView::printCard(shared_ptr<StandardCard> card)
{
    string suite;
    string value;

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

    cout << value << " of " << suite;
}

string GoFishView::askPlayerNameToTakeFrom()
{
    cout << "Whom would you like to ask for a card? Please enter their name: ";

    string name;

    getline(cin, name);

    return name;
}

void GoFishView::invalidPlayerName()
{
    cout << "There's no player with that name." << endl;
}

string GoFishView::askForSuite()
{
    cout << "Enter the suite of the card you'd like to ask for: ";

    string str;

    getline(cin, str);

    return str;
}

void GoFishView::enteredOwnName()
{
    cout << "You tried entering your own name." << endl;
}

string GoFishView::askForValue()
{
    cout << "Enter the value of the card you'd like to ask for: ";

    string str;

    getline(cin, str);

    return str;
}

void GoFishView::invalidSuite(string& suite)
{
    cout << "Invalid card suite: " << suite << "." << endl;
}

void GoFishView::invalidValue(string& value)
{
    cout << "Invalid card value: " << value << "." << endl;
}

void GoFishView::playerHasA(bool has)
{
    if (has)
    {
        cout << "The player has that card! You took it for yourself!" << endl;
    }
    else
    {
        cout << "\"Go fish!\"" << endl;
    }
}

void GoFishView::drawCard()
{
    cout << "You draw a card from the deck." << endl;
}

void GoFishView::emptyDeck()
{
    cout << "The deck is empty! You are enable to draw a card from the deck." << endl;
}

void GoFishView::endTurn()
{
    cout << "Please press enter to end your turn." << endl;

    string line;

    getline(cin, line);
}

void GoFishView::gameWon(string name)
{
    cout << name << " has won the game!";

    string line;

    getline(cin, line);
}
