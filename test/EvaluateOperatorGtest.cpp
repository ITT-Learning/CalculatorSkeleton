/**
 * @file EvaluateOperatorGtest.cpp
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
#include <vector>

#include "../inc/EvaluateOperator.h"

using namespace Calculator;

TEST(Week3EvaluateOperatorTests, EvaluateOperatorIsProperlyInstanciated)
{
    EvaluateOperator evalOp;
    OpSymbol evalOpSym = evalOp.GetOpSymbol();

    EXPECT_EQ(evalOpSym.Id(), "eval");
}

TEST(Week3EvaluateOperatorTests, EvaluateOperatorCorrectlyEvalsBasicOperators)
{
    EvaluateOperator evalOp;

    std::vector<std::pair<std::string, std::string>> inputsAndResults =
    {
        { "1 + 2", "3.000000" }, 
        { "1 - 2", "-1.000000" }, 
        { "2 * 3", "6.000000" }, 
        { "-2 / 3", "-0.666667" }, 
        { "2 ^ 3", "8.000000" }, 
        { "sqrt 16", "4.000000" }, 
        { "inv 2", "0.500000" }, 
        { "abs -2", "2.000000" }
    };

    for (auto iAr : inputsAndResults)
    {
        std::string input = iAr.first;
        EXPECT_EQ(evalOp.eval(input), true) << iAr.first;
        EXPECT_EQ(input, iAr.second) << iAr.first;
    }
}