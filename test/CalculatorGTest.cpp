////////////////////////////////////////////////////////////////////////////////
/**
* @file CalculatorGTest.cpp
* @brief unit tests for the calculator
*/
////////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include "CalculatorMessages.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cmath>

using namespace calculator;
using namespace testing;

class whenTestingCalculator:public ::testing::Test
{
    public:
        Calculator* calculatorInst;
        virtual void SetUp() override;
        virtual void TearDown() override;
};
void whenTestingCalculator::SetUp()
{
    calculatorInst = new Calculator();
}
void whenTestingCalculator::TearDown()
{
    delete calculatorInst;
}

TEST_F(whenTestingCalculator, WhenValidatingTwoPositiveIntegers_ThenTrueReturned)
{
    ASSERT_TRUE(calculatorInst->validateInput("1+1"));
}
TEST_F(whenTestingCalculator, WhenValidatingIncorrectOperation_ThenFalseReturned)
{
    ASSERT_FALSE(calculatorInst->validateInput("1?1"));
}
TEST_F(whenTestingCalculator, WhenValidatingTwoNegativeIntegers_ThenTrueReturned)
{
    ASSERT_TRUE(calculatorInst->validateInput("-1+-1"));
}
TEST_F(whenTestingCalculator, WhenValidatingTwoPositiveFloats_ThenTrueReturned)
{
    ASSERT_TRUE(calculatorInst->validateInput("1.55*30.43"));
}
TEST_F(whenTestingCalculator, WhenValidatingTwoNegativeFloats_ThenTrueReturned)
{
    ASSERT_TRUE(calculatorInst->validateInput("-44.34--0.43"));
}
TEST_F(whenTestingCalculator, WhenValidatingANonNumber_ThenFalseReturned)
{
    ASSERT_FALSE(calculatorInst->validateInput("-b/15"));
}
TEST_F(whenTestingCalculator, WhenValidatingNonNumbersInFrontOfNumbers_ThenFalseReturned)
{
    ASSERT_FALSE(calculatorInst->validateInput("abc123*xyz123"));
}
TEST_F(whenTestingCalculator, WhenAddingPositiveAndNegativeIntegers_ThenCorrectValueReturned)
{
    ASSERT_FLOAT_EQ(calculatorInst->calculate('+', -10, 10), 0);
}
TEST_F(whenTestingCalculator, WhenSubtractingPositiveAndNegativeIntegers_ThenCorrectValueReturned)
{
    ASSERT_FLOAT_EQ(calculatorInst->calculate('-', -10, 10), -20);
}
TEST_F(whenTestingCalculator, WhenDividingPositiveAndNegativeIntegers_ThenCorrectValueReturned)
{
    ASSERT_FLOAT_EQ(calculatorInst->calculate('/', -10, 10), -1);
}
TEST_F(whenTestingCalculator, WhenMultiplyingAndNegativeIntegers_ThenCorrectValueReturned)
{
    ASSERT_FLOAT_EQ(calculatorInst->calculate('*', -10, 10), -100);
}
TEST_F(whenTestingCalculator, WhenDividingByZero_ThenInfIsTrue)
{
    ASSERT_TRUE(std::isinf(calculatorInst->calculate('/', 1, 0)));
}
