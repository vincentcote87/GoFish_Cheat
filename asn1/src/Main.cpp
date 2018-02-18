/*
Entry point of the application.
*/
#include "../include/GoFishController.h"

int main(int argCount, char** args)
{
    shared_ptr<GoFishView> view(shared_ptr<GoFishView>(
        new GoFishView()));

    shared_ptr<StandardPlayerFactory> standardPlayerFactory(
        shared_ptr<StandardPlayerFactory>(new StandardPlayerFactory()));

    shared_ptr<StandardDeckFactory> standardDeckFactory(
        shared_ptr<StandardDeckFactory>(new StandardDeckFactory()));

    shared_ptr<GoFishController> controller(
        shared_ptr<GoFishController>(new GoFishController()));

    controller->setStandardPlayerFactory(standardPlayerFactory);

    controller->setStandardDeckFactory(standardDeckFactory);

    controller->setView(view);

    controller->play();

    return 0;
}
