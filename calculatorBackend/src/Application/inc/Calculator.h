#ifndef CALCULATOR_H
#define CALCULATOR_H

////////////////////////////////////////////////////////////////////////////////
/**
* @file Calculator.h
* @brief calculator function declarations.
*/
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <utility>

#include "History.h"
#include "history_generated.h"
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
         * @param [in] history a pointer to a created history class usd to track completed expressions
        */
        std::pair <std::string,bool> runCalculator(std::string webInput);

        /**
         * @brief Runs a switch statement with entered operator to calculate 2 numbers
         * @param [in] parsedExpression an expression object containing 2 numbers and an operators
         * @return the calculated float answer
        */
        float calculate(const Expression &parsedExpression);

        /**
         * @brief checks user input to see if they want to calculate again, quit, or view history
         * @param [in] history is a created history class used to track completed expressions
         * @return bool for whether or not calculator should keep running
        */
        bool restart(const std::shared_ptr<calculator::History> &history);
};

} //namespace calculator

#endif //CALCULATOR_H
