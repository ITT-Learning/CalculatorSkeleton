
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CustomCalculatorFactory.cpp
 *  @date   Thu June 3 2021
 *  @brief  Factory for CustomCalculator
 */
////////////////////////////////////////////////////////////////////////////

#include <memory>
#include <sstream>

#include "CustomCalculatorFactory.h"
#include "CustomCalculator.h"


namespace calculator
{
    template class CustomCalculatorFactory<int>;
    template class CustomCalculatorFactory<double>;
    template class CustomCalculatorFactory<float>;
    template <class T>
    CustomCalculatorFactory<T>::CustomCalculatorFactory(std::function<T(std::vector<T>)> func, std::string expressionFormat)
            : function_(func), expressionFormat_(std::move(expressionFormat))
    {
        argCount_ = findArgCount();
    }

    template <class T>
    std::unique_ptr<ICalculatorTemplate<T>> CustomCalculatorFactory<T>::createCalculator(std::string mathExpression) const
    {
        //TODO would it make sense to create an ERROR calculator instead of returning nullptr? Clean code principle?
        std::unique_ptr<ICalculatorTemplate<T>> calculator = nullptr;
        std::stringstream expStream(mathExpression);

        std::vector<T> terms;
        T i;
        while(expStream >> i)
        {
            terms.push_back(i);
        }
        if(terms.size() == argCount_)
        {
            calculator = std::make_unique<CustomCalculator<T>>(terms, function_, expressionFormat_);
            count_++;
        }
        return calculator;
    }

    template<class T>
    int CustomCalculatorFactory<T>::findArgCount() const
    {
        int openBracketCount = 0;
        int closeBracketCount = 0;
        for (char i : expressionFormat_)
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