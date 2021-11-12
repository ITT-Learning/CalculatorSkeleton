//////////////////////////////////////////////////
/**
 * @file SubtractCalculator.cpp
 * @brief Implement Subtract Calculator
 */
//////////////////////////////////////////////////

#include "SubtractCalculator.h"

namespace calculator {

// ***************************************************************************** /
// ***************** SubtractCalculator Constructor **************************** /
// ***************************************************************************** /

SubtractCalculator::SubtractCalculator(float firstNumber, float secondNumber)
{
    firstNumber_ = firstNumber; 
    secondNumber_ = secondNumber;
    operator_ = CalculatorStrings::MINUS;
}

// ********************************************************************************* /
// ***************** SubtractCalculator public methods ***************************** /
// ********************************************************************************* /

float SubtractCalculator::getResult() const
{
    return firstNumber_ - secondNumber_; //returns second variable subtracted by first variable 
}

std::string const SubtractCalculator::toString()
{
    return std::to_string(firstNumber_) + CalculatorStrings::EMPTY_SPACE + operator_ + CalculatorStrings::EMPTY_SPACE + 
           std::to_string(secondNumber_) + CalculatorStrings::EQUAL_SIGN + std::to_string(getResult());
}


} // namespace calculator
