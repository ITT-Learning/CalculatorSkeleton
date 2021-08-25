/**
 * @file AbsoluteOperatorGtest.cpp
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

#include "../inc/AbsoluteOperator.h"

using namespace Calculator;

TEST(Week3AbsoluteOperatorTests, AbsoluteoOperatorIsImplementableAndHappyPathFunctional)
{
    AbsoluteOperator abso;

    EXPECT_EQ(abso.GetOpSymbol().Id(), "abs");

    std::string test = "abs 2.0";
    EXPECT_EQ(abso.eval(test), true);
    EXPECT_EQ(test, "2.000000");

    test = "abs -0.5";
    EXPECT_EQ(abso.eval(test), true);
    EXPECT_EQ(test, "0.500000");

    test = "abs 0";
    EXPECT_EQ(abso.eval(test), true);
    EXPECT_EQ(test, "0.000000");

    test = "abs -0";
    EXPECT_EQ(abso.eval(test), true);
    EXPECT_EQ(test, "0.000000");
}