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

class GoFishController : public Controller
{
public:
    GoFishController();

    virtual ~GoFishController();

    virtual void setView(std::shared_ptr<GoFishView> view);

    virtual void setStandardPlayerFactory(std::shared_ptr<StandardPlayerFactory>
        standardPlayerFactory);

    virtual void setStandardDeckFactory(std::shared_ptr<StandardDeckFactory>
        standardDeckFactory);

    virtual void play();

    virtual void init();

    virtual void deal();

    virtual std::list<std::string> requestNames() const;

    virtual std::list<std::shared_ptr<StandardPlayer>> constructPlayers(
        std::list<std::string> names) const;

    virtual bool hasGameEnded() const;

    virtual std::shared_ptr<StandardPlayer> getWinner();

    virtual void playerTurn(std::shared_ptr<StandardPlayer> player);

    virtual bool isValidPlayer(std::string currentPlayerName, std::string& name);

    std::shared_ptr<StandardCard> getCard(std::string& suite, std::string& value);

    virtual std::shared_ptr<StandardPlayer> getPlayer(std::string& name);

    virtual bool isValidSuite(std::string& suite);

    virtual bool isValidValue(std::string& value);
private:
    std::shared_ptr<GoFishView> _view;

    std::shared_ptr<StandardPlayerFactory> _standardPlayerFactory;

    std::shared_ptr<StandardDeckFactory> _standardDeckFactory;

    std::list<std::shared_ptr<StandardPlayer>> _players;

    std::shared_ptr<StandardDeck> _deck;
};

#endif // GOFISHCONTROLLER_H_INCLUDED
