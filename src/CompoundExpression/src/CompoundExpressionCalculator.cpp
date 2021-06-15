////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CompoundExpressionCalculator.cpp
 *  @date   Tue, June 15 2021
 *  @brief  Definitions for calculator that allows more than 2 terms
 */
////////////////////////////////////////////////////////////////////////////

#include <regex>
#include <thread>
#include <utility>
#include <mutex>
#include <iostream>
#include <sstream>

#include "CompoundExpressionCalculator.h"
#include "CalculatorStrings.h"

namespace calculator
{
    CompoundExpressionCalculator::CompoundExpressionCalculator(std::string compoundExpression)
            :compoundExpression_(std::move(compoundExpression))
    {
        resultExpression_ = compoundExpression_;
        result_ = computeResult();
    }

    CompoundExpressionCalculator::CompoundExpressionCalculator(std::unordered_map<char, int> variables,
                                                               std::string variableCompoundExpression)
            :variableMap_(std::move(variables)) ,resultExpression_(std::move(variableCompoundExpression))
    {
        for(auto varPair : variableMap_)
        {
            //create the regex for filtering
            std::string regexPattern(1, varPair.first);
            std::regex charRegex(regexPattern, std::regex_constants::ECMAScript);
            formatResultExpression(charRegex, &CompoundExpressionCalculator::replaceVariableWithNumberInResultExpression);
        }
        compoundExpression_ = resultExpression_;
        result_ = computeResult();
    }

    std::string CompoundExpressionCalculator::getExpression() const
    {
        return compoundExpression_;
    }

    int CompoundExpressionCalculator::getResult() const
    {
        return result_;
    }

    std::string CompoundExpressionCalculator::toString() const
    {
        return getExpression() + CalculatorStrings::EQUAL + std::to_string(result_);
    }

    std::unordered_map<char, int> CompoundExpressionCalculator::toVariableMap(const std::string& variables)
    {
        typedef std::pair<char,int> varPair;
        std::unordered_map<char, int> map;
        std::regex regex(CalculatorStrings::REGEX_PATTERN_VARIABLE_VALUE_PAIR, std::regex_constants::ECMAScript);

        auto match_begin = std::sregex_iterator (variables.begin(), variables.end(), regex);
        auto match_end = std::sregex_iterator();
        for(std::sregex_iterator i = match_begin; i != match_end; i++)
        {
            std::string match = (*i).str();
            char key = match[0];
            int value;
            // variable expression look like 'a=1000' or 'b = 1000', find '=' then add 1 to get just the number
            // we then sstream >> it to get rid of whitespace
            auto numberStart = match.rfind('=') + 1;
            std::stringstream ss(match.substr(numberStart));
            ss >> value;
            if (map.find(key) == map.end())
            {
                map.insert(varPair(key, value));
            }
            else
            {
                map.at(key) = value;
            }
        }
        return map;
    }

    int CompoundExpressionCalculator::computeResult()
    {
        int result = 0;
        std::regex addSubtractRegex(CalculatorStrings::REGEX_PATTERN_ADD_SUBTRACT_EXPRESSION, std::regex_constants::ECMAScript);
        std::regex multiplyDivideRegex(CalculatorStrings::REGEX_PATTERN_MULTIPLY_DIVIDE_EXPRESSION, std::regex_constants::ECMAScript);

        formatResultExpression(multiplyDivideRegex,
                               &CompoundExpressionCalculator::replaceSubexpressionWithResultInResultExpression);
        formatResultExpression(addSubtractRegex,
                               &CompoundExpressionCalculator::replaceSubexpressionWithResultInResultExpression);
        try
        {
            result = std::stoi(resultExpression_);
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << CalculatorStrings::INVALID_INPUT << std::endl << e.what() << std::endl;
        }
        if (std::to_string(result) != resultExpression_)
        {
            std::cerr << CalculatorStrings::INVALID_INPUT << std::endl;
        }
        return result;
    }

    void CompoundExpressionCalculator::formatResultExpression(const std::regex &regex,
                                                              void (CompoundExpressionCalculator::*classReplaceFunction)(const std::string &))
    {
        std::vector<std::thread> threads;

        auto match_begin = std::sregex_iterator(resultExpression_.begin(), resultExpression_.end(), regex);
        auto match_end = std::sregex_iterator();
        while(distance(match_begin, match_end))
        {
            for (std::sregex_iterator i = match_begin; i != match_end; i++)
            {
                threads.emplace_back(classReplaceFunction, this, (*i).str());
            }
            for (auto &thread : threads)
            {
                thread.join();
            }

            //cleanup for next loop
            threads.clear();
            match_begin = std::sregex_iterator(resultExpression_.begin(), resultExpression_.end(), regex);
            match_end = std::sregex_iterator();
        }
    }

    void CompoundExpressionCalculator::replaceSubexpressionWithResultInResultExpression(const std::string &expression)
    {
        //get the result from the expression
        auto c = calculatorFactory_.createCalculator(expression);
        std::string result = std::to_string(c->getResult());

        //create the regex for filtering
        std::string escaped_expression = expressionWrapOperator(expression);
        std::regex expressionRegex(escaped_expression, std::regex_constants::ECMAScript | std::regex_constants::icase);

        threadedReplaceResultExpression(result, expressionRegex);
    }

    void CompoundExpressionCalculator::replaceVariableWithNumberInResultExpression(const std::string &variable)
    {
        std::string result = std::to_string(variableMap_.at(variable[0]));
        std::regex charRegex(variable, std::regex_constants::ECMAScript);
        threadedReplaceResultExpression(result, charRegex);
    }

    void CompoundExpressionCalculator::threadedReplaceResultExpression(const std::string &replacement,
                                                                       const std::regex &match)
    {
        //static mutex
        static std::mutex expressionMutex;
        //lock while reading and updating the resultExpression
        expressionMutex.lock();
        std::string new_expression = regex_replace(resultExpression_, match, replacement,
                                                   std::regex_constants::format_first_only);
        resultExpression_ = new_expression;
        expressionMutex.unlock();
    }

    std::string CompoundExpressionCalculator::expressionWrapOperator(const std::string &expression)
    {
        std::regex operatorRegex(CalculatorStrings::REGEX_PATTERN_OPERATOR_FROM_SIMPLE_EXPRESSION,
                                 std::regex_constants::ECMAScript);
        std::string escExpression = std::regex_replace(expression, operatorRegex,
                                                       CalculatorStrings::REGEX_PATTERN_REPLACE_SURROUND_WITH_BRACKET,
                                                       std::regex_constants::format_first_only);
        return escExpression;
    }
}