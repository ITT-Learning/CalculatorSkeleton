////////////////////////////////////////////////////////////////////////////////
/**
* @file Result.cpp
* @brief Function definitions for Result object
*/
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "Result.h"

namespace calculator {

Result::Result(std::string originalEquation, float answer, std::string fullResult) :
originalEquation_(originalEquation), answer_(answer), fullResult_(fullResult){}

// ************************************************************************* /
// ***************** Result public methods ********************************* /
// ************************************************************************* /
        
std::string Result::getFullResult() const
{
    return fullResult_;
}

} //namespace calculator
