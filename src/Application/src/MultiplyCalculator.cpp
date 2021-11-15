/////////////////////////////////////////////////////////
/**
 * @file MultiplyCalculator.cpp
 * @brief Implement Multiplication Calculator
 */
/////////////////////////////////////////////////////////

#include "MultiplyCalculator.h"

namespace calculator {

// ***************************************************************************** /
// ***************** MultiplyCalculator Constructor **************************** /
// ***************************************************************************** /

MultiplyCalculator::MultiplyCalculator(float firstNumber, float secondNumber)
{
    firstNumber_ = firstNumber; 
    secondNumber_ = secondNumber;
    operator_ = CalculatorStrings::TIMES;
}

// ***************************************************************************** /
// ***************** MultiplyCalculator public methods  ************************ /
// ***************************************************************************** /

float MultiplyCalculator::getResult() const
{
    return firstNumber_ * secondNumber_; //return variables multiplied by each other 
}

std::string const MultiplyCalculator::toString()
{
    return std::to_string(firstNumber_) + CalculatorStrings::EMPTY_SPACE + operator_ + CalculatorStrings::EMPTY_SPACE + 
           std::to_string(secondNumber_) + CalculatorStrings::EQUAL_SIGN + std::to_string(getResult());
}


} // namespace calculator
