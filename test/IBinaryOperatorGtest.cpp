/**
 * @file iUnaryOperatorGtest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <regex>
#include <iostream>
#include "../inc/IBinaryOperator.h"

using namespace Calculator;

TEST(Week3IBinaryOperatorTests, IBinaryOperatorIsImplementableAsABaseClass)
{
    class TestOp: public IBinaryOperator
    {
        public:
            TestOp() : IBinaryOperator(OpSymbol("+", OPORDER::FIVE, true)) {}
            virtual double calculate(double left, double right) { return left + right; } 
    };

    TestOp to;

    EXPECT_EQ(to.GetOpSymbol().Id(), "+");
    EXPECT_EQ(to.findString(), "[^ ]+ *(\\+) *[^ ]+");

    std::string test = "1.0 + -2.0";
    EXPECT_EQ(to.eval(test), true);
    EXPECT_EQ(test, "-1.000000");

    test = "1.0 + 2.0";
    EXPECT_EQ(to.eval(test), true);
    EXPECT_EQ(test, "3.000000");
}