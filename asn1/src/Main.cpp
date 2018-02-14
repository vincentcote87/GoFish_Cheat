/*
Entry point of the application.
*/
#include "../include/GoFishController.h"

int main(int argCount, char** args)
{
    std::shared_ptr<GoFishView> view(std::shared_ptr<GoFishView>(
        new GoFishView()));

    std::shared_ptr<StandardPlayerFactory> standardPlayerFactory(
        std::shared_ptr<StandardPlayerFactory>(new StandardPlayerFactory()));

    std::shared_ptr<StandardDeckFactory> standardDeckFactory(
        std::shared_ptr<StandardDeckFactory>(new StandardDeckFactory()));

    std::shared_ptr<GoFishController> controller(
        std::shared_ptr<GoFishController>(new GoFishController()));

    controller->setStandardPlayerFactory(standardPlayerFactory);

    controller->setStandardDeckFactory(standardDeckFactory);

    controller->setView(view);

    controller->play();

    return 0;
}
