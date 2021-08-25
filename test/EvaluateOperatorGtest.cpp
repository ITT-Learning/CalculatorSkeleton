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
#include <regex>

#include "../inc/EvaluateOperator.h"
#include "OperatorFactory.h"

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
        {"-2", "-2"},
        {"abs(-2)", "2.000000"},
        { "1 + 2", "3.000000" }, 
        { "1 - 2", "-1.000000" }, 
        { "2 * 3", "6.000000" }, 
        { "-2 / 3", "-0.666667" }, 
        { "2 ^ 3", "8.000000" }, 
        { "sqrt 16", "4.000000" }, 
        { "inv 2", "0.500000" }, 
        { "abs -2", "2.000000" },
        { "abs -2", "2.000000" },
        { "1 + 2 - 5", "-2.000000" },
        { "2 * 3 - 5", "1.000000" },
        {"1 + 3 * 4 / 2", "7.000000"},
        {"(1 + 3) * 4 / 2", "8.000000"},
        {"((1 + 3) * 1) + 4 / 2", "6.000000"}
    };

    for (auto iAr : inputsAndResults)
    {
        std::string result = iAr.first;
        std::string expected = iAr.second;

        // std::cout << "INPUT1:\"" << result << "\"\n";
        // std::string opsRegex = " *(" + OperatorFactory::GetInstance()->GetOperatorOrRegex() + ") *";
        // std::regex e(opsRegex);
        // result = std::regex_replace(result, e, " $1 ");
        // std::cout << "INPUT2:\"" << result << "\"\n";

        // opsRegex = " (" + OperatorFactory::GetInstance()->GetOperatorOrRegex() + ") - ";
        // std::regex e2(opsRegex);
        // result = std::regex_replace(result, e2, " $1 -");
        // std::cout << "INPUT3:\"" << result << "\"\n";

        // std::regex e3(" +");
        // result = std::regex_replace(result, e3, " ");
        // std::cout << "INPUT4:\"" << result << "\"\n";

        EXPECT_EQ(evalOp.eval(result), true);
        EXPECT_EQ(result, expected)  << "    Equation: " + iAr.first << std::endl;
    }
}