#include "../include/StandardDeckFactory.h"

StandardDeckFactory::StandardDeckFactory()
{

}

std::shared_ptr<StandardDeck> StandardDeckFactory::createStandardDeck()
{
    return std::shared_ptr<StandardDeck>(new StandardDeck());
}
