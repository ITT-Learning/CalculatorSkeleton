/**
 * @file CalculatorResources.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CALCULATORRESOURCES_H
#define CALCULATORRESOURCES_H

#include <map>
#include <vector>

namespace Calculator
{
    enum OPORDER { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX };

    const std::string REGEX_DOUBLE = "[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?";
    const std::string REGEX_DOUBLE_CAPTURE = "([-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?)";
    const std::string REGEX_DOUBLE_ANCHORED = "^[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?$";

    const std::string HELP_ABSOLUTE_OPERATOR = "Absolute value: \"abs -2\" = 2";
    const std::string HELP_ADDITION_OPERATOR = "Addition: \"1 + 2\" = 3";
    const std::string HELP_SUBTRACTION_OPERATOR = "Subtraction: \"1 - 2\" = -1";
    const std::string HELP_MULTIPLICATION_OPERATOR = "Multiplication: \"2 * 2\" = 4";
    const std::string HELP_DIVISION_OPERATOR = "Division: \"5 / 2\" = 2.5";
    const std::string HELP_EXPONENT_OPERATOR = "Exponent: \"2 ^ 3\" = 8";
    const std::string HELP_SQUARE_ROOT_OPERATOR = "Square Root: Ex. \"sqrt 9\" = 3";
    const std::string HELP_INVERSE_OPERATOR = "Inverse: \"inv 2\" = 0.5";
    const std::string HELP_EVALUATE_OPERATOR = "Evaluate: \"eval 1 + 2\" = 3";
    const std::string HELP_PARENTHESIS_OPERATOR = "Parenthesis: \"2 * (3 + 4)\" = 17";
    const std::string HELP_TRACE_OPERATOR = "Trace(tron or troff): turns on/off order of operation tracing: tron 2 * (3 + 4) troff -> displays all subcalculations and results";
}

#endif //CALCULATORRESOURCES_H