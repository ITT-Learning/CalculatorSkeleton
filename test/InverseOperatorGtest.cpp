/**
 * @file InverseOperatorGtest.cpp
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

#include "../inc/InverseOperator.h"

using namespace Calculator;

TEST(Week3InverseOperatorTests, InverseoOperatorIsImplementableAndHappyPathFunctional)
{
    InverseOperator invo;

    EXPECT_EQ(invo.GetOpSymbol().Id(), "inv");
    EXPECT_EQ(invo.findString(), "(inv) [^ ]+");

    std::string test = "inv 2.0";
    EXPECT_EQ(invo.eval(test), true);
    EXPECT_EQ(test, "0.500000");

    test = "inv -0.5";
    EXPECT_EQ(invo.eval(test), true);
    EXPECT_EQ(test, "-2.000000");

    test = "inv 0";
    EXPECT_EQ(invo.eval(test), true);
    EXPECT_EQ(test, "inf");

    test = "inv -0";
    EXPECT_EQ(invo.eval(test), true);
    EXPECT_EQ(test, "-inf");
}