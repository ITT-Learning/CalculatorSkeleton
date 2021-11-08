#ifndef ICALCULATOR_H
#define ICALCULATOR_H

/////////////////////////////////////////////////////
/**
 * @file ICalculator.h
 * @brief Interface used by main
 */
/////////////////////////////////////////////////////

#include <iostream>
#include <string>

#include <CalculatorStrings.h>

namespace calculator {
class ICalculator 
{
    public:
        /**
         * @brief Destroy the ICalculator object
         * 
         */
        ~ICalculator() = default;

        /**
         * @brief Get the Result object. Pure virtual function defined in child classes
         * @return float after value calculated has been returned
         */
        virtual float getResult() const = 0;

        /**
         * @brief Convert to string function (output)
         * 
         * @return convert calculator output and functionality std::toString
         */
        virtual std::string const toString() = 0;
};
    
} // namespace calculator

#endif //ICALCULATOR_H
