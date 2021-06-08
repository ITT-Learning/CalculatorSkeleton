////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CustomCalculatorFactoryGTest.cpp
 *  @date   Fri, June 11 2021
 *  @brief  Tests for Custom Calculator Factory
 */
////////////////////////////////////////////////////////////////////////////


#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "CustomCalculator.h"
#include "CustomCalculatorFactory.h"

using namespace testing;
using namespace calculator;

/**
 * @brief positive case to make sure a calculator is constructed if terms match
 */
TEST(CustomCalculatorFactoryTests, WhenCreateCalculatorIsCalledWithCorrectTermCount_ThenCustomCalculatorObjectIsReturned)
{
    CustomCalculatorFactory<int> calculatorFactory {[](auto f) { return 0; }, "{}{}{}{}"};
    auto calc = calculatorFactory.createCalculator("1 2 3 4");
    ASSERT_NE(nullptr, calc);
}

/**
 * @brief negative case if term count and expression format do not match
 */
TEST(CustomCalculatorFactoryTests, WhenCreateCalculatorIsCalledWithIncorrectTermCount_ThenNullptrIsReturned)
{
    CustomCalculatorFactory<int> calculatorFactory {[](auto f) { return 0; }, "{}{}{}{}"};

    auto calc1 = calculatorFactory.createCalculator("1 2");
    ASSERT_EQ(nullptr, calc1);
    auto calc2 = calculatorFactory.createCalculator("1 2 3 4 5 6");
    ASSERT_EQ(nullptr, calc2);
}