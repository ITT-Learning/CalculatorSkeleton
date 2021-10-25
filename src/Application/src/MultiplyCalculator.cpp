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

float MultiplyCalculator::getResult()
{
    return firstNumber_ * secondNumber_; //return variables multiplied by each other 
}

} // namespace calculator
