#include "ConsoleIo.h"

#include <iostream>
#include <memory>
#include <string>

#include <boost/algorithm/string.hpp>

#include "ExpressionFactory.h"
#include "IExpression.h"

namespace calculator {

template<typename T>
bool ConsoleIo<T>::handleInput()
{
    bool result{false};
    std::cout << "Please enter a mathematical expression (like 4 - 3 or "
            "12 * (x + 4)), or enter [Q]uit to quit: " << std::endl;
    std::string input;
    std::getline(std::cin, input);
    boost::algorithm::to_lower(input);
    if("quit" == input || "q" == input)
    {
        result = true;
    }
    else
    {
        handleNonQuittingInput(input);
    }
    
    return result;
}

template<typename T>
void ConsoleIo<T>::handleNonQuittingInput(const std::string &input)
{
    auto expression = calculator::expression::ExpressionFactory<T>::
            parseFromComplexString(input);
    if(expression)
    {
        bindSymbols(expression);
        auto optionalValue = expression->calculateExpression();
        if(optionalValue)
        {
            std::cout << "= " << *optionalValue << std::endl;
        }
        else
        {
            std::cout << "A problem happened during calculation. Did you "
                    "divide by zero?" << std::endl;
        }
    }
    else
    {
        std::cout << "Expression could not be parsed. Double-check that it is "
                "typed correctly." << std::endl; 
    }
}

template<typename T>
void ConsoleIo<T>::bindSymbols(std::unique_ptr<calculator::expression::IExpression<T>> &inputExpression)
{
    std::set<char> symbols;
    inputExpression->collectUnboundSymbols(symbols);
    if(!symbols.empty())
    {
        std::cout << "There were some symbols in the expression you entered. Enter a value for each of the symbols "
                "below." << std::endl;
        for(char symbol : symbols)
        {
            T value;
            bool gotValue = false;
            while(!gotValue)
            {
                std::cout << symbol << " = ";
                if(std::cin >> value)
                {
                    gotValue = true;
                }
                else
                {
                    std::cout << "Please enter a valid number." << std::endl;
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            auto outputExpression = inputExpression->bindValueToSymbol(symbol, value);
            if(nullptr != outputExpression)
            {
                inputExpression = std::move(outputExpression);
            }
        }
    }
}

template class ConsoleIo<int>;
template class ConsoleIo<double>;

}