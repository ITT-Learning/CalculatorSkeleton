////////////////////////////////////////////////////////////////////////////////
/**
* @file Result.cpp
* @brief Function definitions for Result object
*/
////////////////////////////////////////////////////////////////////////////////
#include "Result.h"
#include <iostream>

namespace calculator
{

//*************/
// ResultFactory public methods /
///
   
    void Result::returnResult()
    {
        std::cout << fullResult << std::endl;
    }

}