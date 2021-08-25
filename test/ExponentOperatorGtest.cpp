/**
 * @file ExponentOperatorGtest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <regex>
#include <iostream>
#include "../inc/ExponentOperator.h"

using namespace Calculator;

TEST(Week3ExponentOperatorTests, ExponentoOperatorIsImplementableAndHappyPathFunctional)
{
    ExponentOperator expo;

    EXPECT_EQ(expo.GetOpSymbol().Id(), "^");

    std::string test = "-3.0 ^ 2.0";
    EXPECT_EQ(expo.eval(test), true);
    EXPECT_EQ(test, "9.000000");

    test = "-2.0 ^ 3.0";
    EXPECT_EQ(expo.eval(test), true);
    EXPECT_EQ(test, "-8.000000");
}

TEST(Week3ExponentOperatorTests, ExponentoOperatorHelpIsFunctional)
{
    ExponentOperator abso;
    EXPECT_EQ(abso.help(), HELP_EXPONENT_OPERATOR);
}