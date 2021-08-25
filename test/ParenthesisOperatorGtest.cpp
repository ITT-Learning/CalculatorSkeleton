/**
 * @file ParenthesisOperatorGtest.cpp
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
#include "../inc/ParenthesisOperator.h"

using namespace Calculator;

TEST(Week3ParenthesisOperatorTests, ParenthesisoOperatorIsImplementableAndHappyPathFunctional)
{
    ParenthesisOperator po;

    EXPECT_EQ(po.GetOpSymbol().Id(), "(");
    EXPECT_EQ(po.findString(), "(\\()[^\\(\\)]+\\)");

    std::string test = "(1 + 2)";
    EXPECT_EQ(po.eval(test), true);
    EXPECT_EQ(test, "3.000000");

    test = "2 * (1 + 2) / 2";
    EXPECT_EQ(po.eval(test), true);
    EXPECT_EQ(test, "2 * 3.000000 / 2");

    test = "(2 + 3) * (1 + 2) / 2";
    EXPECT_EQ(po.eval(test), true);
    EXPECT_EQ(test, "5.000000 * (1 + 2) / 2");

    test = "2 + 3 * (1 + (2 * 5)) / 2";
    EXPECT_EQ(po.eval(test), true);
    EXPECT_EQ(test, "2 + 3 * (1 + 10.000000) / 2");
}

TEST(Week3ParenthesisOperatorTests, ParenthesisoOperatorHelpIsFunctional)
{
    ParenthesisOperator abso;
    EXPECT_EQ(abso.help(), HELP_PARENTHESIS_OPERATOR);
}