////////////////////////////////////////////////////////////////////////////////
/**
 * @file SymbolExpressionGtest.cpp
 * @date Mon February 28 2022
 * @brief test suites which test SymbolExpression objects and their various 
 * template specializations
 */
////////////////////////////////////////////////////////////////////////////////

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../inc/SymbolExpression.h"

/**
 * @brief a collection of constants used by the SymbolExpression test suites
 */
class SymbolExpressionTestConstants
{
public:
    static constexpr char   GLYPH_X = 'x';
    static constexpr char   GLYPH_Y = 'y';
    static constexpr int    INT_VALUE_TO_BIND = 42;
    static constexpr double DOUBLE_VALUE_TO_BIND = 42.42;
};
constexpr char   SymbolExpressionTestConstants::GLYPH_X;
constexpr char   SymbolExpressionTestConstants::GLYPH_Y;
constexpr int    SymbolExpressionTestConstants::INT_VALUE_TO_BIND;
constexpr double SymbolExpressionTestConstants::DOUBLE_VALUE_TO_BIND;

/**
 * @brief tests the construction of a SymbolExpression<int> with a known glyph
 */
TEST(SymbolExpressionIntTestSuite, WhenConstructorIsCalled_ThenNoExceptionsAreThrown)
{
    EXPECT_NO_THROW(calculator::expression::SymbolExpression<int> result{
            SymbolExpressionTestConstants::GLYPH_X});
}

/**
 * @brief tests the evaluation of a SymbolExpression<int>, which should not 
 * yield a value, as it has not had a value bound to it
 */
TEST(SymbolExpressionIntTestSuite, WhenCalculateExpressionIsCalled_ThenNoneIsReturned)
{
    calculator::expression::SymbolExpression<int> objectToTest{
            SymbolExpressionTestConstants::GLYPH_X};
    auto result = objectToTest.calculateExpression();
    ASSERT_EQ(result, boost::none);
}

/**
 * @brief tests binding a value to a symbol that matches the symbol of a
 * SymbolExpression<int>, which should return a new IExpression<int>
 * with the correct bound value
 */
TEST(SymbolExpressionIntTestSuite, WhenBindValueToSymbolIsCalled_ThenAnExpressionIsReturnedThatYieldsTheCorrectValue)
{
    calculator::expression::SymbolExpression<int> objectToTest{
            SymbolExpressionTestConstants::GLYPH_X};
    auto result = objectToTest.bindValueToSymbol(
            SymbolExpressionTestConstants::GLYPH_X,
            SymbolExpressionTestConstants::INT_VALUE_TO_BIND);
    ASSERT_NE(result, nullptr);
    auto value = result->calculateExpression();
    ASSERT_NE(value, boost::none);
    ASSERT_EQ(*value, SymbolExpressionTestConstants::INT_VALUE_TO_BIND);
}

/**
 * @brief tests binding a value to a symbol that does not match the symbol of a
 * SymbolExpression<int>, which should return a nullptr, indicating that
 * there were no changes to this expression
 */
TEST(SymbolExpressionIntTestSuite, WhenBindValueToSymbolIsCalledWithoutTheMatchingGlyph_ThenNullptrIsReturned)
{
    calculator::expression::SymbolExpression<int> objectToTest{
            SymbolExpressionTestConstants::GLYPH_X};
    auto result = objectToTest.bindValueToSymbol(
            SymbolExpressionTestConstants::GLYPH_Y,
            SymbolExpressionTestConstants::INT_VALUE_TO_BIND);
    ASSERT_EQ(result, nullptr);
}

/**
 * @brief tests converting a SymbolExpression<int> to a string, which should 
 * yield the glyph used to construct it
 */
TEST(SymbolExpressionIntTestSuite, WhenToStringIsCalled_ThenCorrectStringRepresentationIsReturned)
{
    calculator::expression::SymbolExpression<int> objectToTest{
            SymbolExpressionTestConstants::GLYPH_X};
    auto result = objectToTest.toString();
    ASSERT_EQ(result, std::string(1, SymbolExpressionTestConstants::GLYPH_X));
}

/**
 * @brief tests the construction of a SymbolExpression<double> with a known
 * glyph
 */
TEST(SymbolExpressionDoubleTestSuite, WhenConstructorIsCalled_ThenNoExceptionsAreThrown)
{
    EXPECT_NO_THROW(calculator::expression::SymbolExpression<double> result{
            SymbolExpressionTestConstants::GLYPH_X});
}

/**
 * @brief tests the evaluation of a SymbolExpression<double>, which should not 
 * yield a value, as it has not had a value bound to it
 */
TEST(SymbolExpressionDoubleTestSuite, WhenCalculateExpressionIsCalled_ThenNoneIsReturned)
{
    calculator::expression::SymbolExpression<double> objectToTest{
            SymbolExpressionTestConstants::GLYPH_X};
    auto result = objectToTest.calculateExpression();
    ASSERT_EQ(result, boost::none);
}

/**
 * @brief tests binding a value to a symbol that matches the symbol of a
 * SymbolExpression<double>, which should return a new 
 * IExpression<double> with the correct bound value 
 */
TEST(SymbolExpressionDoubleTestSuite, WhenBindValueToSymbolIsCalledWithTheMatchingGlyph_ThenAnExpressionIsReturnedThatYieldsTheCorrectValue)
{
    calculator::expression::SymbolExpression<double> objectToTest{
            SymbolExpressionTestConstants::GLYPH_X};
    auto result = objectToTest.bindValueToSymbol(
            SymbolExpressionTestConstants::GLYPH_X,
            SymbolExpressionTestConstants::DOUBLE_VALUE_TO_BIND);
    ASSERT_NE(result, nullptr);
    auto value = result->calculateExpression();
    ASSERT_NE(value, boost::none);
    ASSERT_EQ(*value, SymbolExpressionTestConstants::DOUBLE_VALUE_TO_BIND);
}

/**
 * @brief tests binding a value to a symbol that does not match the symbol of a
 * SymbolExpression<double>, which should return a nullptr, indicating that
 * there were no changes to this expression
 */
TEST(SymbolExpressionDoubleTestSuite, WhenBindValueToSymbolIsCalledWithoutTheMatchingGlyph_ThenNullptrIsReturned)
{
    calculator::expression::SymbolExpression<double> objectToTest{
            SymbolExpressionTestConstants::GLYPH_X};
    auto result = objectToTest.bindValueToSymbol(
            SymbolExpressionTestConstants::GLYPH_Y,
            SymbolExpressionTestConstants::DOUBLE_VALUE_TO_BIND);
    ASSERT_EQ(result, nullptr);
}

/**
 * @brief tests converting a SymbolExpression<double> to a string, which should 
 * yield the glyph used to construct it
 */
TEST(SymbolExpressionDoubleTestSuite, WhenToStringIsCalled_ThenCorrectStringRepresentationIsReturned)
{
    calculator::expression::SymbolExpression<double> objectToTest{
            SymbolExpressionTestConstants::GLYPH_X};
    auto result = objectToTest.toString();
    ASSERT_EQ(result, std::string(1, SymbolExpressionTestConstants::GLYPH_X));
}
