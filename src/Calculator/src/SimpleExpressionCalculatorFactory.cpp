
////////////////////////////////////////////////////////////////////////////
/**
 *  @file   SimpleExpressionCalculatorFactory.cpp
 *  @date   Thu June 3 2021
 *  @brief  
 */
////////////////////////////////////////////////////////////////////////////

#include <memory>
#include <sstream>

#include "AddCalculator.h"
#include "DivideCalculator.h"
#include "MultiplyCalculator.h"
#include "SimpleExpressionCalculatorFactory.h"
#include "SubtractCalculator.h"

namespace calculator
{
    std::unique_ptr<ICalculator> SimpleExpressionCalculatorFactory::createCalculator(std::string mathExpression) 
    {
        std::unique_ptr<ICalculator> result = nullptr;

        std::stringstream expStream(mathExpression);
        int leftTerm, rightTerm;
        char operation;

        expStream >> leftTerm >> operation >> rightTerm;
        if(expStream)
        {
            switch(operation)
            {
                // TODO refactor this as result = std::unique_ptr<AddCalculator>(rightterm, leftterm)
                // see  suggestions from Max
                case AddCalculator::operation:
                {
                    result = std::unique_ptr<ICalculator>(new AddCalculator(leftTerm, rightTerm));
                    break;
                }
                case SubtractCalculator::operation:
                {
                    result = std::unique_ptr<ICalculator>(new SubtractCalculator(leftTerm, rightTerm));
                    break;
                }
                case MultiplyCalculator::operation:
                {
                    result = std::unique_ptr<ICalculator>(new MultiplyCalculator(leftTerm, rightTerm));
                    break;
                }
                case DivideCalculator::operation:
                {
                    result = std::unique_ptr<ICalculator>(new DivideCalculator(leftTerm, rightTerm));
                    break;
                }
                default:
                {
                    result = nullptr;
                }
            }
        }

        return result;
    }
}