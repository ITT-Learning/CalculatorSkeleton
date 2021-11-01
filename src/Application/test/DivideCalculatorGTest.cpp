///////////////////////////////////////////////////
/**
 * @file DivideCalculatorGTest.cpp
 * @brief Unit tests for Divide Calculator
 */
///////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<limits>

#include "CalculatorApplication.h"
#include "CalculatorApplicationFactory.h"
#include "CalculatorStrings.h"
#include "DivideCalculator.h"

using namespace calculator;
using namespace testing;

/**
 * @brief Unit test to make sure Division with positive floats works
 * 
 */
TEST(whenTestingDivideCalculator, WhenCallingDivideWithPositiveFloatingPoints_ThenCorrectValueReturn)
{
    DivideCalculator divideCalc = DivideCalculator(10.0, 5.0);
    float result = divideCalc.getResult();
/**
 * 
 */
TEST(whenTestingDivideCalculator, WhenCallingDivideWithPositiveAndNegativeFloatingPoints_ThenCorrectValueReturn)
{
    DivideCalculator divideCalc = DivideCalculator(-10.0, 5.0);
    float result = divideCalc.getResult();
    EXPECT_FLOAT_EQ(-2.0, result);
}

/**
 * @brief Unit test to make sure Division when dividing by zero returns error
 * 
 */
TEST(whenTestingDivideCalculator, WhenCallingDivideByZeroTest_ReturnDivideByZeroError){
    DivideCalculator divideCalc = DivideCalculator(10.0, 0.0);
    float result = divideCalc.getResult();
    EXPECT_FLOAT_EQ(-1, result);
}

/**
 * @brief Unit test to make sure Division with positive integers works
 * 
 */
TEST(whenTestingDivideCalculator, WhenCallingDivideWithPositiveIntegers_ThenCorrectValueReturn){
    DivideCalculator divideCalc = DivideCalculator(10, 5);
    float result = divideCalc.getResult();
    EXPECT_FLOAT_EQ(2, result);
}

/**
 * @brief Unit test to make sure Division with negative floating points works
 * 
 */
TEST(whenTestingDivideCalculator, WhenCallingDividewithNegativeFloatingPoints_ThenCorrectPositiveValueReturn){
    DivideCalculator divideCalc = DivideCalculator(-10.0, -5.0);
    float result = divideCalc.getResult();
    EXPECT_FLOAT_EQ(2.0, result);
}
