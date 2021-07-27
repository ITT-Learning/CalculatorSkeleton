/**
 * @file ioStreamCalculatorW2Gtest.cpp
 * @author Gary Dean Jenkins (gary.jenkins@intimetec.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include "../inc/IoStreamCalculatorW2.h"
#include "../inc/CalculatorStrings.h"

using namespace calculatorw2;

TEST(WeekTwoIoStreamCalculatorW2Tests, WhenMathAndControlFunctionsAreEnteredThenTheExpectedOutputIsCorrect)
{
    std::string inputString("2 + 5\n5 - 3\n1.1 * 6\n3.33 / 1.11\n1 / 0\nq");
    std::istringstream inputStream(inputString);
    std::ostringstream outputStream;

    IoStreamCalculatorW2 ioStreamCalculatorW2(inputStream, outputStream);
    ioStreamCalculatorW2.Run();
    EXPECT_EQ(outputStream.str(), "= 7\n= 2\n= 6.6\n= 3\nError: Division by zero\nQuitting!\n");
}