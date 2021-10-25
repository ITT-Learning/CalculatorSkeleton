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

float DivideCalculator::getResult()
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

} // namespace calculator
