#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "IMathOperation.h"
#include "Subtraction.h"
#include "Constant.h"

using namespace testing;

class SubtractionTests : public ::testing::Test{};

TEST_F(SubtractionTests, SubtractsNumbersAssociatively)
{
    IMathOperation* constant14p4 = new Constant(14.4);
    IMathOperation* constantN21p1 = new Constant(-21.1);
    Subtraction diffOf14p4AndN21p1(constant14p4, constantN21p1);
    Subtraction diffOfN21p1And14p4(constantN21p1, constant14p4);
    EXPECT_DOUBLE_EQ(diffOf14p4AndN21p1.calculate(), 35.5);
    EXPECT_DOUBLE_EQ(diffOfN21p1And14p4.calculate(), -35.5);
};