/**
 * @file iOperatorGtest.cpp
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

#include "../inc/IOperator.h"

using namespace Calculator;

TEST(Week3IOperatorTests, IOperatorIsImplementableAsABaseClass)
{
    std::string OPREGEX = "Unevaluated\\(.+\\)";

    class TestOp: public IOperator
    {
        public:
            TestOp(): IOperator(OPORDER::ZERO, "Unevaluated\\(.+\\)") {}
            bool eval(std::string &input){
                unsigned loc = input.find("Une");
                input.replace(loc, 3, "E");
                return true;
            }
    };

    std::string test = "Unevaluated(stuff)";
    TestOp to;

    EXPECT_EQ(to.OpOrder(), OPORDER::ZERO);
    EXPECT_EQ(to.OpRegex(), OPREGEX);
    EXPECT_EQ(to.eval(test), true);
    EXPECT_EQ(test, "Evaluated(stuff)");
}