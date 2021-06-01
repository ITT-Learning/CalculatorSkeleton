////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorGtest.cpp
 *  @date   Wed May 26 2021
 *  @brief  Calculator Unit Tests
 */
////////////////////////////////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "../inc/CalculatorW1.h"

using namespace testing;
using namespace calculator;

/**
 * @brief Unit test for formatCalculation with expected arguments. Should return formatted string.
 * @note formatCalculation simply formats the text, so the math doesn't need to make sense
 * 
 */
TEST(WeekOneCalculatorTests, WhenFormatCalculationGetsCalledWithExpectedArguments_ThenFormattedStringReturned)
{
    EXPECT_EQ("10 X 10 = 100", formatCalculation(10, 10, 100, 'X'));
    EXPECT_EQ("1 % 10 = 0", formatCalculation(1, 10, 0, '%'));
    EXPECT_EQ("10000000 + 10000000 = 20000000", formatCalculation(10000000, 10000000, 20000000, '+'));
    EXPECT_EQ("1 - 10 = 0", formatCalculation(1, 10, 0, '-'));
}

/**
 * @brief Unit test for formatCalculation if a control character is used instead of expected characters
 *        should replace the control character with just a ' '
 * 
 */
TEST(WeekOneCalculatorTests, WhenFormatCalculationGetsCalledWithControlCharacter_ThenReturnFormattedStringWithControlCharacterReplacedWithSpace)
{
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\0'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\n'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\t'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\v'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\b'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\r'));
    EXPECT_EQ("1   10 = 0", formatCalculation(1, 10, 0, '\a'));
}
