/*
Entry point for the test program, which uses Google Test.
*/
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;

int main(int argc, char** argv)
{
    //::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();
}
