////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorGtest.cpp
 *  @date   Wed May 26 2021
 *  @brief  Calculator Unit Tests
 */
////////////////////////////////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "../inc/Calculator.h"

using namespace testing;

//note formatCalculation does no calculation, it simply puts the numbers and char into a string
TEST(formatCalculationTest, BasicFormat)
{
    EXPECT_EQ("10 X 10 = 100", formatCalculation(10, 10, 100, 'X'));
    EXPECT_EQ("1 % 10 = 0", formatCalculation(1, 10, 0, '%'));
    EXPECT_EQ("10000000 + 10000000 = 20000000", formatCalculation(10000000, 10000000, 20000000, '+'));
    // Math doesn't have to make since since this does no calculation
    EXPECT_EQ("1 - 10 = 0", formatCalculation(1, 10, 0, '-'));
}

TEST(formatCalculationTest, UnexpectedCharacters)
{
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\0'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\n'));
    EXPECT_EQ("1 \\ 10 = 0", formatCalculation(1, 10, 0, '\\'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\t'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\v'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\b'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\r'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\a'));
}
