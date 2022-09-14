#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace testing;

#include "Constant.h"

class ConstantTests : public ::testing::Test {};



TEST_F(ConstantTests, HoldsItsValue)
{
    double value = 10.5;
    Constant constValue(value);
    EXPECT_DOUBLE_EQ(constValue.calculate(), value);
};



TEST_F(ConstantTests, TwoConstantsWithSameValueAreEqual)
{
    double value = 1;
    Constant constant1(value);
    Constant constant2(value);
    EXPECT_DOUBLE_EQ(constant1.calculate(), constant2.calculate());
};