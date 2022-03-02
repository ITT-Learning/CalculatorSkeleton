////////////////////////////////////////////////////////////////////////////////
/**
 * @file ValueExpressionGtest.cpp
 * @date Mon February 28 2022
 * @brief test suites which test ValueExpression objects and their various 
 * template specializations
 */
////////////////////////////////////////////////////////////////////////////////

#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../inc/ValueExpression.h"

/**
 * @brief a collection of constants used by the ValueExpression test suites
 */
class ValueExpressionTestConstants
{
public:
    static constexpr int    INT_VALUE = 12;
    static constexpr double DOUBLE_VALUE = 12.12;

    static constexpr char   GLYPH_TO_BIND = 'x';
    static constexpr int    INT_VALUE_TO_BIND = 42;
    static constexpr double DOUBLE_VALUE_TO_BIND = 42.42;
};
constexpr int    ValueExpressionTestConstants::INT_VALUE;
constexpr double ValueExpressionTestConstants::DOUBLE_VALUE;
constexpr char   ValueExpressionTestConstants::GLYPH_TO_BIND;
constexpr int    ValueExpressionTestConstants::INT_VALUE_TO_BIND;
constexpr double ValueExpressionTestConstants::DOUBLE_VALUE_TO_BIND;

/**
 * @brief tests the construction of a ValueExpression<int> with a known value
 */
TEST(ValueExpressionIntTestSuite, WhenConstructorIsCalled_ThenNoExceptionsAreThrown)
{
    EXPECT_NO_THROW(calculator::expression::ValueExpression<int> result{
                ValueExpressionTestConstants::INT_VALUE});
    
}

/**
 * @brief tests the evaluation of a ValueExpression<int>, ensuring that its
 * output value equals its value given at construction
 */
TEST(ValueExpressionIntTestSuite, WhenCalculateExpressionIsCalled_ThenAValueIsReturnedAndItIsCorrect)
{
    calculator::expression::ValueExpression<int> objectToTest{
            ValueExpressionTestConstants::INT_VALUE};
    auto result = objectToTest.calculateExpression();
    ASSERT_NE(result, boost::none);
    ASSERT_EQ(*result, ValueExpressionTestConstants::INT_VALUE);
}

/**
 * @brief tests binding a value to a symbol of a ValueExpression<int>, which
 * should not do anything, as a literal value will not have any unbound symbols
 */
TEST(ValueExpressionIntTestSuite, WhenBindValueToSymbolIsCalled_ThenNullptrIsReturned)
{
    calculator::expression::ValueExpression<int> objectToTest{
            ValueExpressionTestConstants::INT_VALUE};
    auto result = objectToTest.bindValueToSymbol(
            ValueExpressionTestConstants::GLYPH_TO_BIND,
            ValueExpressionTestConstants::INT_VALUE_TO_BIND);
    ASSERT_EQ(result, nullptr);
}

/**
 * @brief tests converting a ValueExpression<int> to a string, which should 
 * yield the original number
 */
TEST(ValueExpressionIntTestSuite, WhenToStringIsCalled_ThenCorrectStringRepresentationIsReturned)
{
    calculator::expression::ValueExpression<int> objectToTest{
            ValueExpressionTestConstants::INT_VALUE};
    auto result = objectToTest.toString();
    ASSERT_EQ(result, std::to_string(ValueExpressionTestConstants::INT_VALUE));
}

/**
 * @brief tests the construction of a ValueExpression<double> with a known value
 */
TEST(ValueExpressionDoubleTestSuite, WhenConstructorIsCalled_ThenNoExceptionsAreThrown)
{
    EXPECT_NO_THROW(calculator::expression::ValueExpression<double> result{
            ValueExpressionTestConstants::DOUBLE_VALUE});
}

/**
 * @brief tests the evaluation of a ValueExpression<double>, ensuring that its
 * output value equals its value given at construction
 */
TEST(ValueExpressionDoubleTestSuite, WhenCalculateExpressionIsCalled_ThenAValueIsReturnedAndItIsCorrect)
{
    calculator::expression::ValueExpression<double> objectToTest{
            ValueExpressionTestConstants::DOUBLE_VALUE};
    auto result = objectToTest.calculateExpression();
    ASSERT_NE(result, boost::none);
    ASSERT_EQ(*result, ValueExpressionTestConstants::DOUBLE_VALUE);
}

/**
 * @brief tests binding a value to a symbol of a ValueExpression<double>, which
 * should not do anything, as a literal value will not have any unbound symbols
 */
TEST(ValueExpressionDoubleTestSuite, WhenBindValueToSymbolIsCalled_ThenNullptrIsReturned)
{
    calculator::expression::ValueExpression<double> objectToTest{
            ValueExpressionTestConstants::DOUBLE_VALUE};
    auto result = objectToTest.bindValueToSymbol(
            ValueExpressionTestConstants::GLYPH_TO_BIND,
            ValueExpressionTestConstants::DOUBLE_VALUE_TO_BIND);
    ASSERT_EQ(result, nullptr);
}

/**
 * @brief tests converting a ValueExpression<double> to a string, which should 
 * yield the original number
 */
TEST(ValueExpressionDoubleTestSuite, WhenToStringIsCalled_ThenCorrectStringRepresentationIsReturned)
{
    calculator::expression::ValueExpression<double> objectToTest{
            ValueExpressionTestConstants::DOUBLE_VALUE};
    auto result = objectToTest.toString();
    ASSERT_EQ(result, std::to_string(ValueExpressionTestConstants::DOUBLE_VALUE));
}
