#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace testing;

#include "Constant.h"

class ConstantTests : public ::testing::Test{};

TEST_F(ConstantTests, HoldsItsValue)
{
    double value = 10.5;
    Constant constValue(value);
    EXPECT_DOUBLE_EQ(constValue.calculate(), value);
};