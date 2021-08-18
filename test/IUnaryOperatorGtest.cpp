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
            TestOp() : IUnaryOperator(OPORDER::ZERO, "PLUS1") {}
            virtual double calculate(double input) { return input + 1.0; } 
    };

    TestOp to;

    EXPECT_EQ(to.OpOrder(), OPORDER::ZERO);
    EXPECT_EQ(to.OpRegex(), "PLUS1 [^ ]+");

    std::string test = "PLUS1 -2.0";
    EXPECT_EQ(to.eval(test), true);
    EXPECT_EQ(test, "-1.000000");

    test = "PLUS1 2.0";
    EXPECT_EQ(to.eval(test), true);
    EXPECT_EQ(test, "3.000000");
}