////////////////////////////////////////////////////////////////////////////////
/**
 * @file ExpressionFactoryGtest.cpp
 * @date Tues March 1 2022
 * @brief test suites which test ExpressionFactory functionality and its various
 * template specializations
 */
////////////////////////////////////////////////////////////////////////////////

#include <boost/optional.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../inc/ExpressionFactory.h"

/**
 * @brief a collection of constants used by the ExpressionFactory test suites
 */
class ExpressionFactoryTestConstants
{
public:
    /**
     * @brief random text that should fail to be parsed
     */
    static constexpr const char *RANDOM_TEXT = "asdf";
    /**
     * @brief random text followed by a single operator expression that should
     * fail to be parsed
     */
    static constexpr const char *RANDOM_TEXT_BEFORE_NO_SPACE = "asdf7 * 5";
    /**
     * @brief random text followed by a space and then a single operator 
     * expression that should fail to be parsed
     */
    static constexpr const char *RANDOM_TEXT_BEFORE_SPACE = "asdf 7 * 5";
    /**
     * @brief a single operator expression followed by random text that should
     * fail to be parsed
     */
    static constexpr const char *RANDOM_TEXT_AFTER_NO_SPACE = "7 * 5asdf";
    /**
     * @brief a single operator expression followed by a space and then random
     * text that should fail to be parsed
     */
    static constexpr const char *RANDOM_TEXT_AFTER_SPACE = "7 * 5 asdf";
    /**
     * @brief a single operator expression with an unknown operator that should
     * fail to be parsed
     */
    static constexpr const char *BAD_OPERATOR = "7 ^ 5";
    /**
     * @brief a valid expression with two operators that may fail or succeed to
     * be parsed depending on the factory method used
     */
    static constexpr const char *TOO_MANY_OPERATORS = "7 * 5 * 12";
    /**
     * @brief a single operator expression with a number string that is too big
     * to fit into the corresponding type that should fail to be parsed
     */
    static constexpr const char *INT_TOO_BIG = "98572670273489809756093840958609384098509843 + 3";
    /**
     * @brief a syntactically valid expression that should successfully be
     * parsed but should also fail to be evaluated, either as an int or double
     */
    static constexpr const char *INT_DIV_BY_ZERO = "9 / 0";
    /**
     * @brief a valid addition expression that should successfully be parsed and
     * evaluated, both as an int expression and as a double expression
     */
    static constexpr const char *GOOD_INT_ADD = "5 + 7";
    /**
     * @brief a valid addition expression containing no spaces that should
     * successfully be parsed and evaluated, both as an int expression and as a
     * double expression
     */
    static constexpr const char *GOOD_INT_ADD_NO_SPACES = "5+7";
    /**
     * @brief the expected int result when the GOOD_INT_ADD expression is
     * evaulated
     */
    static constexpr int         GOOD_INT_ADD_INT_RESULT = 5 + 7;
    /**
     * @brief the expected double result when the GOOD_INT_ADD expression is
     * evaulated as a double expression
     */
    static constexpr double      GOOD_INT_ADD_DOUBLE_RESULT = 5.0 + 7.0;
    /**
     * @brief a valid subtraction expression that should successfully be parsed
     * and evaluated, despite its two adjacent minus signs
     */
    static constexpr const char *GOOD_INT_SUBTRACT = "1--5";
    /**
     * @brief the expected result when the good integer subtraction expression
     * is evaluated
     */
    static constexpr int         GOOD_INT_SUBTRACT_RESULT = 1 - -5;
    /**
     * @brief a valid multiplication expression that should successfully be
     * parsed and evaluated
     */
    static constexpr const char *GOOD_INT_MULTIPLICATION = "3 * -12";
    /**
     * @brief the expected result when the good integer multiplication
     * expression is evaluated
     */
    static constexpr int         GOOD_INT_MULTIPLICATION_RESULT = 3 * -12;
    /**
     * @brief a valid division expression that should successfully be parsed and
     * evaluated
     */
    static constexpr const char *GOOD_INT_DIVISION = "9 / 4";
    /**
     * @brief the expected result when the good integer division expression is
     * evaluated
     */
    static constexpr int         GOOD_INT_DIVISION_RESULT = 9 / 4;
    /**
     * @brief a valid modulo expression that should successfully be parsed and
     * evaluated
     */
    static constexpr const char *GOOD_INT_MODULO = "10 % 4";
    /**
     * @brief the expected result when the good integer modulo expression is
     * evaluated
     */
    static constexpr int         GOOD_INT_MODULO_RESULT = 10 % 4;
    /**
     * @brief a single operator expression with a number string that is too big
     * to fit into the corresponding type that should fail to be parsed
     */
    static constexpr const char *DOUBLE_TOO_BIG = "9E+400 + 3";
    /**
     * @brief a valid double addition expression that should successfully be
     * parsed and evaluated as a double expression
     */
    static constexpr const char *GOOD_DOUBLE_ADD = "5.34 + 0.71";
    /**
     * @brief the expected result when the good double addition expression is
     * evaluated
     */
    static constexpr double      GOOD_DOUBLE_ADD_RESULT = 5.34 + 0.71;
    /**
     * @brief a valid double subtraction expression that should successfully be
     * parsed and evaluated as a double expression
     */
    static constexpr const char *GOOD_DOUBLE_SUBTRACT = "1.1112--0.5317";
    /**
     * @brief the expected result when the good double subtraction expression is
     * evaluated
     */
    static constexpr double      GOOD_DOUBLE_SUBTRACT_RESULT = 1.1112 - -0.5317;
    /**
     * @brief a valid double multiplication expression that should successfully
     * be parsed and evaluated as a double expression
     */
    static constexpr const char *GOOD_DOUBLE_MULTIPLY = "3.119 * -1.2345";
    /**
     * @brief the expected result when the good double multiplication expression
     * is evaluated
     */
    static constexpr double      GOOD_DOUBLE_MULTIPLY_RESULT = 3.119 * -1.2345;
    /**
     * @brief a valid double division expression that should successfully be
     * parsed and evaluated as a double expression
     */
    static constexpr const char *GOOD_DOUBLE_DIVIDE = "9.9 / 0.4388";
    /**
     * @brief the expected result when the good double division expression is
     * evaluated
     */
    static constexpr double      GOOD_DOUBLE_DIVIDE_RESULT = 9.9 / 0.4388;
    /**
     * @brief a valid double modulo expression that should successfully be
     * parsed and evaluated as a double expression
     */
    static constexpr const char *GOOD_DOUBLE_MODULO = "10.443 % 3.9";
    /**
     * @brief the expected result when the good double modulo expression is
     * evaluated
     */
    static constexpr double      GOOD_DOUBLE_MODULO_RESULT = 2.643;
};
constexpr const char *ExpressionFactoryTestConstants::RANDOM_TEXT;
constexpr const char *ExpressionFactoryTestConstants::RANDOM_TEXT_BEFORE_NO_SPACE;
constexpr const char *ExpressionFactoryTestConstants::RANDOM_TEXT_BEFORE_SPACE;
constexpr const char *ExpressionFactoryTestConstants::RANDOM_TEXT_AFTER_NO_SPACE;
constexpr const char *ExpressionFactoryTestConstants::RANDOM_TEXT_AFTER_SPACE;
constexpr const char *ExpressionFactoryTestConstants::INT_TOO_BIG;
constexpr const char *ExpressionFactoryTestConstants::BAD_OPERATOR;
constexpr const char *ExpressionFactoryTestConstants::TOO_MANY_OPERATORS;
constexpr const char *ExpressionFactoryTestConstants::INT_DIV_BY_ZERO;
constexpr const char *ExpressionFactoryTestConstants::GOOD_INT_ADD;
constexpr const char *ExpressionFactoryTestConstants::GOOD_INT_ADD_NO_SPACES;
constexpr int         ExpressionFactoryTestConstants::GOOD_INT_ADD_INT_RESULT;
constexpr double      ExpressionFactoryTestConstants::GOOD_INT_ADD_DOUBLE_RESULT;
constexpr const char *ExpressionFactoryTestConstants::GOOD_INT_SUBTRACT;
constexpr const int   ExpressionFactoryTestConstants::GOOD_INT_SUBTRACT_RESULT;
constexpr const char *ExpressionFactoryTestConstants::GOOD_INT_MULTIPLICATION;
constexpr int         ExpressionFactoryTestConstants::GOOD_INT_MULTIPLICATION_RESULT;
constexpr const char *ExpressionFactoryTestConstants::GOOD_INT_DIVISION;
constexpr int         ExpressionFactoryTestConstants::GOOD_INT_DIVISION_RESULT;
constexpr const char *ExpressionFactoryTestConstants::GOOD_INT_MODULO;
constexpr int         ExpressionFactoryTestConstants::GOOD_INT_MODULO_RESULT;
constexpr const char *ExpressionFactoryTestConstants::DOUBLE_TOO_BIG;
constexpr const char *ExpressionFactoryTestConstants::GOOD_DOUBLE_ADD;
constexpr double      ExpressionFactoryTestConstants::GOOD_DOUBLE_ADD_RESULT;
constexpr const char *ExpressionFactoryTestConstants::GOOD_DOUBLE_SUBTRACT;
constexpr double      ExpressionFactoryTestConstants::GOOD_DOUBLE_SUBTRACT_RESULT;
constexpr const char *ExpressionFactoryTestConstants::GOOD_DOUBLE_MULTIPLY;
constexpr double      ExpressionFactoryTestConstants::GOOD_DOUBLE_MULTIPLY_RESULT;
constexpr const char *ExpressionFactoryTestConstants::GOOD_DOUBLE_DIVIDE;
constexpr double      ExpressionFactoryTestConstants::GOOD_DOUBLE_DIVIDE_RESULT;
constexpr const char *ExpressionFactoryTestConstants::GOOD_DOUBLE_MODULO;
constexpr double      ExpressionFactoryTestConstants::GOOD_DOUBLE_MODULO_RESULT;

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a known random string is given, which should return no
 * expression
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithRandomText_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::RANDOM_TEXT});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a known random string followed by a valid single operator string
 * is given, which should return no expression
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithRandomTextBeforeValidExpression_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::
            RANDOM_TEXT_BEFORE_NO_SPACE});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a known random string followed by a space followed by a valid
 * single operator string is given, which should return no expression
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithRandomTextBeforeSpaceAndValidExpression_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::
            RANDOM_TEXT_BEFORE_SPACE});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single operator string followed by a known random string
 * is given, which should return no expression
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithRandomTextAfterValidExpression_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::
            RANDOM_TEXT_AFTER_NO_SPACE});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single operator string followed by a space followed by a
 * known random string is given, which should return no expression
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithRandomTextAfterValidExpressionAndSpace_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::
            RANDOM_TEXT_AFTER_SPACE});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a single operator string with a number that is too big to be
 * contained in the corresponding type is given, which should return no
 * expression
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithTooBigANumber_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::INT_TOO_BIG});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a single operator string with an unknown operator is given,
 * which should return no expression
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithAnUnknownOperator_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::BAD_OPERATOR});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid expression string is given, but with too many operators,
 * which should return no expression
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithTooManyOperators_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::TOO_MANY_OPERATORS});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid expression is given, but which attempts to divide by
 * zero, which should return an expression which fails to evaluate a result
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithDivideByZeroExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeNone)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::INT_DIV_BY_ZERO});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_EQ(calculation, boost::none);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single addition string is given, which should return an
 * expression that evaluates to the expected result
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidAdditionExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_INT_ADD});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_EQ(*calculation, ExpressionFactoryTestConstants::GOOD_INT_ADD_INT_RESULT);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single addition string without spaces is given, which
 * should return an expression that evaluates to the expected result
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidAdditionExpressionWithNoSpaces_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_INT_ADD_NO_SPACES});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_EQ(*calculation, ExpressionFactoryTestConstants::GOOD_INT_ADD_INT_RESULT);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single subtraction string with two adjacent subtraction
 * signs is given, which should return an expression that evaluates to the
 * expected result, even with two adjacent subtraction signs
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidSubtractionExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_INT_SUBTRACT});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_EQ(*calculation, ExpressionFactoryTestConstants::GOOD_INT_SUBTRACT_RESULT);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single multiplication string is given, which should
 * return an expression that evaluates to the expected result
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidMultiplicationExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_INT_MULTIPLICATION});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_EQ(*calculation, ExpressionFactoryTestConstants::GOOD_INT_MULTIPLICATION_RESULT);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single division string is given, which should return an
 * expression that evaluates to the expected result
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidDivisionExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_INT_DIVISION});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_EQ(*calculation, ExpressionFactoryTestConstants::GOOD_INT_DIVISION_RESULT);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single modulo string is given, which should return an
 * expression that evaluates to the expected result
 */
TEST(ExpressionFactoryIntTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidModuloExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<int>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_INT_MODULO});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_EQ(*calculation, ExpressionFactoryTestConstants::GOOD_INT_MODULO_RESULT);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a known random string is given, which should return no
 * expression
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithRandomText_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::RANDOM_TEXT});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a known random string followed by a valid single operator string
 * is given, which should return no expression
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithRandomTextBeforeValidExpression_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::
            RANDOM_TEXT_BEFORE_NO_SPACE});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a known random string followed by a space followed by a valid
 * single operator string is given, which should return no expression
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithRandomTextBeforeSpaceAndValidExpression_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::
            RANDOM_TEXT_BEFORE_SPACE});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single operator string followed by a known random string
 * is given, which should return no expression
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithRandomTextAfterValidExpression_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::
            RANDOM_TEXT_AFTER_NO_SPACE});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single operator string followed by a space followed by a
 * known random string is given, which should return no expression
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithRandomTextAfterValidExpressionAndSpace_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::
            RANDOM_TEXT_AFTER_SPACE});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a single operator string with a number that is too big to be
 * contained in the corresponding type is given, which should return no
 * expression
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithTooBigANumber_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::DOUBLE_TOO_BIG});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a single operator string with an unknown operator is given,
 * which should return no expression
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithAnUnknownOperator_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::BAD_OPERATOR});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid expression string is given, but with too many operators,
 * which should return no expression
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithTooManyOperators_ThenNoneWillBeReturned)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::TOO_MANY_OPERATORS});
    EXPECT_EQ(result, nullptr);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid expression is given, but which attempts to divide by
 * zero, which should return an expression which fails to evaluate a result
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithDivideByZeroExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeNone)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::INT_DIV_BY_ZERO});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_EQ(calculation, boost::none);
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single addition string is given, which should return an
 * expression that evaluates to the expected result
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidAdditionExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_DOUBLE_ADD});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_NEAR(*calculation,
            ExpressionFactoryTestConstants::GOOD_DOUBLE_ADD_RESULT,
            128 * (nextafter(*calculation, INFINITY) - *calculation));
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single addition string without spaces is given, which
 * should return an expression that evaluates to the expected result
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidAdditionExpressionWithNoSpaces_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_INT_ADD_NO_SPACES});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_NEAR(*calculation,
            ExpressionFactoryTestConstants::GOOD_INT_ADD_DOUBLE_RESULT,
            128 * (nextafter(*calculation, INFINITY) - *calculation));
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single subtraction string with two adjacent subtraction
 * signs is given, which should return an expression that evaluates to the
 * expected result, even with two adjacent subtraction signs
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidSubtractionExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_DOUBLE_SUBTRACT});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_NEAR(*calculation,
            ExpressionFactoryTestConstants::GOOD_DOUBLE_SUBTRACT_RESULT,
            128 * (nextafter(*calculation, INFINITY) - *calculation));
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single multiplication string is given, which should
 * return an expression that evaluates to the expected result
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidMultiplicationExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_DOUBLE_MULTIPLY});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_NEAR(*calculation,
            ExpressionFactoryTestConstants::GOOD_DOUBLE_MULTIPLY_RESULT,
            128 * (nextafter(*calculation, INFINITY) - *calculation));
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single division string is given, which should return an
 * expression that evaluates to the expected result
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidDivisionExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_DOUBLE_DIVIDE});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_NEAR(*calculation,
            ExpressionFactoryTestConstants::GOOD_DOUBLE_DIVIDE_RESULT,
            128 * (nextafter(*calculation, INFINITY) - *calculation));
}

/**
 * @brief tests the building of an expression when a single operator string is
 * expected and a valid single modulo string is given, which should return an
 * expression that evaluates to the expected result
 */
TEST(ExpressionFactoryDoubleTestSuite,
        WhenParseFromSingleOperationStringIsCalledWithValidModuloExpression_ThenAnExpressionWillBeReturnedAndItsValueWillBeCorrect)
{
    auto result = calculator::expression::ExpressionFactory<double>::
            parseFromSingleOperationString(
            std::string{ExpressionFactoryTestConstants::GOOD_DOUBLE_MODULO});
    EXPECT_NE(result, nullptr);
    auto calculation = result->calculateExpression();
    EXPECT_NE(calculation, boost::none);
    EXPECT_NEAR(*calculation,
            ExpressionFactoryTestConstants::GOOD_DOUBLE_MODULO_RESULT,
            128 * (nextafter(*calculation, INFINITY) - *calculation));
}
