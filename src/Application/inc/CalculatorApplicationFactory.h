#ifndef CALCULATORAPPLICATIONFACTORY_H
#define CALCULATORAPPLICATIONFACTORY_H

////////////////////////////////////////////////////////////////
/**
 * @file CalculatorApplicationFactory.h
 * @brief Factory Pattern class
 */
//////////////////////////////////////////////////////////////

#include <memory>

#include "ICalculatorFactory.h"
<<<<<<< HEAD
namespace calculator {
    
    /**
    * @brief CalculatorFactory interface which exposes to other components
    *
    */
    class CalculatorApplicationFactory : public ICalculatorFactory
    {
        public:
        /**
         * @name ICalculatorFactory methods.
         * @{
         */

        std::unique_ptr<ICalculator> createCalculator(float firstNumber, float secondNumber, char operation) override;

        /**
         * @}
         */

    };
=======

namespace calculator {

/**
* @brief CalculatorFactory interface which exposes to other components
*
*/

class CalculatorApplicationFactory : public ICalculatorFactory
{
    public:
    /**
     * @name ICalculatorFactory methods.
     * @{
     */

    std::unique_ptr<ICalculator> createCalculator(float firstNumber, float secondNumber, char operation) override;

    /**
     * @}
     */

};
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9

}

#endif  // CALCULATORAPPLICATIONFACTORY_H
