///////////////////////////////////////////////////////////
/**
 * @file AddCalculator.cpp
 * @brief implementing Add Calculator
 */
/////////////////////////////////////////////////////////

#include "AddCalculator.h"

namespace calculator {

// ***************************************************************************** /
// ***************** AddCalculator Constructor ********************************* /
// ***************************************************************************** /

AddCalculator::AddCalculator(float firstNumber, float secondNumber)
{
    firstNumber_ = firstNumber; 
    secondNumber_ = secondNumber;
    operator_ = CalculatorStrings::PLUS;
}

// ***************************************************************************** /
// ***************** AddCalculator public methods ****************************** /
// ***************************************************************************** /

float AddCalculator::getResult()
{
    return firstNumber_ + secondNumber_;
}

} // namespace calculator
