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
    sampleExpression.a = -10;
    sampleExpression.b = 10;
    
};
void whenTestingCalculator::TearDown()
{
    delete calculatorInst;
}

TEST_F(whenTestingCalculator, WhenAddingPositiveAndNegativeIntegers_ThenCorrectValueReturned)
{
    sampleExpression.operation = '+';
    ASSERT_FLOAT_EQ(calculatorInst->calculate(sampleExpression), 0);
}
TEST_F(whenTestingCalculator, WhenSubtractingPositiveAndNegativeIntegers_ThenCorrectValueReturned)
{
    sampleExpression.operation = '-';
    ASSERT_FLOAT_EQ(calculatorInst->calculate(sampleExpression), -20);
}
TEST_F(whenTestingCalculator, WhenDividingPositiveAndNegativeIntegers_ThenCorrectValueReturned)
{
    sampleExpression.operation = '/';
    ASSERT_FLOAT_EQ(calculatorInst->calculate(sampleExpression), -1);
}
TEST_F(whenTestingCalculator, WhenMultiplyingAndNegativeIntegers_ThenCorrectValueReturned)
{
    sampleExpression.operation = '*';
    ASSERT_FLOAT_EQ(calculatorInst->calculate(sampleExpression), -100);
}
TEST_F(whenTestingCalculator, WhenDividingByZero_ThenInfIsTrue)
{
    sampleExpression.operation = '/';
    sampleExpression.b = 0;
    ASSERT_TRUE(std::isinf(calculatorInst->calculate(sampleExpression)));
}
