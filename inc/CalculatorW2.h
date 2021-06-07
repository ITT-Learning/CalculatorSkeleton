///////////////////////////////////////////////////////////////////////////////
/**
 * @file  CalculatorW2.h
 * @date  Fri, 16 April 2021
 * @brief 
 * 
 */
///////////////////////////////////////////////////////////////////////////////

#ifndef CALCULATORW2_H
#define CALCULATORW2_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "CalculatorStrings.h"
// Add your function declarations here.
namespace calculator {
    class CalculatorW2 {
        public:
            /**
             * @brief operations usuable in the calculator
             * @note operations added here should be added to validOperations_ as well
             * 
             */
            enum class Operation: char
            {
                ADD      = '+',
                DIVIDE   = '/',
                MULTIPLY = '*',
                SUBTRACT = '-'
            };

            /**
             * @brief Construct a new CalculatorW2 object = default
             * 
             */
            CalculatorW2();

            /**
             * @brief Construct a new CalculatorW2 object using a math expression
             * 
             * @param mathExpression The math expression should be a string that is leftTerm, space, operation, space rightTerm
             *                       e.g., '5 + 5'
             */
            explicit CalculatorW2(const std::string &mathExpression);

            /**
             * @brief Construct a new CalculatorW2 object using set left and right terms and operation.
             * 
             * @param leftTerm first term in math expression
             * @param rightTerm second term in math expression
             * @param operation operation in math expression
             */
            explicit CalculatorW2(int leftTerm, int rightTerm, Operation operation);

            /**
             * @brief Destroy the CalculatorW2 object = default
             * 
             */
            ~CalculatorW2();

            /**
             * @brief Get the current result
             * 
             * @return int 
             */
            int getResult();
            
        private:
            int leftTerm_                      = 0;
            int rightTerm_                     = 0;
            int result_                        = 0;
            Operation operation_               = Operation::ADD;
            bool hasError_                     = false;
            std::string errorMessage_          = CalculatorStrings::EMPTY_STRING;
            std::vector<char> validOperations_ { (char)Operation::ADD,
                                                (char)Operation::SUBTRACT,
                                                (char)Operation::MULTIPLY, 
                                                (char)Operation::DIVIDE };
            /**
             * @brief add two terms together
             * 
             * @param leftTerm [in] first term
             * @param rightTerm [in] second term
             * @return int = leftTerm + rightTerm 
             */
            int add(int leftTerm, int rightTerm);

            /**
             * @brief divide the leftTerm by the rightTerm
             * @note will set the error flag and update error message if attempting to divide by zero
             * 
             * @param leftTerm [in] numerator
             * @param rightTerm [in] denominator 
             * @return int = leftTerm / rightTerm
             *               0 , if attempting to divide by zero
             */
            int divide(int leftTerm, int rightTerm);

            /**
             * @brief multiply two terms together
             * 
             * @param leftTerm [in] first term
             * @param rightTerm [in] seconds term
             * @return int = leftTerm * rightTerm
             */
            int multiply(int leftTerm, int rightTerm);

            /**
             * @brief subtract the rightTerm from the leftTerm
             * 
             * @param leftTerm [in] first term
             * @param rightTerm [in] second term
             * @return int = leftTerm - rightTerm
             */
            int subtract(int leftTerm, int rightTerm);
            
            /**
             * @brief set result_ by calculating the math expression using leftTerm, rightTerm, and operation
             *        this will need to be called if any of those members are set manually
             * 
             */
            void calculateResult();

            /**
             * @brief The full equation of the calculator
             * @note this is a friend method and is styled like std::to_string functions
             *       I chose this implementation instead of the member function calculator.toString()
             *       way only because I wanted to understand friends better
             * 
             * @param calculator [in] the calculator to see the full equation
             * @return std::string formatted like "5 + 5 = 10" or
             *                     "leftTerm_ operation_ rightTerm_ = result_"
             */
            friend std::string to_string(const CalculatorW2& calculator);

            /**
             * @brief simple overloaded << to work with std::ostream's
             * 
             * @param os [out] 
             * @param calculator [in] calculator to be added using to_string(calculator)
             * @return std::ostream& 
             */
            friend std::ostream& operator<<(std::ostream& os, const CalculatorW2& calculator);
    };
}
#endif  // CALCULATORW2_H
