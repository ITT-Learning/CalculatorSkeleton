///////////////////////////////////////////////////////////////////////////////
/**
 * @file  ICalculator.h
 * @date  Wed, 2 June 2021
 * @brief Interface for calculator objects
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ICALCULATOR_H
#define ICALCULATOR_H

#include <string>

namespace calculator 
{
    class ICalculator
    {
        public:
            /**
             * @brief Destroy the ICalculator object
             * 
             */
            virtual ~ICalculator() = default;

            /**
             * @brief The expression or left side of the equation, e.g. "5 + 5"
             * 
             * @return std::string 
             */
            virtual std::string getExpression() const = 0;

            /**
             * @brief the solved result or right side, of the equation
             * 
             * @return int - result of operation
             */
            virtual int getResult() const = 0;

            /**
             * @brief The full equation representation, e.g. "5 + 5 = 10"
             * 
             * @return std::string representation of object
             */
            virtual std::string toString() const = 0;
    };
}
#endif  // ICALCULATOR_H
