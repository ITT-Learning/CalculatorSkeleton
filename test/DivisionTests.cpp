#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "IMathOperation.h"
#include "Division.h"
#include "Constant.h"

using namespace testing;

class DivisionTests : public ::testing::Test {};

TEST_F(DivisionTests, DividesPositiveNumbers)
{
    Division quotientOf20And4(new Constant(20), new Constant(4));
    EXPECT_DOUBLE_EQ(quotientOf20And4.calculate(), 5);
};



TEST_F(DivisionTests, DividesPositiveAndNegativeNumbers)
{
    Division quotientOfN20And4(new Constant(-20), new Constant(4));
    EXPECT_DOUBLE_EQ(quotientOfN20And4.calculate(), -5);
};



TEST_F(DivisionTests, DividesNegativeNumbers)
{
    Division quotientOfN20AndN4(new Constant(-20), new Constant(-4));
    EXPECT_DOUBLE_EQ(quotientOfN20AndN4.calculate(), 5);
};



TEST_F(DivisionTests, DividesDecimals)
{
    Division quotientOf1p5And0p5(new Constant(1.5), new Constant(0.5));
    EXPECT_DOUBLE_EQ(quotientOf1p5And0p5.calculate(), 3);
};



TEST_F(DivisionTests, DividesAssociativelyCorrectly)
{
    Division quotientOf20And4(new Constant(20), new Constant(4));
    Division quotientOf4And20(new Constant(4), new Constant(20));
    EXPECT_DOUBLE_EQ(quotientOf20And4.calculate(), 5);
    EXPECT_DOUBLE_EQ(quotientOf4And20.calculate(), 0.2);
};



TEST_F(DivisionTests, ReturnsZeroOnDivideByZero)
{
    Division DivideByZero(new Constant(1), new Constant(0));
    EXPECT_DOUBLE_EQ(DivideByZero.calculate(), 0);
};