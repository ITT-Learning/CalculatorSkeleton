///////////////////////////////////////////////////////////////////////////////
/**
 * @file  ICalculatorTemplate.h
 * @date  Wed, 9 June 2021
 * @brief Interface for calculator objects of type T
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef ICALCULATORTEMPLATE_H
#define ICALCULATORTEMPLATE_H

#include <string>

namespace calculator 
{
    template <typename T>
    class ICalculatorTemplate
    {
        public:
            /**
             * @brief Destroy the ICalculatorTemplate object
             *
             */
            virtual ~ICalculatorTemplate() = default;

            /**
             * @brief The expression or left side of the equation
             *
             * @return std::string
             */
            virtual std::string getExpression() const = 0;

            /**
             * @brief the solved result or right side, of the equation
             *
             * @return T - result of operation
             */
            virtual T getResult() const = 0;

            /**
             * @brief The full equation representation, e.g. "5 + 5 = 10"
             * @warning If implementing this interface you will need to make sure T can be converted to a string
             *
             * @return std::string full equation of the calculator
             */
            virtual std::string toString() const = 0;
    };
}
#endif  // ICALCULATORTEMPLATE_H
