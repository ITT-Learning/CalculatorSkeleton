////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorGtest.cpp
 *  @date   Wed May 26 2021
 *  @brief  Calculator Unit Tests
 */
////////////////////////////////////////////////////////////////////////////

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/Calculator.h"

using namespace testing;
using namespace calculator;

TEST(WeekOneCalculatorTests, CalculateMethodTests)
{
    const char* errorString;
    double result;

    EXPECT_TRUE( Calculate('+', 1, 1, result) == nullptr && result == 2);
    EXPECT_TRUE( Calculate('+', 1, -1, result) == nullptr && result == 0);
    EXPECT_TRUE( Calculate('+', 1, -2, result) == nullptr && result == -1);

    EXPECT_TRUE( Calculate('-', 3, 1, result) == nullptr && result == 2);
    EXPECT_TRUE( Calculate('-', 1, 1, result) == nullptr && result == 0);
    EXPECT_TRUE( Calculate('-', 0, 1, result) == nullptr && result == -1);

    EXPECT_TRUE( Calculate('*', 1, 2, result) == nullptr && result == 2);
    EXPECT_TRUE( Calculate('*', 0, 1, result) == nullptr && result == 0);
    EXPECT_TRUE( Calculate('*', 1, -1, result) == nullptr && result == -1);

    EXPECT_TRUE( Calculate('/', 4, 2, result) == nullptr && result == 2);
    EXPECT_TRUE( Calculate('/', 0, 1, result) == nullptr && result == 0);
    EXPECT_TRUE( Calculate('/', 1, -1, result) == nullptr && result == -1);
    EXPECT_TRUE( Calculate('/', 1, 2, result) == nullptr && result == .5);
}

TEST(WeekOneCalculatorTests, CalculateMethodErrors)
{
    double result;

    ASSERT_STREQ(Calculate('/', 1, 0, result), "Error: Division by zero");
}