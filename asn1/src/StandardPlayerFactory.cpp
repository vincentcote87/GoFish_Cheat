#include "../include/StandardPlayerFactory.h"
#include "../include/StandardPlayer.h"

StandardPlayerFactory::StandardPlayerFactory()
{

}

std::shared_ptr<StandardPlayer> StandardPlayerFactory::createPlayer(std::string name)
{
    return std::shared_ptr<StandardPlayer>(new StandardPlayer(name));
}
