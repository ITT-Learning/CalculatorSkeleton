////////////////////////////////////////////////////////////////////////////////
/**
 * @file OperatorExpressionGtest.cpp
 * @date Tues March 1 2022
 * @brief test suites which test OperatorExpression objects and their various
 * template specializations
 */
////////////////////////////////////////////////////////////////////////////////

#include <memory>

#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "OperatorExpression.h"
#include "ValueExpression.h"
#include "SymbolExpression.h"

/**
 * @brief a collection of constants used by the OperatorExpression test suites
 */
class OperatorExpressionTestConstants
{
public:
    static constexpr char   GLYPH_X = 'x';
    static constexpr int    X_INT_VALUE = 42;
    static constexpr double X_DOUBLE_VALUE = 42.42;

    static constexpr char   GLYPH_Y = 'y';
    static constexpr int    Y_INT_VALUE = 0;
    static constexpr double Y_DOUBLE_VALUE = 0.0;

    static constexpr char   GLYPH_Z = 'z';
    static constexpr int    Z_INT_VALUE = 1;
    static constexpr double Z_DOUBLE_VALUE = 1.0;

    static constexpr char   GLYPH_U = 'u';
    static constexpr int    U_INT_VALUE = 9;
    static constexpr double U_DOUBLE_VALUE = 8.9991;

    static constexpr int    ADDITION_INT_RESULT = X_INT_VALUE + Z_INT_VALUE;
    static constexpr double ADDITION_DOUBLE_RESULT = X_DOUBLE_VALUE + Z_DOUBLE_VALUE;

    static constexpr int    SUBTRACTION_INT_RESULT = X_INT_VALUE - Z_INT_VALUE;
    static constexpr double SUBTRACTION_DOUBLE_RESULT = X_DOUBLE_VALUE - Z_DOUBLE_VALUE;

    static constexpr int    MULTIPLICATION_INT_RESULT = X_INT_VALUE * U_INT_VALUE;
    static constexpr double MULTIPLICATION_DOUBLE_RESULT = X_DOUBLE_VALUE * U_DOUBLE_VALUE;

    static constexpr int    DIVISION_INT_RESULT = X_INT_VALUE / U_INT_VALUE;
    static constexpr double DIVISION_DOUBLE_RESULT = X_DOUBLE_VALUE / U_DOUBLE_VALUE;

    static constexpr int    MODULO_INT_RESULT = X_INT_VALUE % U_INT_VALUE;
    static constexpr double MODULO_DOUBLE_RESULT = 6.4236;

    static constexpr int    COMPOUND_INT_RESULT = (X_INT_VALUE + Z_INT_VALUE) / (X_INT_VALUE % U_INT_VALUE);
    static constexpr double COMPOUND_DOUBLE_RESULT = 6.759449529858646;

    static constexpr const char *INT_STRING_TEST_EXPRESSION = "(42 + z)";
    static constexpr const char *DOUBLE_STRING_TEST_EXPRESSION = "(42.420000 + z)";
};
constexpr char   OperatorExpressionTestConstants::GLYPH_X;
constexpr int    OperatorExpressionTestConstants::X_INT_VALUE;
constexpr double OperatorExpressionTestConstants::X_DOUBLE_VALUE;
constexpr char   OperatorExpressionTestConstants::GLYPH_Y;
constexpr int    OperatorExpressionTestConstants::Y_INT_VALUE;
constexpr double OperatorExpressionTestConstants::Y_DOUBLE_VALUE;
constexpr char   OperatorExpressionTestConstants::GLYPH_Z;
constexpr int    OperatorExpressionTestConstants::Z_INT_VALUE;
constexpr double OperatorExpressionTestConstants::Z_DOUBLE_VALUE;
constexpr char   OperatorExpressionTestConstants::GLYPH_U;
constexpr int    OperatorExpressionTestConstants::U_INT_VALUE;
constexpr double OperatorExpressionTestConstants::U_DOUBLE_VALUE;
constexpr int    OperatorExpressionTestConstants::ADDITION_INT_RESULT;
constexpr double OperatorExpressionTestConstants::ADDITION_DOUBLE_RESULT;
constexpr int    OperatorExpressionTestConstants::SUBTRACTION_INT_RESULT;
constexpr double OperatorExpressionTestConstants::SUBTRACTION_DOUBLE_RESULT;
constexpr int    OperatorExpressionTestConstants::MULTIPLICATION_INT_RESULT;
constexpr double OperatorExpressionTestConstants::MULTIPLICATION_DOUBLE_RESULT;
constexpr int    OperatorExpressionTestConstants::DIVISION_INT_RESULT;
constexpr double OperatorExpressionTestConstants::DIVISION_DOUBLE_RESULT;
constexpr int    OperatorExpressionTestConstants::MODULO_INT_RESULT;
constexpr double OperatorExpressionTestConstants::MODULO_DOUBLE_RESULT;
constexpr int    OperatorExpressionTestConstants::COMPOUND_INT_RESULT;
constexpr double OperatorExpressionTestConstants::COMPOUND_DOUBLE_RESULT;
constexpr const char *OperatorExpressionTestConstants::INT_STRING_TEST_EXPRESSION;
constexpr const char *OperatorExpressionTestConstants::DOUBLE_STRING_TEST_EXPRESSION;

/**
 * @brief tests that an OperatorExpression throws an exception during
 * construction if its given left sub-expression is nullptr
 */
TEST(OperatorExpressionIntTestSuite, WhenConstructorIsCalledWithNullptrLeftSubExpression_ThenAnExceptionIsThrown)
{
    std::unique_ptr<calculator::expression::IExpression<int>>
            leftNullptr{nullptr};
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::Y_INT_VALUE);
    EXPECT_THROW(
            calculator::expression::OperatorExpression<int> expression(
                    std::move(leftNullptr),
                    std::move(rightSubExpression),
                    calculator::expression::OperatorType::ADDITION),
            std::domain_error);
}

/**
 * @brief tests that an OperatorExpression throws an exception during
 * construction if its given right sub-expression is nullptr
 */
TEST(OperatorExpressionIntTestSuite, WhenConstructorIsCalledWithNullptrRightSubExpression_ThenAnExceptionIsThrown)
{
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::X_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightNullptr{nullptr};
    EXPECT_THROW(
            calculator::expression::OperatorExpression<int> expression(
                    std::move(leftSubExpression),
                    std::move(rightNullptr),
                    calculator::expression::OperatorType::ADDITION),
            std::domain_error);
}

/**
 * @brief tests that an OperatorExpression can be constructed successfully if 
 * its given sub-expressions are not nullptr
 */
TEST(OperatorExpressionIntTestSuite, WhenConstructorIsCalledWithInitializedSubExpressions_ThenTheObjectIsConstructed)
{
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::X_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::Y_INT_VALUE);
    EXPECT_NO_THROW(calculator::expression::OperatorExpression<int> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::ADDITION));
}

/**
 * @brief tests that an OperatorExpression returns nothing when attempting to
 * calculate an expression that would divide by zero
 */
TEST(OperatorExpressionIntTestSuite, WhenCalculateExpressionIsCalledWithDivisionByZero_ThenNoneIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::X_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::Y_INT_VALUE);
    calculator::expression::OperatorExpression<int> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::DIVISION);
    auto value = expression.calculateExpression();
    EXPECT_EQ(value, boost::none);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with a single addition operation and tests
 * whether the caching feature works correctly by calculating the expression
 * twice
 */
TEST(OperatorExpressionIntTestSuite, WhenCalculateExpressionIsCalledWithAdditionTwice_ThenTheCorrectValueIsReturnedTwice)
{
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::X_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::Z_INT_VALUE);
    calculator::expression::OperatorExpression<int> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::ADDITION);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::ADDITION_INT_RESULT);
    value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::ADDITION_INT_RESULT);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with a single subtraction operation
 */
TEST(OperatorExpressionIntTestSuite, WhenCalculateExpressionIsCalledWithSubtraction_ThenTheCorrectValueIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::X_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::Z_INT_VALUE);
    calculator::expression::OperatorExpression<int> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::SUBTRACTION);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::SUBTRACTION_INT_RESULT);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with a single multiplication operation
 */
TEST(OperatorExpressionIntTestSuite, WhenCalculateExpressionIsCalledWithMultiplication_ThenTheCorrectValueIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::X_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::U_INT_VALUE);
    calculator::expression::OperatorExpression<int> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::MULTIPLICATION);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::MULTIPLICATION_INT_RESULT);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with a single division operation
 */
TEST(OperatorExpressionIntTestSuite, WhenCalculateExpressionIsCalledWithDivision_ThenCorrectValueIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::X_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::U_INT_VALUE);
    calculator::expression::OperatorExpression<int> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::DIVISION);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::DIVISION_INT_RESULT);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with a single modulo operation
 */
TEST(OperatorExpressionIntTestSuite, WhenCalculateExpressionIsCalledWithModulo_ThenCorrectValueIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::X_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::U_INT_VALUE);
    calculator::expression::OperatorExpression<int> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::MODULO);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::MODULO_INT_RESULT);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with multiple operations
 */
TEST(OperatorExpressionIntTestSuite, WhenCalculateExpressionIsCalledWithCompoundExpression_ThenCorrectValueIsReturned)
{
    // nodes at depth = 2
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftLeftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::X_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>>
            leftRightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::Z_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>> 
            rightLeftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::X_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightRightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::U_INT_VALUE);
    // nodes at depth = 1
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftSubExpression = std::make_unique<
            calculator::expression::OperatorExpression<int>>(
            std::move(leftLeftSubExpression),
            std::move(leftRightSubExpression),
            calculator::expression::OperatorType::ADDITION);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightSubExpression = std::make_unique<
            calculator::expression::OperatorExpression<int>>(
            std::move(rightLeftSubExpression),
            std::move(rightRightSubExpression),
            calculator::expression::OperatorType::MODULO);
    // nodes at depth = 0
    calculator::expression::OperatorExpression<int> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::DIVISION);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::COMPOUND_INT_RESULT);
}

/**
 * @brief tests that an OperatorExpression will replace symbols as the caller
 * binds values to those symbols and that, only after binding all symbols in the
 * expression, the expression yields a value
 */
TEST(OperatorExpressionIntTestSuite, WhenBindValueToSymbolIsCalledWithCompoundExpression_ThenThatSymbolIsReplacedByThatValueInAllSubExpressionsAndTheEntireExpressionWillOnlyHaveAValueWhenAllSymbolsAreBound)
{
    // TODO this test might be too long and complicated. How can we check that 
    // an expression will ONLY yield the correct result after all symbols are
    // bound in a way that also binds multiple symbols?
    // nodes at depth = 2
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftLeftSubExpression = std::make_unique<
            calculator::expression::SymbolExpression<int>>(
            OperatorExpressionTestConstants::GLYPH_X, true);
    std::unique_ptr<calculator::expression::IExpression<int>>
            leftRightSubExpression = std::make_unique<
            calculator::expression::SymbolExpression<int>>(
            OperatorExpressionTestConstants::GLYPH_Z, true);
    std::unique_ptr<calculator::expression::IExpression<int>> 
            rightLeftSubExpression = std::make_unique<
            calculator::expression::SymbolExpression<int>>(
            OperatorExpressionTestConstants::GLYPH_X, true);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightRightSubExpression = std::make_unique<
            calculator::expression::SymbolExpression<int>>(
            OperatorExpressionTestConstants::GLYPH_U, true);
    // nodes at depth = 1
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftSubExpression = std::make_unique<
            calculator::expression::OperatorExpression<int>>(
            std::move(leftLeftSubExpression),
            std::move(leftRightSubExpression),
            calculator::expression::OperatorType::ADDITION);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightSubExpression = std::make_unique<
            calculator::expression::OperatorExpression<int>>(
            std::move(rightLeftSubExpression),
            std::move(rightRightSubExpression),
            calculator::expression::OperatorType::MODULO);
    // nodes at depth = 0
    calculator::expression::OperatorExpression<int> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::DIVISION);

    // start binding variables
    auto value = expression.calculateExpression();
    EXPECT_EQ(value, boost::none);
    auto newExpression = expression.bindValueToSymbol(
            OperatorExpressionTestConstants::GLYPH_X,
            OperatorExpressionTestConstants::X_INT_VALUE);
    EXPECT_EQ(newExpression, nullptr);
    value = expression.calculateExpression();
    EXPECT_EQ(value, boost::none);
    newExpression = expression.bindValueToSymbol(
            OperatorExpressionTestConstants::GLYPH_Z,
            OperatorExpressionTestConstants::Z_INT_VALUE);
    EXPECT_EQ(newExpression, nullptr);
    value = expression.calculateExpression();
    EXPECT_EQ(value, boost::none);
    newExpression = expression.bindValueToSymbol(
            OperatorExpressionTestConstants::GLYPH_U,
            OperatorExpressionTestConstants::U_INT_VALUE);
    EXPECT_EQ(newExpression, nullptr);
    value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::COMPOUND_INT_RESULT);
}

/**
 * @brief tests that an OperatorExpression builds the correct string
 * representation
 */
TEST(OperatorExpressionIntTestSuite, WhenToStringIsCalled_ThenTheCorrectStringValueIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<int>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<int>>(
            OperatorExpressionTestConstants::X_INT_VALUE);
    std::unique_ptr<calculator::expression::IExpression<int>>
            rightSubExpression = std::make_unique<
            calculator::expression::SymbolExpression<int>>(
            OperatorExpressionTestConstants::GLYPH_Z, true);
    calculator::expression::OperatorExpression<int> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::ADDITION);
    auto stringRepresentation = expression.toString();
    EXPECT_EQ(stringRepresentation, OperatorExpressionTestConstants::INT_STRING_TEST_EXPRESSION);
}

/**
 * @brief tests that an OperatorExpression throws an exception during
 * construction if its given left sub-expression is nullptr
 */
TEST(OperatorExpressionDoubleTestSuite, WhenConstructorIsCalledWithNullptrLeftSubExpression_ThenAnExceptionIsThrown)
{
    std::unique_ptr<calculator::expression::IExpression<double>>
            leftNullptr{nullptr};
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::Y_DOUBLE_VALUE);
    EXPECT_THROW(
            calculator::expression::OperatorExpression<double> expression(
                    std::move(leftNullptr),
                    std::move(rightSubExpression),
                    calculator::expression::OperatorType::ADDITION),
            std::domain_error);
}

/**
 * @brief tests that an OperatorExpression throws an exception during
 * construction if its given right sub-expression is nullptr
 */
TEST(OperatorExpressionDoubleTestSuite, WhenConstructorIsCalledWithNullptrRightSubExpression_ThenAnExceptionIsThrown)
{
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightNullptr{nullptr};
    EXPECT_THROW(
            calculator::expression::OperatorExpression<double> expression(
                    std::move(leftSubExpression),
                    std::move(rightNullptr),
                    calculator::expression::OperatorType::ADDITION),
            std::domain_error);
}

/**
 * @brief tests that an OperatorExpression can be constructed successfully if 
 * its given sub-expressions are not nullptr
 */
TEST(OperatorExpressionDoubleTestSuite, WhenConstructorIsCalledWithInitializedSubExpressions_ThenTheObjectIsConstructed)
{
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::Y_DOUBLE_VALUE);
    EXPECT_NO_THROW(
            calculator::expression::OperatorExpression<double> expression(
                    std::move(leftSubExpression),
                    std::move(rightSubExpression),
                    calculator::expression::OperatorType::ADDITION));
}

/**
 * @brief tests that an OperatorExpression returns nothing when attempting to
 * calculate an expression that would divide by zero
 */
TEST(OperatorExpressionDoubleTestSuite, WhenCalculateExpressionIsCalledWithDivisionByZero_ThenNoneIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::Y_DOUBLE_VALUE);
    calculator::expression::OperatorExpression<double> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::DIVISION);
    auto value = expression.calculateExpression();
    EXPECT_EQ(value, boost::none);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with a single addition operation and tests
 * whether the caching feature works correctly by calculating the expression
 * twice
 */
TEST(OperatorExpressionDoubleTestSuite, WhenCalculateExpressionIsCalledWithAdditionTwice_ThenTheCorrectValueIsReturnedTwice)
{
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::Z_DOUBLE_VALUE);
    calculator::expression::OperatorExpression<double> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::ADDITION);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::ADDITION_DOUBLE_RESULT);
    value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::ADDITION_DOUBLE_RESULT);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with a single subtraction operation
 */
TEST(OperatorExpressionDoubleTestSuite, WhenCalculateExpressionIsCalledWithSubtraction_ThenTheCorrectValueIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::Z_DOUBLE_VALUE);
    calculator::expression::OperatorExpression<double> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::SUBTRACTION);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::SUBTRACTION_DOUBLE_RESULT);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with a single multiplication operation
 */
TEST(OperatorExpressionDoubleTestSuite, WhenCalculateExpressionIsCalledWithMultiplication_ThenTheCorrectValueIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::U_DOUBLE_VALUE);
    calculator::expression::OperatorExpression<double> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::MULTIPLICATION);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::MULTIPLICATION_DOUBLE_RESULT);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with a single division operation
 */
TEST(OperatorExpressionDoubleTestSuite, WhenCalculateExpressionIsCalledWithDivision_ThenCorrectValueIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::U_DOUBLE_VALUE);
    calculator::expression::OperatorExpression<double> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::DIVISION);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::DIVISION_DOUBLE_RESULT);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with a single modulo operation
 */
TEST(OperatorExpressionDoubleTestSuite, WhenCalculateExpressionIsCalledWithModulo_ThenCorrectValueIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::U_DOUBLE_VALUE);
    calculator::expression::OperatorExpression<double> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::MODULO);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::MODULO_DOUBLE_RESULT);
}

/**
 * @brief tests that an OperatorExpression returns the correct value when
 * calculating an expression with multiple operations
 */
TEST(OperatorExpressionDoubleTestSuite, WhenCalculateExpressionIsCalledWithCompoundExpression_ThenCorrectValueIsReturned)
{
    // nodes at depth = 2
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftLeftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>>
            leftRightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::Z_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>> 
            rightLeftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightRightSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::U_DOUBLE_VALUE);
    // nodes at depth = 1
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftSubExpression = std::make_unique<
            calculator::expression::OperatorExpression<double>>(
            std::move(leftLeftSubExpression),
            std::move(leftRightSubExpression),
            calculator::expression::OperatorType::ADDITION);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightSubExpression = std::make_unique<
            calculator::expression::OperatorExpression<double>>(
            std::move(rightLeftSubExpression),
            std::move(rightRightSubExpression),
            calculator::expression::OperatorType::MODULO);
    // nodes at depth = 0
    calculator::expression::OperatorExpression<double> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::DIVISION);
    auto value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::COMPOUND_DOUBLE_RESULT);
}

/**
 * @brief tests that an OperatorExpression will replace symbols as the caller
 * binds values to those symbols and that, only after binding all symbols in the
 * expression, the expression yields a value
 */
TEST(OperatorExpressionDoubleTestSuite, WhenBindValueToSymbolIsCalledWithCompoundExpression_ThenThatSymbolIsReplacedByThatValueInAllSubExpressionsAndTheEntireExpressionWillOnlyHaveAValueWhenAllSymbolsAreBound)
{
    // TODO this test might be too long and complicated. How can we check that 
    // an expression will ONLY yield the correct result after all symbols are
    // bound in a way that also binds multiple symbols?
    // nodes at depth = 2
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftLeftSubExpression = std::make_unique<
            calculator::expression::SymbolExpression<double>>(
            OperatorExpressionTestConstants::GLYPH_X, true);
    std::unique_ptr<calculator::expression::IExpression<double>>
            leftRightSubExpression = std::make_unique<
            calculator::expression::SymbolExpression<double>>(
            OperatorExpressionTestConstants::GLYPH_Z, true);
    std::unique_ptr<calculator::expression::IExpression<double>> 
            rightLeftSubExpression = std::make_unique<
            calculator::expression::SymbolExpression<double>>(
            OperatorExpressionTestConstants::GLYPH_X, true);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightRightSubExpression = std::make_unique<
            calculator::expression::SymbolExpression<double>>(
            OperatorExpressionTestConstants::GLYPH_U, true);
    // nodes at depth = 1
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftSubExpression = std::make_unique<
            calculator::expression::OperatorExpression<double>>(
            std::move(leftLeftSubExpression),
            std::move(leftRightSubExpression),
            calculator::expression::OperatorType::ADDITION);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightSubExpression = std::make_unique<
            calculator::expression::OperatorExpression<double>>(
            std::move(rightLeftSubExpression),
            std::move(rightRightSubExpression),
            calculator::expression::OperatorType::MODULO);
    // nodes at depth = 0
    calculator::expression::OperatorExpression<double> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::DIVISION);

    // start binding variables
    auto value = expression.calculateExpression();
    EXPECT_EQ(value, boost::none);
    auto newExpression = expression.bindValueToSymbol(
            OperatorExpressionTestConstants::GLYPH_X,
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    EXPECT_EQ(newExpression, nullptr);
    value = expression.calculateExpression();
    EXPECT_EQ(value, boost::none);
    newExpression = expression.bindValueToSymbol(
            OperatorExpressionTestConstants::GLYPH_Z,
            OperatorExpressionTestConstants::Z_DOUBLE_VALUE);
    EXPECT_EQ(newExpression, nullptr);
    value = expression.calculateExpression();
    EXPECT_EQ(value, boost::none);
    newExpression = expression.bindValueToSymbol(
            OperatorExpressionTestConstants::GLYPH_U,
            OperatorExpressionTestConstants::U_DOUBLE_VALUE);
    EXPECT_EQ(newExpression, nullptr);
    value = expression.calculateExpression();
    EXPECT_NE(value, boost::none);
    EXPECT_EQ(*value, OperatorExpressionTestConstants::COMPOUND_DOUBLE_RESULT);
}

/**
 * @brief tests that an OperatorExpression builds the correct string
 * representation
 */
TEST(OperatorExpressionDoubleTestSuite, WhenToStringIsCalled_ThenTheCorrectStringValueIsReturned)
{
    std::unique_ptr<calculator::expression::IExpression<double>> 
            leftSubExpression = std::make_unique<
            calculator::expression::ValueExpression<double>>(
            OperatorExpressionTestConstants::X_DOUBLE_VALUE);
    std::unique_ptr<calculator::expression::IExpression<double>>
            rightSubExpression = std::make_unique<
            calculator::expression::SymbolExpression<double>>(
            OperatorExpressionTestConstants::GLYPH_Z, true);
    calculator::expression::OperatorExpression<double> expression(
            std::move(leftSubExpression),
            std::move(rightSubExpression),
            calculator::expression::OperatorType::ADDITION);
    auto stringRepresentation = expression.toString();
    EXPECT_EQ(stringRepresentation, OperatorExpressionTestConstants::DOUBLE_STRING_TEST_EXPRESSION);
}
