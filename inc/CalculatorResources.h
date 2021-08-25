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

    const std::string HELP_ABSOLUTE_OPERATOR = "abs - absolute value - Ex. \"abs -2\" = 2\\n";
    const std::string HELP_ADDITION_OPERATOR = "+ - addition - Ex. \"1 + 2\" = 3\\n";
    const std::string HELP_SUBTRACTION_OPERATOR = "- - subtraction - Ex. \"1 - 2\" = -1\\n";
    const std::string HELP_MULTIPLICATION_OPERATOR = "* - multiplication - Ex. \"2 * 2\" = 4\\n";
    const std::string HELP_DIVISION_OPERATOR = "/ - division - Ex. \"5 / 2\" = 2.5\\n";
    const std::string HELP_EXPONENT_OPERATOR = "^ - exponent - Ex. \"2 ^ 3\" = 8\\n";
    const std::string HELP_SQUARE_ROOT_OPERATOR = "sqrt - square root- Ex. \"sqrt 9\" = 3\\n";
    const std::string HELP_INVERSE_OPERATOR = "inv - inverse - Ex. \"inv 2\" = 0.5\\n";
    const std::string HELP_EVALUATE_OPERATOR = "eval {implicit, do not use} - evaluate - Ex. \"eval 1 + 2\" = 3\\n";
    const std::string HELP_PARENTHESIS_OPERATOR = "( - parenthesis - Ex. \"2 * (3 + 4)\" = 17\\n";
    const std::string HELP_TRACE_OPERATOR = "tron or troff - turns on/off order of operation tracing - Ex. tron 2 * (3 + 4) troff -> displays all subcalculations and results\\n";
}

#endif //CALCULATORRESOURCES_H