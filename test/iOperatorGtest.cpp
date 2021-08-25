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
#include "../inc/OpSymbol.h"

using namespace Calculator;

TEST(Week3IOperatorTests, IOperatorIsImplementableAsABaseClass)
{
    class TestOp: public IOperator
    {
        public:
            TestOp() : IOperator(OpSymbol("+", OPORDER::FOUR, true)) {}
            bool eval(std::string &input){
                unsigned loc = input.find(findString());
                input = "1";
                return true;
            }
            std::string findString() {return "1 " + GetOpSymbol().Regex() + " 1";}
            virtual const std::string help() {return "";}
    };

    std::string test = "1 + 1";
    TestOp to;

    EXPECT_EQ(to.GetOpSymbol().Id(), "+");
    EXPECT_EQ(to.findString(), "1 \\+ 1");
    EXPECT_EQ(to.eval(test), true);
    EXPECT_EQ(test, "1");
}