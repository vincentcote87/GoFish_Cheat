#include "../include/StandardPlayerFactory.h"
#include "../include/StandardPlayer.h"

StandardPlayerFactory::StandardPlayerFactory()
{

}

shared_ptr<StandardPlayer> StandardPlayerFactory::createStandardPlayer(string name)
{
    return shared_ptr<StandardPlayer>(new StandardPlayer(name));
}