///////////////////////////////////////////////////
/**
 * @file AddCalculatorGTest.cpp
 * @brief Unit tests for Add Calculator
 */
///////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<limits>

#include "AddCalculator.h"
#include "CalculatorApplication.h"
#include "CalculatorApplicationFactory.h"
#include "CalculatorStrings.h"

using namespace calculator;
using namespace testing;

class whenTestingAddCalculator : public :: testing :: Test
{

};

/**
 * @brief Unit test to make sure Addition with positive floating points works
 * 
 */
TEST(whenTestingAddCalculator, WhenCallingAddWithPositiveFloatingPoints_ThenCorrectPositiveValueReturn)
{
    AddCalculator addCalc = AddCalculator(10.0, 5.0);
    float result = addCalc.getResult();
    EXPECT_FLOAT_EQ(result, 15.0);
}

/**
 * @brief Unit test to make sure Addition with negative floating points works
 * 
 */
TEST(whenTestingAddCalculator, WhenCallingAddWithNegativeFloatingPoints_ThenCorrectNegativeValueReturn)
{
    AddCalculator addCalc = AddCalculator(-10.0, -5.0);
    float result = addCalc.getResult();
    EXPECT_FLOAT_EQ(result, -15.0);
}
