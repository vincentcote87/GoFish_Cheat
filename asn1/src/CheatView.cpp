#include <iostream>
#include <sstream>
#include "../include/CheatView.h"

using std::cin;
using std::cout;
using std::endl;

CheatView::CheatView() {}

CheatView::~CheatView() {}

string CheatView::askForPlayerName()
{
    cout << "Please enter a player name (enter if you don't want to add another player): ";

    string name;

    getline(cin, name);

    return name;
}

void CheatView::nameAlreadyExists()
{
    cout << "You've tried to enter a player name which has already been specified." << endl;
}

void CheatView::showHand(shared_ptr<StandardHand> hand)
{
    cout << "Your hand: " << endl;

    unsigned int count = hand->getCount();

    for (unsigned int i = 0; i < count; ++i)
    {
        shared_ptr<StandardCard> card = hand->getCard(i);

        printCard(card);
        cout << endl;

        // if (i < count - 1)
        // {
        //     cout << ", ";
        // }
    }

    cout << endl;
    int x;
    cin >> x;
}

void CheatView::playerTurn(const string& name) {
    system("clear");

    cout << "It's " << name << "'s turn. Press enter when ready." << endl;

    string line;

    getline(cin, line);
}

void CheatView::printCard(shared_ptr<StandardCard> card) {
    string suit;
    string value;

    switch (card->getSuit())
    {
    case CardSuit::CLUB:
        suit = "Clubs";

        break;
    case CardSuit::DIAMOND:
        suit = "Diamonds";

        break;
    case CardSuit::HEART:
        suit = "Hearts";

        break;
    case CardSuit::SPADE:
        suit = "Spades";

        break;
    default:
        suit = "Unknown Suit";

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

    cout << value << " of " << suit;
}