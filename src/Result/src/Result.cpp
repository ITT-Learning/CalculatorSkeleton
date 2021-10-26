////////////////////////////////////////////////////////////////////////////////
/**
* @file Result.cpp
* @brief Function definitions for Result object
*/
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "Result.h"

namespace calculator {

//*************/
// Result public methods /
///
   
std::string Result::getFullResult() const
{
    return fullResult_;
}

} //namespace calculator
