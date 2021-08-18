/**
 * @file IUnaryOperatorGtest.cpp
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

#include "../inc/IUnaryOperator.h"

using namespace Calculator;

TEST(Week3IUnaryOperatorTests, IUnaryOperatorIsImplementableAsABaseClass)
{
    class TestOp: public IUnaryOperator
    {
        public:
            TestOp() : IUnaryOperator(OpSymbols.at("abs")) {}
            virtual double calculate(double input) { return (input < 0) ? (-1 * input) : input; } 
    };

    TestOp to;

    EXPECT_EQ(to.GetOpSymbol().Id, "abs");
    EXPECT_EQ(to.findString(), "(abs) [^ ]+");

    std::string test = "abs -2.0";
    EXPECT_EQ(to.eval(test), true);
    EXPECT_EQ(test, "2.000000");

    test = "abs 2.0";
    EXPECT_EQ(to.eval(test), true);
    EXPECT_EQ(test, "2.000000");
}