#include "ConsoleIo.h"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <flatbuffers/flatbuffers.h>

#include "ExpressionSerializer.h"
#include "ExpressionFactory.h"
#include "IExpression.h"

namespace calculator {

template<typename T>
bool ConsoleIo<T>::handleInput(std::vector<typename expression::ExpressionSerializer<T>::ExpressionBuffer> &savedExpressions)
{
    bool result{false};
    
    std::cout << "Enter [N]ew to add a new expression to the list of remembered expressions, [E]valuate to pick and "
            "evaluate a remembered expression, or [Q]uit to quit the program." << std::endl;
    std::string input;
    std::getline(std::cin, input);
    boost::algorithm::to_lower(input);
    if("new" == input || "n" == input)
    {
        handleNewExpressionInput(savedExpressions);
    }
    else if("evaluate" == input || "e" == input)
    {
        handleEvaluateExpressionInput(savedExpressions);
    }
    else if("quit" == input || "q" == input)
    {
        result = true;
    }
    else
    {
        std::cout << "I didn't understand that command. Try again." << std::endl;
    }
    
    return result;
}

template<typename T>
void ConsoleIo<T>::handleNewExpressionInput(std::vector<typename expression::ExpressionSerializer<T>::ExpressionBuffer> &savedExpressions)
{
    std::cout << "Enter a mathematical expression (like 4 - 3 or 12 * (x + 4)): " << std::endl;
    std::string input;
    std::getline(std::cin, input);
    auto expression = calculator::expression::ExpressionFactory<T>::
            parseFromComplexString(input);
    if(nullptr != expression)
    {
        auto serializedExpressionBuffer = expression::ExpressionSerializer<T>::serialize(*expression);
        savedExpressions.push_back(std::move(serializedExpressionBuffer));
    }
    else
    {
        std::cout << "Expression could not be understood. Double-check that it is "
                "typed correctly." << std::endl; 
    }
}

template<typename T>
void ConsoleIo<T>::handleEvaluateExpressionInput(const std::vector<typename expression::ExpressionSerializer<T>::ExpressionBuffer> &savedExpressions)
{
    std::cout << "Saved expressions:" << std::endl;
    for(size_t i = 0; i < savedExpressions.size(); i++)
    {
        auto currentExpression = expression::ExpressionSerializer<T>::deserialize(savedExpressions[i]);
        if(nullptr != currentExpression)
        {
            std::cout << std::to_string(i + 1) << ". " << currentExpression->toString() << std::endl;
        }
    }
    std::cout << "Pick an expression above to evaluate:" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::stringstream inputStream{input};
    size_t index;
    if(inputStream >> index)
    {
        index--;
        if(index < savedExpressions.size())
        {
            // We could probably trade some memory (above), storing all the deserialized expressions, so that we don't have
            // to call deserialize again here. It's the classic CPU/memory tradeoff.
            auto chosenExpression = expression::ExpressionSerializer<T>::deserialize(savedExpressions[index]);
            bindSymbols(chosenExpression);
            auto optionalValue = chosenExpression->calculateExpression();
            if(boost::none != optionalValue)
            {
                std::cout << chosenExpression->toString() << " = " << *optionalValue << std::endl;
            }
            else
            {
                std::cout << "A problem happened during calculation. Did you divide by zero?" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "The number you entered wasn't listed above." << std::endl;
    }
}

template<typename T>
void ConsoleIo<T>::bindSymbols(std::unique_ptr<expression::IExpression<T>> &inputExpression)
{
    std::set<char> symbols;
    inputExpression->collectUnboundSymbols(symbols);
    if(!symbols.empty())
    {
        std::cout << "There were some symbols in the expression you chose. Enter a value for each of the symbols "
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