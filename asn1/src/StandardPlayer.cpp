#include "../include/StandardPlayer.h"
#include "../include/StandardHand.h"

StandardPlayer::StandardPlayer(const std::string& name):_name(name),_hand(std::shared_ptr<StandardHand>(
    new StandardHand()))
{

}

StandardPlayer::~StandardPlayer()
{
    this->_hand.reset();
}

std::shared_ptr<StandardHand> StandardPlayer::getHand()
{
    return this->_hand;
}

std::string StandardPlayer::getName() const
{
    return this->_name;
}
