#include "../inc/Calculator.h"
#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace calculator;
using namespace testing;


class whenTestingCalculator:public ::testing::Test{};
TEST_F(whenTestingCalculator, divideTest){
    Calculator calculator;
    ASSERT_FLOAT_EQ(calculator.divide(10.0f, 5.0f, '/'), 2.0f);
}

TEST_F(whenTestingCalculator, divideByZeroTest){
    Calculator calculator;
    ASSERT_EQ(0.0, calculator.divide(10.0f, 0.0f, '/'));
    ASSERT_EXIT(calculator.divide(10.0f, 0.0f, '/'), testing::ExitedWithCode(-1), "Error, Can't divide by zero");
}

TEST_F(whenTestingCalculator, addTest){
    Calculator calculator;
    ASSERT_FLOAT_EQ(calculator.add(10.0f, 5.0f, '+'), 15.0f);
}

TEST_F(whenTestingCalculator, multiplyTest){
    Calculator calculator;
    ASSERT_FLOAT_EQ(calculator.multiply(10.0f, 5.0f, '*'), 50.0f);
}

TEST_F(whenTestingCalculator, subtractTest){
    Calculator calculator;
    ASSERT_FLOAT_EQ(calculator.subtract(10.0f, 5.0f, '-'), 5.0f);
}

TEST_F(whenTestingCalculator, modulusTest){
    Calculator calculator;
    ASSERT_FLOAT_EQ(calculator.modulus(10.0f, 5.0f, '/'), 0.0f);
}

