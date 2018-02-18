#include "../include/StandardDeckFactory.h"

StandardDeckFactory::StandardDeckFactory()
{

}

shared_ptr<StandardDeck> StandardDeckFactory::createStandardDeck()
{
    return shared_ptr<StandardDeck>(new StandardDeck());
}
