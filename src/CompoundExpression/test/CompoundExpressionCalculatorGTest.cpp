////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CompoundExpressionCalculatorGTest.h
 *  @date   Tue, June 15 2021
 *  @brief  Tests for CompoundExpressionCalculator
 */
////////////////////////////////////////////////////////////////////////////


#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "CompoundExpressionCalculator.h"

using namespace testing;
using namespace calculator;

/**
 * @brief Fixture of Compound Expression Calculator. Contains calculators that are used in tests
 */
class CompoundExpressionCalculatorTests : public ::testing::Test
{
    protected:
        typedef std::pair<char, int> varPair;
        std::unordered_map<char, int> map {
            varPair('a',-1),
            varPair('b',2),
            varPair('c',3),
            varPair('d',-3),
            varPair('e',-5)
        };

        std::string testExpression = "-1 + 2 * -3 / 3 - -5"; // = 2
        std::string testVarExpression = "a + b * d / c - e";

        CompoundExpressionCalculator calculatorExpression{testExpression};
        CompoundExpressionCalculator calculatorVariable{map, testVarExpression};
        CompoundExpressionCalculator calculatorExpressionEmpty {""};
        CompoundExpressionCalculator calculatorVariableEmpty {std::unordered_map<char, int>(), ""};

};

/**
 * @brief Happy test for static toVariableMap, takes expression and converts to unordered map
 */
TEST_F(CompoundExpressionCalculatorTests, WhenToVariableMapIsCalledWithValidString_ThenFilledMapReturned)
{
    auto result = CompoundExpressionCalculator::toVariableMap("a = 10, b = 100");

    ASSERT_TRUE(result['a'] == 10);
    ASSERT_TRUE(result['b'] == 100);
}

/**
 * @brief Negative test for static toVariableMap if can't read then an empty map is passed
 */
TEST_F(CompoundExpressionCalculatorTests, WhenToVariableMapIsCalledWithInvalidString_ThenEmptyMapReturned)
{
    auto result = CompoundExpressionCalculator::toVariableMap("a 234, 823 457b 00");

    ASSERT_TRUE(result.empty());
}

/**
 * @brief Happy test for getResult on a compound calculator
 */
TEST_F(CompoundExpressionCalculatorTests, WhenGetResultIsCalledWithCompoundCalculator_ThenAnswerReturned)
{
    ASSERT_EQ(2, calculatorExpression.getResult());
    ASSERT_EQ(2, calculatorVariable.getResult());
}

/**
 * @brief Happy test for getExpression on a compound calculator
 */
TEST_F(CompoundExpressionCalculatorTests, WhenGetExpressionIsCalledWithCompoundCalculator_ThenFormattedExpressionReturned)
{
    ASSERT_EQ("-1 + 2 * -3 / 3 - -5", calculatorExpression.getExpression());
    ASSERT_EQ("-1 + 2 * -3 / 3 - -5", calculatorVariable.getExpression());
}

/**
 * @brief Happy test for toString on a compound calculator
 */
TEST_F(CompoundExpressionCalculatorTests, WhenToStringIsCalledWithCompoundCalculator_ThenFullEquationReturned)
{
    ASSERT_EQ("-1 + 2 * -3 / 3 - -5 = 2", calculatorExpression.toString());
    ASSERT_EQ("-1 + 2 * -3 / 3 - -5 = 2", calculatorVariable.toString());
}

/**
 * @brief Negative test for getResult on a empty compound calculator, result should be 0
 */
TEST_F(CompoundExpressionCalculatorTests, WhenGetResultIsCalledWithEmptyCompoundCalculator_ThenZeroReturned)
{
    ASSERT_EQ(0, calculatorExpressionEmpty.getResult());
    ASSERT_EQ(0, calculatorVariableEmpty.getResult());
}

/**
 * @brief Negative test for getExpression on a empty compound calculator, should be ""
 */
TEST_F(CompoundExpressionCalculatorTests, WhenGetExpressionIsCalledWithEmptyCompoundCalculator_ThenEmptyStringReturned)
{
    ASSERT_EQ("", calculatorExpressionEmpty.getExpression());
    ASSERT_EQ("", calculatorVariableEmpty.getExpression());
}

/**
 * @brief Negative test for toString on a empty compound calculator, should be " = 0"
 *        Since it should be taking the empty expression and concatenating " = " and the result, "0"
 */
TEST_F(CompoundExpressionCalculatorTests, WhenToStringIsCalledWithEmptyCompoundCalculator_ThenEqualZeroReturned)
{
    ASSERT_EQ(" = 0", calculatorExpressionEmpty.toString());
    ASSERT_EQ(" = 0", calculatorVariableEmpty.toString());
}