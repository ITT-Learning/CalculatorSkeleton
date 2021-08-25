/**
 * @file MultiplicationOperatorGtest.cpp
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
#include "../inc/MultiplicationOperator.h"

using namespace Calculator;

TEST(Week3MultiplicationOperatorTests, MultiplicationoOperatorIsImplementableAndHappyPathFunctional)
{
    MultiplicationOperator mo;

    EXPECT_EQ(mo.GetOpSymbol().Id(), "*");

    std::string test = "3.0 * -2.0";
    EXPECT_EQ(mo.eval(test), true);
    EXPECT_EQ(test, "-6.000000");

    test = "-1.0 * -2.0";
    EXPECT_EQ(mo.eval(test), true);
    EXPECT_EQ(test, "2.000000");
}