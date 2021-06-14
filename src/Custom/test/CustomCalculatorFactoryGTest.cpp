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

class CustomCalculatorFactoryTests: public ::testing::Test
{
    protected:
        std::string fourFormat = "{}{}{}{}";
        CustomCalculatorFactory<int> calculatorFactory{[](const std::vector<int>& terms){ return 0; }, fourFormat};
};

/**
 * @brief positive case to make sure a calculator is constructed if terms match
 */
TEST_F(CustomCalculatorFactoryTests, WhenCreateCalculatorIsCalledWithCorrectTermCount_ThenCustomCalculatorObjectIsReturned)
{
    auto calc = calculatorFactory.createCalculator("1 2 3 4");
    ASSERT_NE(nullptr, calc);
}

/**
 * @brief negative case if term count and expression format do not match
 */
TEST_F(CustomCalculatorFactoryTests, WhenCreateCalculatorIsCalledWithIncorrectTermCount_ThenNullptrIsReturned)
{
    auto calc1 = calculatorFactory.createCalculator("1 2");
    ASSERT_EQ(nullptr, calc1);
    auto calc2 = calculatorFactory.createCalculator("1 2 3 4 5 6");
    ASSERT_EQ(nullptr, calc2);
}