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

<<<<<<< HEAD
class whenTestingAddCalculator : public :: testing :: Test
{

};

=======
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
/**
 * @brief Unit test to make sure Addition with positive floating points works
 * 
 */
<<<<<<< HEAD
TEST_F(whenTestingAddCalculator, WhenCallingAddWithPositiveFloatingPoints_ThenCorrectPositiveValueReturn)
=======
TEST(whenTestingAddCalculator, WhenCallingAddWithPositiveFloatingPoints_ThenCorrectPositiveValueReturn)
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
{
    AddCalculator addCalc = AddCalculator(10.0, 5.0);
    float result = addCalc.getResult();
    EXPECT_FLOAT_EQ(result, 15.0);
}

/**
 * @brief Unit test to make sure Addition with negative floating points works
 * 
 */
<<<<<<< HEAD
TEST_F(whenTestingAddCalculator, WhenCallingAddWithNegativeFloatingPoints_ThenCorrectNegativeValueReturn)
=======
TEST(whenTestingAddCalculator, WhenCallingAddWithNegativeFloatingPoints_ThenCorrectNegativeValueReturn)
>>>>>>> 2085be165f0cff9b9b8d290c375838c98aaaabb9
{
    AddCalculator addCalc = AddCalculator(-10.0, -5.0);
    float result = addCalc.getResult();
    EXPECT_FLOAT_EQ(result, -15.0);
}
