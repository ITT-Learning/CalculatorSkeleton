////////////////////////////////////////////////////////////////////////////////
/**
* @file ResultFactory.cpp
* @brief Function definitions for Result Factory
*/
////////////////////////////////////////////////////////////////////////////////

#include "Result.h"
#include "ResultFactory.h"
#include <sstream>
#include <iostream>
#include "CalculatorMessages.h"


namespace calculator
{

//*************/
// ResultFactory public methods /
///
   
    Result ResultFactory::CreateResult(const Expression &parsedExpression, const float &answer)
    {
        Result result;
        result.expression = parsedExpression;
        result.answer = answer;
        std::stringstream ss;
        ss << parsedExpression.a << CalculatorMessages::EMPTY_SPACE << parsedExpression.operation << CalculatorMessages::EMPTY_SPACE << parsedExpression.b << CalculatorMessages::EQUALS << answer << std::endl;
        result.fullResult = ss.str();
        return result;
    }
    
}