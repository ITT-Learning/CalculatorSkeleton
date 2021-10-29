#ifndef CALCULATOR_H
#define CALCULATOR_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.h
* @brief calculator function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Parser.h"
namespace calculator {

/**
* @brief Calculator interface which exposes to other components
*/

class Calculator
{
    public:
        /**
         * @brief initiates calculator and works with the parser to return a result object
        */
        void runCalculator();

        /**
         * @brief Runs a switch statement with entered operator to calculate 2 numbers
         * @param [in] parsedExpression an expression object containing 2 numbers and an operators
         * @return the calculated float answer
        */
        float calculate(const Expression &parsedExpression);
};

}//namespace calculator

#endif  // CALCULATOR_H
