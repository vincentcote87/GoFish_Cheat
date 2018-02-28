#ifndef CHEAT_VIEW_H
#define CHEAT_VIEW_H

#include <string>
#include <memory>
#include "StandardHand.h"

using std::string;
using std::shared_ptr;

class CheatView {
public:
	CheatView();

	virtual ~CheatView();

	string askForPlayerName();

    void nameAlreadyExists();

    void showHand(shared_ptr<StandardHand> hand);

    void playerTurn(const string& name);

private:
    void printCard(shared_ptr<StandardCard> card);
};

#endif