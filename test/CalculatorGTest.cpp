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
