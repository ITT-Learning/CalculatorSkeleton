///////////////////////////////////////////////////
/**
 * @file SubtractCalculatorGTest.cpp
 * @brief Unit tests for subtract calculator
 */
///////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<limits>

#include "CalculatorApplication.h"
#include "CalculatorApplicationFactory.h"
#include "CalculatorStrings.h"
#include "SubtractCalculator.h"

using namespace calculator;
using namespace testing;

class whenTestingSubtractCalculator : public :: testing :: Test
{

};

/**
 * @brief Unit test to make sure subtraction with positive floating points works
 * 
 */
TEST_F(whenTestingSubtractCalculator, WhenCallingSubtractWithPositiveFloatingPoints_ThenCorrectPositiveValueReturn)
{
    SubtractCalculator subCalc = SubtractCalculator(10.0, 5.0);
    float result = subCalc.getResult();
    EXPECT_FLOAT_EQ(5.0, result);
}

/**
 * @brief Unit test to make sure subtraction with negative floating points works
 * 
 */
TEST_F(whenTestingSubtractCalculator, WhenCallingSubtractWithNegativeFloatingPoints_ThenCorrectPositiveValueReturn)
{
    SubtractCalculator subCalc = SubtractCalculator(-10.0, -5.0);
    float result = subCalc.getResult();
    EXPECT_FLOAT_EQ(-5.0, result);
}
