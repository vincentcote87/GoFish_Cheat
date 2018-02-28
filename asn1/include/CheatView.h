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

private:

};

#endif