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

float AddCalculator::getResult() const
{
    return firstNumber_ + secondNumber_;
}

std::string const AddCalculator::toString()
{
    return std::to_string(firstNumber_) + CalculatorStrings::EMPTY_SPACE + operator_ + CalculatorStrings::EMPTY_SPACE + std::to_string(secondNumber_) + CalculatorStrings::EQUAL_SIGN + std::to_string(getResult());
}

} // namespace calculator
