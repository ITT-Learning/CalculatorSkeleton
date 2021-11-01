//////////////////////////////////////////////////////////////////
/**
 * @file DivideCalculator.cpp
 * @brief Implementing Divide Calculator
 */
//////////////////////////////////////////////////////////////////

#include "DivideCalculator.h"

namespace calculator {

// ***************************************************************************** /
// ***************** DivideCalculator Constructor *******************************/
// ***************************************************************************** /

DivideCalculator::DivideCalculator(float firstNumber, float secondNumber)
{
    firstNumber_ = firstNumber; 
    secondNumber_ = secondNumber;
    operator_ = CalculatorStrings::DIVIDE;
}

// ***************************************************************************** /
// ***************** DivideCalculator public methods ****************************/
// ***************************************************************************** /

float DivideCalculator::getResult() const
{
    int result = 0;
    if(secondNumber_ == 0) //if second number = 0, output error message
    {
        std::cerr << CalculatorStrings::ERROR_MESSAGE_DIVIDE_BY_ZERO << std::endl;
        result = -1;
    }
    else
    {
        result = firstNumber_ / secondNumber_; //else, return first variable divided by the second
    }
    
    return result;
}

std::string const DivideCalculator::toString()
{
    return std::to_string(firstNumber_) + CalculatorStrings::EMPTY_SPACE + operator_ + CalculatorStrings::EMPTY_SPACE + std::to_string(secondNumber_) + CalculatorStrings::EQUAL_SIGN + std::to_string(getResult());
}


} // namespace calculator
