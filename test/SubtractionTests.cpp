#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "IMathOperation.h"
#include "Subtraction.h"
#include "Constant.h"

using namespace testing;

class SubtractionTests : public ::testing::Test {};



TEST_F(SubtractionTests, SubtractsPositiveNumbers)
{
    Subtraction diffOf10And15(new Constant(15), new Constant(10));
    EXPECT_DOUBLE_EQ(diffOf10And15.calculate(), 5);
};



TEST_F(SubtractionTests, SubtractsPositiveAndNegativeNumbers)
{
    Subtraction diffOfN10And15(new Constant(15), new Constant(-10));
    EXPECT_DOUBLE_EQ(diffOfN10And15.calculate(), 25);
};



TEST_F(SubtractionTests, SubtractsNegativeNumbers)
{
    Subtraction diffOfN10AndN15(new Constant(-10), new Constant(-15));
    EXPECT_DOUBLE_EQ(diffOfN10AndN15.calculate(), 5);
};



TEST_F(SubtractionTests, SubtractsFractionalNumbers)
{
    Subtraction diffOf1p5And1p3(new Constant(1.5), new Constant(1.3));
    EXPECT_DOUBLE_EQ(diffOf1p5And1p3.calculate(), 0.2);
};



TEST_F(SubtractionTests, SubtractsAssociativelyCorrectly)
{
    Subtraction diffOfN10And15(new Constant(-10), new Constant(15));
    Subtraction diffOf15AndN10(new Constant(15), new Constant(-10));
    EXPECT_DOUBLE_EQ(diffOf15AndN10.calculate(), 25);
    EXPECT_DOUBLE_EQ(diffOfN10And15.calculate(), -25);
};