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

#include "../inc/IBinaryOperator.h"

using namespace Calculator;

TEST(Week3IBinaryOperatorTests, IBinaryOperatorIsImplementableAsABaseClass)
{
    class TestOp: public IBinaryOperator
    {
        public:
            TestOp() : IBinaryOperator(OPORDER::ZERO, "MAX") {}
            virtual double calculate(double left, double right) { return left > right ? left : right; } 
    };

    TestOp to;

    EXPECT_EQ(to.OpOrder(), OPORDER::ZERO);
    EXPECT_EQ(to.OpRegex(), "[^& ]+ MAX [^ ]+");

    std::string test = "1.0 MAX -2.0";
    EXPECT_EQ(to.eval(test), true);
    EXPECT_EQ(test, "1.000000");

    test = "1.0 MAX 2.0";
    EXPECT_EQ(to.eval(test), true);
    EXPECT_EQ(test, "2.000000");
}