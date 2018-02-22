#include <gmock/gmock.h>
#include "TestGoFishController.h"
#include "MockGoFishView.h"
#include "../include/GoFishController.h"

TestGoFishController::TestGoFishController(): ::testing::Test(),
    _mockStandardDeckFactory(shared_ptr<MockStandardDeckFactory>(new MockStandardDeckFactory())),
    _mockStandardPlayerFactory(shared_ptr<MockStandardPlayerFactory>(new MockStandardPlayerFactory())),
    _mockGoFishView(shared_ptr<MockGoFishView>(new MockGoFishView()))
{
    this->_mockController = shared_ptr<MockController>(new MockController());

    //this->_mockController->setStandardDeckFactory(this->_mockStandardDeckFactory);
    //this->_mockController->setStandardPlayerFactory(this->_mockStandardPlayerFactory);
    //this->_mockController->setView(this->_mockGoFishView);

    SetUp();
}

TestGoFishController::~TestGoFishController()
{
    TearDown();
}

void TestGoFishController::SetUp()
{

}

void TestGoFishController::TearDown()
{

}

TEST_F(TestGoFishController, TestPlay)
{
    this->_mockController->setStandardDeckFactory(this->_mockStandardDeckFactory);
    this->_mockController->setStandardPlayerFactory(this->_mockStandardPlayerFactory);
    this->_mockController->setView(this->_mockGoFishView);

    ::testing::Expectation expect1 = EXPECT_CALL(*(this->_mockController), play()).
        Times(::testing::Exactly(1));

    ::testing::Expectation expect2 = EXPECT_CALL(*(this->_mockController), init()).
        Times(::testing::AnyNumber()).
        After(expect1);

    ::testing::Expectation expect3 = EXPECT_CALL(*(this->_mockController), requestNames()).
        Times(::testing::AnyNumber()).
        After(expect2);

    ::testing::Expectation expect4 = EXPECT_CALL(*(this->_mockGoFishView), askForPlayerName()).
        Times(::testing::AnyNumber()).
        After(expect3).
        WillOnce(::testing::Return(string("Player1")));

    this->_mockController->play();

    this->_mockController.reset();
    this->_mockStandardDeckFactory.reset();
    this->_mockStandardPlayerFactory.reset();
    this->_mockGoFishView.reset();
}
