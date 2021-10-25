////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri August 25 2021
 *  @brief  This is a basic calculator program which asks for an equation and uses a switch to decifer what the equation is and return the result
 */
////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cmath>
#include <future>
#include <iostream>
#include <sstream>
#include <thread>
#include <typeinfo>
#include <vector>

#include "CalculatorApplication.h"
#include "CalculatorStrings.h"
#include "Parser.h"

using namespace calculator;

/**
 * @brief Main interface which exposes to other components
 *
 */
int main() 
{
    bool again = true;

    while(again)
    {
        Parser parser;
        float answer;
        Expression parsedExpression;

        auto tempVector = std::async(&Parser::createVector, parser, parser.getUserInput());
        while(tempVector.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
        {
            std::cout << CalculatorStrings::BUILDING_VECTORS;
        }
        std::cout << std::endl;
        auto setVector = tempVector.get();

        while(setVector.second)
        {
            auto tempParsedExpression = std::async(&Parser::breakDownEquation, parser, setVector.first);
            while(tempParsedExpression.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
            {
                std::cout << CalculatorStrings::DISSECTING_AND_CALCULATING;
            }
            std::cout << std::endl;

            parsedExpression = tempParsedExpression.get();

            if(parsedExpression.validExpression)
            {
                answer = CalculatorApplication::calculate(parsedExpression.firstNumber, parsedExpression.secondNumber, parsedExpression.operation);
                ExpressionUnit prevAnswer;
                prevAnswer.number = answer;
                prevAnswer.valid = true;

                if(setVector.first->size() > 0)
                {
                    setVector.first->insert(setVector.first->begin() + parsedExpression.placementIndex, prevAnswer);
                }
                else
                {
                    break;
                }
                
            }
            else
            {
                std::cout << CalculatorStrings::ERROR_MESSAGE_INVALID_INPUT << std::endl;
                break;
            }

        }

        std::cout << CalculatorStrings::REPEAT_PROGRAM << std::endl;
        
        char repeat;      
        std::cin >> repeat; 
 
        if(repeat != CalculatorStrings::YES)
        {
            again = false;
        }
    }

    return 0;
    
} // namespace calculator
