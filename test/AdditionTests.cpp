#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "IMathOperation.h"
#include "Addition.h"
#include "Constant.h"

using namespace testing;

class AdditionTests : public ::testing::Test{};

TEST_F(AdditionTests, AddsNumbersAssociatively)
{
    IMathOperation* constant14p4 = new Constant(14.4);
    IMathOperation* constantN21p1 = new Constant(-21.1);
    Addition sumOf14p4AndN21p1(constantN21p1, constant14p4);
    Addition sumOfN21p1And14p4(constant14p4, constantN21p1);
    EXPECT_DOUBLE_EQ(sumOf14p4AndN21p1.calculate(), -6.7);
    EXPECT_DOUBLE_EQ(sumOfN21p1And14p4.calculate(), -6.7);
};