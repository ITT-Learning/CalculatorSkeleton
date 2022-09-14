#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "IMathOperation.h"
#include "Multiplication.h"
#include "Constant.h"

using namespace testing;

class MultiplicationTests : public ::testing::Test {};



TEST_F(MultiplicationTests, MultipliesPositiveNumbers)
{
    Multiplication productOf5And4(new Constant(5), new Constant(4));
    EXPECT_DOUBLE_EQ(productOf5And4.calculate(), 20);
};



TEST_F(MultiplicationTests, MultipliesPositiveAndNegativeNumbers)
{
    Multiplication productOf5AndN4(new Constant(5), new Constant(-4));
    EXPECT_DOUBLE_EQ(productOf5AndN4.calculate(), -20);
};



TEST_F(MultiplicationTests, MultipliesNegativeNumbers)
{
    Multiplication productOfN5AndN4(new Constant(-5), new Constant(-4));
    EXPECT_DOUBLE_EQ(productOfN5AndN4.calculate(), 20);
};



TEST_F(MultiplicationTests, MultipliesFractionalNumbers)
{
    Multiplication productOf2p5And2(new Constant(2.5), new Constant(2));
    EXPECT_DOUBLE_EQ(productOf2p5And2.calculate(), 5);
};



TEST_F(MultiplicationTests, MultipliesAssociativelyCorrectly)
{
    Multiplication productOfN4And5(new Constant(-4), new Constant(5));
    Multiplication productOf5AndN4(new Constant(5), new Constant(-4));
    EXPECT_DOUBLE_EQ(productOfN4And5.calculate(), productOf5AndN4.calculate());
}