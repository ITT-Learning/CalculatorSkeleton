/**
 * @file calculatorW2Gtest.cpp
 * @author Gary Dean Jenkins (gary.jenkins@intimetec.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/CalculatorW2.h"
#include "../inc/CalculatorStrings.h"

using namespace calculatorw2;

/**
 * @brief Do the support MAth and Control operators exist with the expected characters?
 * 
 */
TEST(WeekTwoCalculatorW2Tests, TheRequiredMathAndControlOperatorsMustBeSupported)
{
    EXPECT_EQ((char)Operators::UNKNOWN, 'u');
    EXPECT_EQ((char)Operators::NOOP, 'n');
    EXPECT_EQ((char)Operators::HELP, 'h');
    EXPECT_EQ((char)Operators::QUIT, 'q');
    EXPECT_EQ((char)Operators::ADD, '+');
    EXPECT_EQ((char)Operators::SUBTRACT, '-');
    EXPECT_EQ((char)Operators::MULTIPLY, '*');
    EXPECT_EQ((char)Operators::DIVIDE, '/');
}

/**
 * @brief Is the default state of the calculator clean/without error?
 * 
 */
TEST(WeekTwoCalculatorW2Tests, WhenACalculatorW2IsCreatedThenTheErrorMustBeNull)
{
    CalculatorW2 calculatorW2;

    EXPECT_EQ(calculatorW2.getError(), nullptr);
}

/**
 * @brief Does the add method correctly calculate the valid range of results?
 * 
 */
TEST(WeekTwoCalculatorW2Tests, WhenTwoNumbersAreAddedTheResultMustBeCorrect)
{
    CalculatorW2 calculatorw2;

    EXPECT_DOUBLE_EQ(calculatorw2.add(2, 2), 4);
    EXPECT_DOUBLE_EQ(calculatorw2.add(1, -2), -1);
    EXPECT_DOUBLE_EQ(calculatorw2.add(1, -1), 0);
    EXPECT_DOUBLE_EQ(calculatorw2.add(1.001, 1.11), 2.111);
}

/**
 * @brief Does the subtract method correctly calculate the valid range of results?
 * 
 */
TEST(WeekTwoCalculatorW2Tests, WhenTwoNumbersAreSubtractedTheResultMustBeCorrect)
{
    CalculatorW2 calculatorw2;

    EXPECT_DOUBLE_EQ(calculatorw2.subtract(2, 1), 1);
    EXPECT_DOUBLE_EQ(calculatorw2.subtract(1, 1), 0);
    EXPECT_DOUBLE_EQ(calculatorw2.subtract(1, 2), -1);
    EXPECT_DOUBLE_EQ(calculatorw2.subtract(2.111, 1.11), 1.001);
}

/**
 * @brief Does the multiply method correctly calculate the valid range of results?
 * 
 */
TEST(WeekTwoCalculatorW2Tests, WhenTwoNumbersAreMultipliedTheResultMustBeCorrect)
{
    CalculatorW2 calculatorw2;

    EXPECT_DOUBLE_EQ(calculatorw2.multiply(1, 1), 1);
    EXPECT_DOUBLE_EQ(calculatorw2.multiply(1, 0), 0);
    EXPECT_DOUBLE_EQ(calculatorw2.multiply(1, -1), -1);
    EXPECT_DOUBLE_EQ(calculatorw2.multiply(2, 1.111), 2.222);
}

/**
 * @brief Does the divide method correctly calculate the valid range of results?
 * 
 */
TEST(WeekTwoCalculatorW2Tests, WhenTwoNumbersAreDividedTheResultMustBeCorrect)
{
    CalculatorW2 calculatorw2;

    EXPECT_DOUBLE_EQ(calculatorw2.divide(1, 1), 1);
    EXPECT_DOUBLE_EQ(calculatorw2.divide(0, 1), 0);
    EXPECT_DOUBLE_EQ(calculatorw2.divide(1, -1), -1);
    EXPECT_DOUBLE_EQ(calculatorw2.divide(2.222, 2), 1.111);
}

/**
 * @brief Do valid calculations correctly return a nullptr indicating no errors?
 * 
 */
TEST(WeekTwoCalculatorW2Tests, WhenValidMathOperationArePErformedThenTheErrorMustBeNull)
{
    CalculatorW2 calculatorw2;

    calculatorw2.add(1, 1);
    EXPECT_EQ(calculatorw2.getError(), nullptr);
    calculatorw2.subtract(0, 1);
    EXPECT_EQ(calculatorw2.getError(), nullptr);
    calculatorw2.multiply(1, -1);
    EXPECT_EQ(calculatorw2.getError(), nullptr);
    calculatorw2.divide(2.222, 2);
    EXPECT_EQ(calculatorw2.getError(), nullptr);
}

/**
 * @brief Does a divide by zero correctly return a divide by zero error string?
 * 
 */
TEST(WeekTwoCalculatorW2Tests, WhenInvalidCalculationsArePerformedThenTheAppropriateErrorMustBeSet)
{
    CalculatorW2 calculatorW2;

    calculatorW2.divide(1, 0);
    EXPECT_STREQ(calculatorW2.getError(), divideByZeroError);
}
