/*
Entry point of the application.
*/
#include "../include/GoFishController.h"
#include "../include/CheatController.h"

int main(int argCount, char** args)
{
    // shared_ptr<GoFishView> view(shared_ptr<GoFishView>(
    //     new GoFishView()));

    shared_ptr<CheatView> view(shared_ptr<CheatView>(
        new CheatView()));

    shared_ptr<StandardPlayerFactory> standardPlayerFactory(
        shared_ptr<StandardPlayerFactory>(new StandardPlayerFactory()));

    shared_ptr<StandardDeckFactory> standardDeckFactory(
        shared_ptr<StandardDeckFactory>(new StandardDeckFactory()));

    // shared_ptr<GoFishController> controller(
    //     shared_ptr<GoFishController>(new GoFishController()));

    shared_ptr<CheatController> controller(
        shared_ptr<CheatController>(new CheatController()));

    controller->setStandardPlayerFactory(standardPlayerFactory);

    controller->setStandardDeckFactory(standardDeckFactory);

    controller->setView(view);

    controller->play();

    return 0;
}
