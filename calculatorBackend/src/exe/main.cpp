////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <memory>
#include <string>

#include "Calculator.h"
#include "CalculatorMessages.h"
#include "flatbuffers/util.h"
#include "History.h"

int main() 
{
    std::shared_ptr<calculator::History> history = std::make_shared<calculator::History>();
    
    bool running = true;
    while(running)
    {
        // calculator::Calculator calculator;
        // calculator.runCalculator(history);
        // running = calculator.restart(history);
    }

    return 0;
}
