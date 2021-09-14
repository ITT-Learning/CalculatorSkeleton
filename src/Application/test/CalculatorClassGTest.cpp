#include "CalculatorApplcation.h"
#include "CalculatorStrings.h"
#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace calculator;
using namespace testing;


class whenTestingCalculator:public ::testing::Test
{
    public:
        Calculator* calculator;
        virtual void SetUp() override;
        virtual void TearDown() override;
};
void whenTestingCalculator::SetUp()
{
    calculator = new Calculator();
}
void whenTestingCalculator::TearDown()
{
    delete calculator;
}
TEST_F(whenTestingCalculator, WhenCallingDivideWithPositiveFloatingPoints_ThenCorrectValueReturn){
    ASSERT_FLOAT_EQ(calculator->divide(10.0f, 5.0f), 2.0f);
}

TEST_F(whenTestingCalculator, WhenCallingDivideWithPositiveIntegers_ThenCorrectValueReturn){
    ASSERT_EQ(calculator->divide(10.0, 5.0), 2.0);
}

TEST_F(whenTestingCalculator, WhenCallingDivideByZeroTest_ReturnDivideByZeroError){
    ASSERT_FLOAT_EQ(-1.0, calculator->divide(10.0f, 0.0f));
}
TEST_F(whenTestingCalculator, WhenCallingDividewithNegativeFloatingPoints_ThenCorrectPositiveValueReturn){
    ASSERT_FLOAT_EQ(calculator->divide(-10.0f, -10.0f),1.0f);
}

TEST_F(whenTestingCalculator, WhenCallingAddWithPositiveFloatingPoints_ThenCorrectPositiveValueReturn){
    ASSERT_FLOAT_EQ(calculator->add(10.0f, 5.0f), 15.0f);
}

TEST_F(whenTestingCalculator, WhenCallingAddWithNegativeFloatingPoints_ThenCorrectNegativeValueReturn){
    ASSERT_FLOAT_EQ(calculator->add(-10.0f, -5.0f), -15.0f);
}

TEST_F(whenTestingCalculator, WhenCallingMultiplyWithPositiveFloatingPoints_ThenCorrectPositiveValueReturn){
    ASSERT_FLOAT_EQ(calculator->multiply(10.0f, 5.0f), 50.0f);
}

TEST_F(whenTestingCalculator, WhenCallingMultiplyWithPositiveAndNegativeFloatingPoints_ThenCorrectNegativeValueReturn){
    ASSERT_FLOAT_EQ(calculator->multiply(10.0f, -5.0f), -50.0f);
}

TEST_F(whenTestingCalculator, WhenCallingMultiplyWithNegativeFloatingPoints_ThenCorrectPositiveValueReturn){
    ASSERT_FLOAT_EQ(calculator->multiply(-10.0f, -5.0f), 50.0f);
}

TEST_F(whenTestingCalculator, WhenCallingSubtractWithPositiveFloatingPoints_ThenCorrectPositiveValueReturn){
    ASSERT_FLOAT_EQ(calculator->subtract(10.0f, 5.0f), 5.0f);
}

TEST_F(whenTestingCalculator, WhenCallingSubtractWithNegativeFloatingPoints_ThenCorrectPositiveValueReturn){
    ASSERT_FLOAT_EQ(calculator->subtract(-10.0f, -15.0f), 5.0f);
}

TEST_F(whenTestingCalculator, modulusTest){
    ASSERT_FLOAT_EQ(calculator->modulus(10.0f, 5.0f), 0.0f);
}