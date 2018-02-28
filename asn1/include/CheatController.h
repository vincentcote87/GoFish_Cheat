#ifndef CHEATCONTROLLER_H
#define CHEATCONTROLLER_H

#include <memory>
#include <list>
#include <string>
#include "Controller.h"
#include "CheatView.h"
#include "StandardPlayer.h"
#include "StandardDeck.h"
#include "StandardPlayerFactory.h"
#include "StandardDeckFactory.h"

using std::list;
using std::string;
using std::shared_ptr;

class CheatController : public Controller {
public:
	CheatController();

	virtual ~CheatController();

	virtual void setView(shared_ptr<CheatView> view);

    virtual void setStandardPlayerFactory(shared_ptr<StandardPlayerFactory>
        standardPlayerFactory);

    virtual void setStandardDeckFactory(shared_ptr<StandardDeckFactory>
        standardDeckFactory);

    virtual void play();

    virtual void init();

    virtual void deal();

    virtual list<string> requestNames() const;

    virtual list<shared_ptr<StandardPlayer>> constructPlayers(
        list<string> names) const;

    virtual bool hasGameEnded() const;

    virtual void playerTurn(shared_ptr<StandardPlayer> player);


private:
	shared_ptr<CheatView> _view;

    shared_ptr<StandardPlayerFactory> _standardPlayerFactory;

    shared_ptr<StandardDeckFactory> _standardDeckFactory;

    list<shared_ptr<StandardPlayer>> _players;

    shared_ptr<StandardDeck> _deck;
};

#endif