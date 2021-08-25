/**
 * @file SubtractionOperatorGtest.cpp
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
#include "../inc/SubtractionOperator.h"

using namespace Calculator;

TEST(Week3SubtractionOperatorTests, SubtractionoOperatorIsImplementableAndHappyPathFunctional)
{
    SubtractionOperator so;

    EXPECT_EQ(so.GetOpSymbol().Id(), "-");

    std::string test = "1.0 - -2.0";
    EXPECT_EQ(so.eval(test), true);
    EXPECT_EQ(test, "3.000000");

    test = "1.0 - 2.0";
    EXPECT_EQ(so.eval(test), true);
    EXPECT_EQ(test, "-1.000000");
}