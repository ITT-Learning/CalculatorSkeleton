/**
 * @file SquareRootOperatorGtest.cpp
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

#include "../inc/SquareRootOperator.h"

using namespace Calculator;

TEST(Week3SquareRootOperatorTests, SquareRootoOperatorIsImplementableAndHappyPathFunctional)
{
    SquareRootOperator sqrto;

    EXPECT_EQ(sqrto.GetOpSymbol().Id(), "sqrt");
    EXPECT_EQ(sqrto.findString(), "(sqrt) [^ ]+");

    std::string test = "sqrt 9.0";
    EXPECT_EQ(sqrto.eval(test), true);
    EXPECT_EQ(test, "3.000000");

    test = "sqrt -4.0";
    EXPECT_EQ(sqrto.eval(test), true);
    EXPECT_EQ(test, "-nan");
}