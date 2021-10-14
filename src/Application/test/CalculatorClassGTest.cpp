/**
 * @file CalculatorClassGTest.cpp
 * @brief 
 * @version 0.1
 * @date 2021-09-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<gtest/gtest.h>
#include<gmock/gmock.h>

/**
 * @brief header files included 
 * 
 */
#include "CalculatorApplicationFactory.h"
#include "DivideCalculator.h"
#include "MultiplyCalculator.h"
#include "SubtractCalculator.h"
#include "AddCalculator.h"
#include "CalculatorApplication.h"
#include "CalculatorStrings.h"
#include<limits>

using namespace calculator;
using namespace testing;


class whenTestingCalculator:public ::testing::Test
{
    public:
        CalculatorApplicationFactory* calculator;
        virtual void SetUp() override;
        virtual void TearDown() override;
};
void whenTestingCalculator::SetUp()
{
    calculator = new CalculatorApplicationFactory();
}
void whenTestingCalculator::TearDown()
{
    delete calculator;
}

/**
 * @brief Unit test to make sure Division with positive floats works
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingDivideWithPositiveFloatingPoints_ThenCorrectValueReturn)
{
    DivideCalculator divideCalc = DivideCalculator(10.0, 5.0);
    float result = divideCalc.getResult();
    ASSERT_FLOAT_EQ(result, 2.0);

}

/**
 * @brief Unit test to make sure Division with positive floats works
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingDivideWithPositiveAndNegativeFloatingPoints_ThenCorrectValueReturn)
{
    DivideCalculator divideCalc = DivideCalculator(-10.0, 5.0);
    float result = divideCalc.getResult();
    ASSERT_FLOAT_EQ(result, -2.0);

}

/**
 * @brief Unit test to make sure Division with positive integers works
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingDivideWithPositiveIntegers_ThenCorrectValueReturn){
    DivideCalculator divideCalc = DivideCalculator(10, 5);
    float result = divideCalc.getResult();
    ASSERT_FLOAT_EQ(result, 2);
}

/**
 * @brief Unit test to make sure Division when dividing by zero returns error
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingDivideByZeroTest_ReturnDivideByZeroError){
    DivideCalculator divideCalc = DivideCalculator(10.0, 0.0);
    float result = divideCalc.getResult();
    ASSERT_FLOAT_EQ(-1, result);
}

/**
 * @brief Unit test to make sure Division with negative floating points works
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingDividewithNegativeFloatingPoints_ThenCorrectPositiveValueReturn){
    DivideCalculator divideCalc = DivideCalculator(-10.0, -5.0);
    float result = divideCalc.getResult();
    ASSERT_FLOAT_EQ(result, 2.0);
}

/**
 * @brief Unit test to make sure Addition with positive floating points works
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingAddWithPositiveFloatingPoints_ThenCorrectPositiveValueReturn){
    AddCalculator addCalc = AddCalculator(10.0, 5.0);
    float result = addCalc.getResult();
    ASSERT_FLOAT_EQ(result, 15.0);
}

/**
 * @brief Unit test to make sure Addition with negative floating points works
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingAddWithNegativeFloatingPoints_ThenCorrectNegativeValueReturn){
    AddCalculator addCalc = AddCalculator(-10.0, -5.0);
    float result = addCalc.getResult();
    ASSERT_FLOAT_EQ(result, -15.0);
}

/**
 * @brief Unit test to make sure multiply with positive floating points works
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingMultiplyWithPositiveFloatingPoints_ThenCorrectPositiveValueReturn){
    MultiplyCalculator multiCalc = MultiplyCalculator(10.0, 5.0);
    float result = multiCalc.getResult();
    ASSERT_FLOAT_EQ(result, 50.0);
}

/**
 * @brief Unit test to make sure multiply with positive and negative floating points works
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingMultiplyWithPositiveAndNegativeFloatingPoints_ThenCorrectNegativeValueReturn){
    MultiplyCalculator multiCalc = MultiplyCalculator(10.0, -5.0);
    float result = multiCalc.getResult();
    ASSERT_FLOAT_EQ(result, -50.0);
}

/**
 * @brief Unit test to make sure multiply with negative floating points works
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingMultiplyWithNegativeFloatingPoints_ThenCorrectPositiveValueReturn){
    MultiplyCalculator multiCalc = MultiplyCalculator(-10.0, -5.0);
    float result = multiCalc.getResult();
    ASSERT_FLOAT_EQ(result, 50.0);
}

/**
 * @brief Unit test to make sure subtraction with positive floating points works
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingSubtractWithPositiveFloatingPoints_ThenCorrectPositiveValueReturn){
    SubtractCalculator subCalc = SubtractCalculator(10.0, 5.0);
    float result = subCalc.getResult();
    ASSERT_FLOAT_EQ(result, 5.0);
}

/**
 * @brief Unit test to make sure subtraction with negative floating points works
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingSubtractWithNegativeFloatingPoints_ThenCorrectPositiveValueReturn){
    SubtractCalculator subCalc = SubtractCalculator(-10.0, -5.0);
    float result = subCalc.getResult();
    ASSERT_FLOAT_EQ(result, -5.0);
}

/**
 * @brief Unit test to make sure max input is caught
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingCalculateWithMaxFloatingPoints_ThenCorrectErrorReturned){
    int result = CalculatorApplication::calculate(3.40283e+038, 3.40283e+038,'+');
    ASSERT_EQ(result, -1);
}

/**
 * @brief Unit test to make sure min input is caught
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingCalculateWithMinFloatingPoints_ThenCorrectErrorReturned){
    int result = CalculatorApplication::calculate(1.17548e-038, 1.17548e-038,'+');
    ASSERT_EQ(result, -1);
}

/**
 * @brief Unit test to make sure infinite input is caught
 * 
 */
TEST_F(whenTestingCalculator, WhenCallingCalculateWitInfiniteFloatingPoints_ThenCorrectErrorReturned){
    int result = CalculatorApplication::calculate(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(),'+');
    ASSERT_EQ(result, -1);
}