
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   SimpleExpressionCalculatorW3Factory.cpp
 *  @date   Thu June 3 2021
 *  @brief  
 */
////////////////////////////////////////////////////////////////////////////

#include <sstream>
#include <memory>

#include "SimpleExpressionCalculatorW3Factory.h"
#include "AddCalculatorW3.h"
#include "SubtractCalculatorW3.h"
#include "MultiplyCalculatorW3.h"
#include "DivideCalculatorW3.h"

namespace calculator
{
    std::unique_ptr<ICalculatorW3> SimpleExpressionCalculatorW3Factory::createCalculator(std::string mathExpression) 
    {
        std::stringstream expStream(mathExpression);
        int leftTerm, rightTerm;
        char operation;

        expStream >> leftTerm >> operation >> rightTerm;
        if(expStream)
        {
            switch(operation)
            {
                case AddCalculatorW3::operation:
                {
                    return std::unique_ptr<ICalculatorW3>(new AddCalculatorW3(leftTerm, rightTerm));
                    break;
                }
                case SubtractCalculatorW3::operation:
                {
                    return std::unique_ptr<ICalculatorW3>(new SubtractCalculatorW3(leftTerm, rightTerm));
                    break;
                }
                case MultiplyCalculatorW3::operation:
                {
                    return std::unique_ptr<ICalculatorW3>(new MultiplyCalculatorW3(leftTerm, rightTerm));
                    break;
                }
                case DivideCalculatorW3::operation:
                {
                    return std::unique_ptr<ICalculatorW3>(new DivideCalculatorW3(leftTerm, rightTerm));
                    break;
                }
            }
        }

        return nullptr;
    }
}