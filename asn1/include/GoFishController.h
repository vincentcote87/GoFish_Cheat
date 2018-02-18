#ifndef GOFISHCONTROLLER_H_INCLUDED
#define GOFISHCONTROLLER_H_INCLUDED

#include <memory>
#include <list>
#include <string>
#include "Controller.h"
#include "GoFishView.h"
#include "StandardPlayer.h"
#include "StandardDeck.h"
#include "StandardPlayerFactory.h"
#include "StandardDeckFactory.h"

using std::list;
using std::string;
using std::shared_ptr;

class GoFishController : public Controller
{
public:
    GoFishController();

    virtual ~GoFishController();

    virtual void setView(shared_ptr<GoFishView> view);

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

    virtual shared_ptr<StandardPlayer> getWinner();

    virtual void playerTurn(shared_ptr<StandardPlayer> player);

    virtual bool isValidPlayer(string currentPlayerName, string& name);

    shared_ptr<StandardCard> getCard(string& suit, string& value);

    virtual shared_ptr<StandardPlayer> getPlayer(string& name);

    virtual bool isValidSuit(string& suit);

    virtual bool isValidValue(string& value);
private:
    shared_ptr<GoFishView> _view;

    shared_ptr<StandardPlayerFactory> _standardPlayerFactory;

    shared_ptr<StandardDeckFactory> _standardDeckFactory;

    list<shared_ptr<StandardPlayer>> _players;

    shared_ptr<StandardDeck> _deck;
};

#endif // GOFISHCONTROLLER_H_INCLUDED
