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
<<<<<<< HEAD
                result = std::unique_ptr<ICalculator>(new AddCalculator(firstNumber, secondNumber));
=======
                result = std::make_unique<AddCalculator>(firstNumber, secondNumber);
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
                break;
            }
            case CalculatorStrings::MINUS :
            {
<<<<<<< HEAD
                result = std::unique_ptr<ICalculator>(new SubtractCalculator(firstNumber, secondNumber));
=======
                result = std::make_unique<SubtractCalculator>(firstNumber, secondNumber);
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
                break;
            }
            case CalculatorStrings::TIMES :
            {
<<<<<<< HEAD
                result = std::unique_ptr<ICalculator>(new MultiplyCalculator(firstNumber, secondNumber));
=======
                result = std::make_unique<MultiplyCalculator>(firstNumber, secondNumber);
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
                break;
            }
            case CalculatorStrings::DIVIDE :
            {
<<<<<<< HEAD
                result = std::unique_ptr<ICalculator>(new DivideCalculator(firstNumber, secondNumber));
=======
                result = std::make_unique<DivideCalculator>(firstNumber, secondNumber);
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
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
