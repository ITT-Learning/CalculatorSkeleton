////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

//#include "Calculator.h"
#include "IoStreamCalculatorW2.h"

int main() 
{
    // Fill in or change code here as necessary.  See also Calculator.cpp
    //calculator::RunCalculator();

    calculatorw2::IoStreamCalculatorW2 ioStreamCalculatorW2;

    ioStreamCalculatorW2.OutputHelloAndHelp();
    ioStreamCalculatorW2.Run();
}