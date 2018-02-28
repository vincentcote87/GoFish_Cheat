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