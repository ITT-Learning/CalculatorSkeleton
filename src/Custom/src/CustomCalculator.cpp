
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CustomCalculator.cpp
 *  @date   Wed June 9 2021
 *  @brief
 */
////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <exception>

#include "CustomCalculator.h"
#include "CalculatorStrings.h"

namespace calculator
{
    template class CustomCalculator<int>;
    template class CustomCalculator<double>;
    template class CustomCalculator<float>;

    template <class T>
    CustomCalculator<T>::CustomCalculator(std::vector<T> terms, std::function<T(std::vector<T>)> func, std::string expressionFormat)
            : terms_(terms), function_(func), expression_(expressionFormat)
    {
        argCount_ = terms.size();
    }

    template <class T>
    std::string CustomCalculator<T>::getExpression() const
    {
        std::string s = "";
        if (findArgCount() == terms_.size())
        {
            fmt::dynamic_format_arg_store<fmt::format_context> store;
            for (int term : terms_)
            {
                store.push_back(term);
            }
            try
            {
                s = fmt::vformat(expression_, store);
            }
            catch (const std::exception &ex)
            {
                std::cerr << ex.what() << std::endl;
            }
        }
        else
        {
            std::cerr << "mismatched arguments" << std::endl;
        }
        return s;
    }

    template <class T>
    T CustomCalculator<T>::getResult() const
    {
        return function_(terms_);
    }

    template <class T>
    std::string CustomCalculator<T>::toString() const
    {
        std::stringstream ss;
        ss << getExpression() << CalculatorStrings::EQUAL << getResult();
        return ss.str();
    }

    template<class T>
    int CustomCalculator<T>::findArgCount() const
    {
        int openBracketCount = 0;
        int closeBracketCount = 0;
        for (char i : expression_)
        {
            if (i == '{')
            {
                openBracketCount++;
            }
            else if (i == '}')
            {
                closeBracketCount++;
            }
        }
        return std::min(openBracketCount, closeBracketCount);
    }
}