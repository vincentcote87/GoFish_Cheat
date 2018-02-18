#include "../include/StandardPlayer.h"
#include "../include/StandardHand.h"

StandardPlayer::StandardPlayer(const string& name):_name(name),_hand(shared_ptr<StandardHand>(
    new StandardHand()))
{

}

StandardPlayer::~StandardPlayer()
{
    this->_hand.reset();
}

shared_ptr<StandardHand> StandardPlayer::getHand()
{
    return this->_hand;
}

string StandardPlayer::getName() const
{
    return this->_name;
}
