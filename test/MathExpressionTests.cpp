#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>
#include <set>
#include "MathExpression.h"

using namespace testing;

TEST(MathExpressionTests, WhenPassedAnEquationWithOneVariable_ThenReturnsAOneItemVectorConatainingThatVariable)
{
    std::string equation1 = "foo";
    std::string equation2 = "bar";

    std::set<std::string> expected1 { "foo" };
    std::set<std::string> expected2 { "bar" };

    MathExpression mathExpression1(equation1);
    MathExpression mathExpression2(equation2);

    EXPECT_EQ(expected1, mathExpression1.needsVariableValues());
    EXPECT_EQ(expected2, mathExpression2.needsVariableValues());
};



TEST(MathExpressionTests, WhenPassedAnEquationWithTwoVariables_ThenReturnsATwoItemVectorConatainingThoseVariables)
{
    std::string equation1 = "foo+fooo";
    std::string equation2 = "bar+barr";

    std::set<std::string> expected1 { "foo", "fooo" };
    std::set<std::string> expected2 { "bar", "barr" };

    MathExpression mathExpression1(equation1);
    MathExpression mathExpression2(equation2);

    EXPECT_EQ(expected1, mathExpression1.needsVariableValues());
    EXPECT_EQ(expected2, mathExpression2.needsVariableValues());
};



TEST(MathExpressionTests, WhenPassedAnEquationWithTwoVariablesAndOneGetsAValue_ThenReturnsAOneItemVectorConatainingTheUnsetVariable)
{
    std::string equation1 = "foo+fooo";
    std::string equation2 = "bar+barr";

    std::set<std::string> expected1 { "fooo" };
    std::set<std::string> expected2 { "barr" };

    MathExpression mathExpression1(equation1);
    MathExpression mathExpression2(equation2);

    mathExpression1.setVariableValue("foo", 1);
    mathExpression2.setVariableValue("bar", 2);

    EXPECT_EQ(expected1, mathExpression1.needsVariableValues());
    EXPECT_EQ(expected2, mathExpression2.needsVariableValues());
};



TEST(MathExpressionTests, WhenPopulatingATwoVariableString_ThenThePopulatedStringHasReplacedValues)
{
    std::string equation = "foo+bar";
    std::string expected1 = "5+10";
    std::string expected2 = "3.5+6.5";

    MathExpression mathExpression1(equation);
    MathExpression mathExpression2(equation);

    mathExpression1.setVariableValue("foo", 5);

    auto partialResult1 = mathExpression1.getPopulatedEquation();
    auto partialResult2 = mathExpression2.getPopulatedEquation();
    EXPECT_FALSE(partialResult1.isValid()) << "Equation should not be valid without all variables populated.";
    EXPECT_FALSE(partialResult2.isValid()) << "Equation should not be valid without all variables populated.";

    mathExpression1.setVariableValue("bar", 10);
    mathExpression2.setVariableValue("foo", 3.5);
    mathExpression2.setVariableValue("bar", 6.5);

    auto result1 = mathExpression1.getPopulatedEquation();
    auto result2 = mathExpression2.getPopulatedEquation();
    EXPECT_TRUE(result1.isValid()) << "Error message: " << result1.getError();
    EXPECT_TRUE(result2.isValid()) << "Error message: " << result2.getError();

    EXPECT_EQ(expected1, *result1.consumeResult());
    EXPECT_EQ(expected2, *result2.consumeResult());
};