#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "IMathOperation.h"
#include "Addition.h"
#include "Constant.h"

using namespace testing;

class AdditionTests : public ::testing::Test {};



TEST_F(AdditionTests, AddsPositiveNumbers)
{
    Addition sumOf10And15(new Constant(10), new Constant(15));
    EXPECT_DOUBLE_EQ(sumOf10And15.calculate(), 25);
};



TEST_F(AdditionTests, AddsPositiveAndNegativeNumbers)
{
    Addition sumOfN10And15(new Constant(-10), new Constant(15));
    EXPECT_DOUBLE_EQ(sumOfN10And15.calculate(), 5);
};



TEST_F(AdditionTests, AddsNegativeNumbers)
{
    Addition sumOfN10AndN15(new Constant(-10), new Constant(-15));
    EXPECT_DOUBLE_EQ(sumOfN10AndN15.calculate(), -25);
};



TEST_F(AdditionTests, AddsFractionalNumbers)
{
    Addition sumOf1p5And1p3(new Constant(1.5), new Constant(1.3));
    EXPECT_DOUBLE_EQ(sumOf1p5And1p3.calculate(), 2.8);
};



TEST_F(AdditionTests, AddsAssociativelyCorrectly)
{
    Addition sumOfN10And15(new Constant(-10), new Constant(15));
    Addition sumOf15AndN10(new Constant(15), new Constant(-10));
    EXPECT_DOUBLE_EQ(sumOf15AndN10.calculate(), sumOfN10And15.calculate());
};