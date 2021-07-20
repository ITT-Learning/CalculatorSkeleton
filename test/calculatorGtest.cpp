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
    EXPECT_EQ( 2, Calculate('+', 1, 1));
    EXPECT_EQ( 0, Calculate('+', 1, -1));
    EXPECT_EQ(-1, Calculate('+', 1, -2));

    EXPECT_EQ( 2, Calculate('-', 3, 1));
    EXPECT_EQ( 0, Calculate('-', 1, 1));
    EXPECT_EQ(-1, Calculate('-', 0, 1));

    EXPECT_EQ( 2, Calculate('*', 1, 2));
    EXPECT_EQ( 0, Calculate('*', 0, 1));
    EXPECT_EQ(-1, Calculate('*', 1, -1));

    EXPECT_EQ( 2, Calculate('/', 4, 2));
    EXPECT_EQ( 0, Calculate('/', 0, 1));
    EXPECT_EQ(-1, Calculate('/', 1, -1));
    EXPECT_EQ(.5, Calculate('/', 1, 2));
}

TEST(WeekOneCalculatorTests, CalculateMethodErrors)
{
    try
    {
        double result = Calculate('/', 1, 0);
    }
    catch (std::exception& e)
    {
        std::string expected("Error: Division by zero");
        std::string actual(e.what());
        EXPECT_EQ(expected, actual);
    }
}