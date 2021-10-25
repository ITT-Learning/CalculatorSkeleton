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

float SubtractCalculator::getResult()
{
    return firstNumber_ - secondNumber_; //returns second variable subtracted by first variable 
}

} // namespace calculator
