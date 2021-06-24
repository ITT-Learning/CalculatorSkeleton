////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "CalculatorApplication.h"

#define PLAY 0

int main()
{
#if PLAY
    calculator::CalculatorApplication::playground();
#else
    calculator::CalculatorApplication::run();
#endif
    return 0;
}

