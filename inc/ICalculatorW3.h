///////////////////////////////////////////////////////////////////////////////
/**
 * @file  ICalculatorW3.h
 * @date  Wed, 2 June 2021
 * @brief Interface for calculator objects
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ICALCULATORW3_H
#define ICALCULATORW3_H

#include <string>

namespace calculator 
{
    class ICalculatorW3
    {
        public:
            /**
             * @brief Destroy the ICalculatorW3 object
             * 
             */
            virtual ~ICalculatorW3() = default;
            /**
             * @brief The expression or left side of the equation, e.g. "5 + 5"
             * 
             * @return std::string 
             */
            virtual std::string getExpression() = 0;
            /**
             * @brief the solved result or right side, of the equation
             * 
             * @return int - result of operation
             */
            virtual int getResult() = 0;
            /**
             * @brief The full equation representation, e.g. "5 + 5 = 10"
             * 
             * @return std::string representation of object
             */
            virtual std::string toString() = 0;
    };
}
#endif  // ICALCULATORW3_H
