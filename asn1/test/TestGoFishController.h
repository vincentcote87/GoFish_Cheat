#ifndef TESTGOFISHCONTROLLER_H_INCLUDED
#define TESTGOFISHCONTROLLER_H_INCLUDED

#include <gtest/gtest.h>
#include <memory>
#include "MockStandardDeckFactory.h"
#include "MockStandardPlayerFactory.h"
#include "MockGoFishView.h"
#include "MockController.h"

class TestGoFishController : public ::testing::Test
{
public:
    TestGoFishController();

    virtual ~TestGoFishController();

    virtual void SetUp();

    virtual void TearDown();
protected:
    std::shared_ptr<MockStandardPlayerFactory> _mockStandardPlayerFactory;

    std::shared_ptr<MockStandardDeckFactory> _mockStandardDeckFactory;

    std::shared_ptr<MockGoFishView> _mockGoFishView;

    std::shared_ptr<MockController> _mockController;
};

#endif // TESTGOFISHCONTROLLER_H_INCLUDED
