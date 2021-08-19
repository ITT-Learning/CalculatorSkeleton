/**
 * @file DivisionOperatorGtest.cpp
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
#include "../inc/DivisionOperator.h"

using namespace Calculator;

TEST(Week3DivisionOperatorTests, DivisionOperatorIsImplementableAndHappyPathFunctional)
{
    DivisionOperator divop;

    EXPECT_EQ(divop.GetOpSymbol().Id(), "/");
    EXPECT_EQ(divop.findString(), "[^ ]+ (/) [^ ]+");

    std::string test = "3.0 / -2.0";
    EXPECT_EQ(divop.eval(test), true);
    EXPECT_EQ(test, "-1.500000");

    test = "-1.0 / -2.0";
    EXPECT_EQ(divop.eval(test), true);
    EXPECT_EQ(test, "0.500000");

    test = "-1.0 / 0";
    EXPECT_EQ(divop.eval(test), true);
    EXPECT_EQ(test, "-inf");
}