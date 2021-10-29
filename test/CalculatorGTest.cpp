////////////////////////////////////////////////////////////////////////////////
/**
* @file CalculatorGTest.cpp
* @brief unit tests for the calculator
*/
////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Calculator.h"
#include "CalculatorMessages.h"
#include "Parser.h"

using namespace calculator;
using namespace testing;

class whenTestingCalculator:public ::testing::Test
{
    public:
        Calculator* calculatorInst;
        virtual void SetUp() override;
        virtual void TearDown() override;
    protected:
        Expression sampleExpression;

};
void whenTestingCalculator::SetUp()
{
    calculatorInst = new Calculator();
    sampleExpression.number1 = -10;
    sampleExpression.number2 = 10;
    
};
void whenTestingCalculator::TearDown()
{
    delete calculatorInst;
}

/**
* @brief Unit test for adding positive and negative integers
*/
TEST_F(whenTestingCalculator, WhenAddingPositiveAndNegativeIntegers_ThenCorrectValueReturned)
{
    sampleExpression.operation = CalculatorMessages::ADD;
    EXPECT_FLOAT_EQ(0, calculatorInst->calculate(sampleExpression));
}

/**
* @brief Unit test for subtracting positive and negative integers
*/
TEST_F(whenTestingCalculator, WhenSubtractingPositiveAndNegativeIntegers_ThenCorrectValueReturned)
{
    sampleExpression.operation = CalculatorMessages::SUBTRACT;
    EXPECT_FLOAT_EQ(-20, calculatorInst->calculate(sampleExpression));
}
/**
* @brief Unit test for dividing positive and negative integers
*/
TEST_F(whenTestingCalculator, WhenDividingPositiveAndNegativeIntegers_ThenCorrectValueReturned)
{
    sampleExpression.operation = CalculatorMessages::DIVIDE;
    EXPECT_FLOAT_EQ(-1, calculatorInst->calculate(sampleExpression));
}
/**
* @brief Unit test for multiplying positive and negative integers
*/
TEST_F(whenTestingCalculator, WhenMultiplyingPositiveAndNegativeIntegers_ThenCorrectValueReturned)
{
    sampleExpression.operation = CalculatorMessages::MULTIPLY;
    EXPECT_FLOAT_EQ(-100, calculatorInst->calculate(sampleExpression));
}

/**
* @brief Unit test for dividing by zero
*/
TEST_F(whenTestingCalculator, WhenDividingByZero_ThenInfIsTrue)
{
    sampleExpression.operation = CalculatorMessages::DIVIDE;
    sampleExpression.number2 = 0;
    EXPECT_TRUE(std::isinf(calculatorInst->calculate(sampleExpression)));
}
