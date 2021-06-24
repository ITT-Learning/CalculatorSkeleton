////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CompoundExpressionCalculator.h
 *  @date   Tue, June 15 2021
 *  @brief  Calculator that allows more than 2 terms
 *          Compound expression will be solved by order of operations
 *  @note   only simple operators are supported -- * / + -, parentheses and exponents are not supported
 */
////////////////////////////////////////////////////////////////////////////
#ifndef CALCULATOR_COMPOUNDEXPRESSIONCALCULATOR_H
#define CALCULATOR_COMPOUNDEXPRESSIONCALCULATOR_H

#include <regex>
#include <unordered_map>
#include <vector>

#include "AddCalculator.h"
#include "DivideCalculator.h"
#include "ICalculator.h"
#include "MultiplyCalculator.h"
#include "SimpleExpressionCalculatorFactory.h"
#include "SubtractCalculator.h"

namespace calculator
{
    class CompoundExpressionCalculator : public ICalculator
    {
        public:
            /**
             * @brief delete default constructor -- a calculator has to be made with inputs
             */
            CompoundExpressionCalculator() = delete;

            /**
             * @brief Make a calculator using a compound expression string
             * @param [in] compoundExpression Input should be formatted like this: "10 + 5 - -7 * -9 / 3" with numbers and operators
             */
            explicit CompoundExpressionCalculator(std::string compoundExpression);

            /**
             * @brief Make a calculator using a map of variables and a variableCompoundExpression
             * @param variables [in] move map of char to int you can use toVariableMap() to convert from string to map
             * @param variableCompoundExpression [in] move expression should be formatted "a + b - c / a * b"
             *                                        variables can be used many times
             */
            explicit CompoundExpressionCalculator(std::unordered_map<char, int> variables, std::string variableCompoundExpression);

            /**
             * @brief  get Expression or left side of equation
             * @note   Calculator made with a map will have the expression variables replaces with the numbers
             * @return std::string - left side of the equation - e.g. "10 + 5 - 3 * 1"
             */
            std::string getExpression() const final;

            /**
             * @brief get the solved result or right side of the equation
             * @return int the result of the equation
             */
            int getResult() const final;

            /**
             * @brief  get the full equation
             * @return std::string - e.g. "10 + 5 - 3 * 1 = 12"
             */
            std::string toString() const final;

            /**
             * @brief convert a list of variable string into a map
             * @param variables expected input should be "a = 1, b = 2, x = -100, y = 12"
             * @return std::unordered_map<char, int> - pairing of variable to value
             */
            static std::unordered_map<char, int> toVariableMap(const std::string& variables);

        private:
            SimpleExpressionCalculatorFactory calculatorFactory_;
            std::string                       compoundExpression_;
            std::unordered_map<char, int>     variableMap_           = std::unordered_map<char, int>();

            /**
             * @brief Calculates the result using threads and order of operations
             *        we'll capture the result in result_ since this can be a costly operation
             * @param resultExpression [in/out] passed to calculator result concurrently
             * @return the finished result
             */
            int computeResult(std::string &resultExpression) const;

            /**
             * @brief Replace function which can be used with formatResultExpression to take a simple expression with the result
             *        e.g. expecting "10 + 10", will solve it to 20, and then search resultExpression_ for "10 + 10 and replace it with 20
             * @param resultExpression [in/out] passed to calculator result concurrently
             * @param expression [in] - subexpression that needs solved and replaced
             */
            void replaceSubexpressionWithResultInResultExpression(std::string &resultExpression,
                                                                  const std::string &expression) const;

            /**
             * @brief Replace function which can be used with formatResultExpression to take a variable and replace with the value
             *        e.g. expecting "a" look it up in variableMap_ and then replace all "a"s with the value
             * @param resultExpression [in/out] passed to calculator result concurrently
             * @param variable [in] - variable to replace
             */
            void replaceVariableWithNumberInResultExpression(std::string &resultExpression,
                                                             const std::string &variable) const;

            /**
             * @brief Uses the regex to find matches in the resultExpression_ and will spin up threads to replace the matches
             * @param resultExpression [in/out] passed to calculator result concurrently
             * @param regex [in] regex to find that needs replaced
             * @param classReplaceFunction [in] A [private] CompoundExpressionFunction function pointer that takes a string of the match
             *                             the function is responsible for updating the string using threadedReplaceResultExpression
             * @note this is some confusing code that I don't really love. On one hand passing a function for being thread makes a lot of sense
             *       on the other-hand a member function pointer is a really confusing concept
             *       In addition we are expecting the function to call threadedReplaceResultExpression and there is really no safety
             *       that we can provide that would force that. Ideally this would be refactored.
             *       Doing it this way does reduce duplicating code since I can use the same code for replacing variables with values
             *       and I can use it for solving sub-expressions and replacing that, but in this case I think it actually hinders
             *       readability.
             */
            void formatResultExpression(std::string &resultExpression, const std::regex &regex,
                                        void (CompoundExpressionCalculator::*classReplaceFunction)(std::string &, const std::string &string) const) const;

            /**
             * @brief Safely handles updating resultExpression_ by threads using a mutex to lock reading and updating resultExpression_
             * @param resultExpression [in/out] passed to calculator result concurrently
             * @param replacement [in] what to replace matched substring
             * @param match [in] regex containing the substring that needs to be replaced
             */
            void threadedReplaceResultExpression(std::string &resultExpression,
                                                 const std::string &replacement,
                                                 const std::regex &match) const;

            /**
             * @brief Helper function to make the regex work. Since '+' and '*' are special characters we need to wrap
             *        them in square brackets to make the regex work.
             * @param expression [in] - simple math expression, e.g. "100 + 100"
             * @return std::string expression with operator wrapped in '[' ']', e.g. "100 [+] 100"
             *
             */
            static std::string expressionWrapOperator(const std::string &expression);
    };
}

#endif //CALCULATOR_COMPOUNDEXPRESSIONCALCULATOR_H
