///////////////////////////////////////////////////
/**
 * @file LimitCalculatorGTest.cpp
 * @brief Unit tests for checking limits with calculator
 */
///////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<limits>

#include "CalculatorApplication.h"
#include "CalculatorApplicationFactory.h"
#include "CalculatorStrings.h"

using namespace calculator;
using namespace testing;

class whenTestingLimitCalculator : public :: testing :: Test
{

};

/**
 * @brief Unit test to make sure max input is caught
 * 
 */
TEST(whenTestingLimitCalculator, WhenCallingCalculateWithMaxFloatingPoints_ThenCorrectErrorReturned)
{
    int result = CalculatorApplication::calculate(3.40283e+038, 3.40283e+038,'+');
    EXPECT_EQ(-1, result);
}

/**
 * @brief Unit test to make sure min input is caught
 * 
 */
TEST(whenTestingLimitCalculator, WhenCallingCalculateWithMinFloatingPoints_ThenCorrectErrorReturned)
{
    int result = CalculatorApplication::calculate(1.17548e-038, 1.17548e-038,'+');
    EXPECT_EQ(-1, result);
}

/**
 * @brief Unit test to make sure infinite input is caught
 * 
 */
TEST(whenTestingLimitCalculator, WhenCallingCalculateWitInfiniteFloatingPoints_ThenCorrectErrorReturned)
{
    int result = CalculatorApplication::calculate(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(),'+');
    EXPECT_EQ(-1, result);
}
