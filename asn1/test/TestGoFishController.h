#ifndef TESTGOFISHCONTROLLER_H_INCLUDED
#define TESTGOFISHCONTROLLER_H_INCLUDED

#include <gtest/gtest.h>
#include <memory>
#include "MockStandardDeckFactory.h"
#include "MockStandardPlayerFactory.h"
#include "MockGoFishView.h"
#include "MockController.h"

using std::shared_ptr;

class TestGoFishController : public ::testing::Test
{
public:
    TestGoFishController();

    virtual ~TestGoFishController();

    virtual void SetUp();

    virtual void TearDown();
protected:
    shared_ptr<MockStandardPlayerFactory> _mockStandardPlayerFactory;

    shared_ptr<MockStandardDeckFactory> _mockStandardDeckFactory;

    shared_ptr<MockGoFishView> _mockGoFishView;

    shared_ptr<MockController> _mockController;
};

#endif // TESTGOFISHCONTROLLER_H_INCLUDED
