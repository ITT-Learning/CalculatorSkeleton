////////////////////////////////////////////////////////////////////
/**
 * @file CalculatorApplicationFactory.cpp
 * @brief Functions that support main.cpp
 */
////////////////////////////////////////////////////////////////////

#include "AddCalculator.h"
#include "CalculatorApplicationFactory.h"
#include "DivideCalculator.h"
#include "MultiplyCalculator.h"
#include "SubtractCalculator.h"

namespace calculator {

// *****************************************************************************/
// ***************** CalculatorApplicationFactory public methods **********************/
// *****************************************************************************/

std::unique_ptr<ICalculator> CalculatorApplicationFactory::createCalculator(float firstNumber, float secondNumber, char operation)
{
    std::unique_ptr<ICalculator> result = nullptr; //create calculator type pointer and point to null
    {
        switch (operation) //switch case decides which calculator to return 
        {
            case CalculatorStrings::PLUS :
            {
                result = std::unique_ptr<ICalculator>(new AddCalculator(firstNumber, secondNumber));
                break;
            }
            case CalculatorStrings::MINUS :
            {
                result = std::unique_ptr<ICalculator>(new SubtractCalculator(firstNumber, secondNumber));
                break;
            }
            case CalculatorStrings::TIMES :
            {
                result = std::unique_ptr<ICalculator>(new MultiplyCalculator(firstNumber, secondNumber));
                break;
            }
            case CalculatorStrings::DIVIDE :
            {
                result = std::unique_ptr<ICalculator>(new DivideCalculator(firstNumber, secondNumber));
                break;
            } 
            default:
            {
                result = nullptr; //if operation doesn't meet one of the cases, return pointing to null
            }
        }

        return result; 
    }
}   

} //namespace calculator
