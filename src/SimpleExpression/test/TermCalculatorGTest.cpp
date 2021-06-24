////////////////////////////////////////////////////////////////////////////
/**
 *  @file   TermCalculatorGTest.cpp
 *  @date   Tue, June 15 2021
 *  @brief  Tests for TermCalculator
 */
////////////////////////////////////////////////////////////////////////////


#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "TermCalculator.h"

using namespace testing;

namespace calculator
{
/**
 * @brief test for term calculator getResult should return term
 */
    TEST(termCalculatorTests, WhenGetResultIsCalledWithTermCalculator_ThenTermReturnedAsInt)
    {
        TermCalculator termCalculator{0};
        ASSERT_EQ(0, termCalculator.getResult());
    }

/**
 * @brief test for term calculator for toString, should return the term as a string
 */
    TEST(termCalculatorTests, WhenToStringIsCalledWithTermCalculator_ThenTermReturnedAsString)
    {
        TermCalculator termCalculator{0};
        ASSERT_EQ("0", termCalculator.toString());
    }

/**
 * @brief test for term calculator for getResult, should return the term as a string
 */
    TEST(termCalculatorTests, WhenGetExpressionIsCalledWithTermCalculator_ThenTermReturnedAsString)
    {
        TermCalculator termCalculator{0};
        ASSERT_EQ("0", termCalculator.getExpression());
    }
}