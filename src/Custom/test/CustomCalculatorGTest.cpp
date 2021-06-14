//////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CustomCalculatorGTest.cpp
 *  @date   Thu, June 10 2021
 *  @brief  Tests for CustomCalculator
 */
////////////////////////////////////////////////////////////////////////////


#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "CustomCalculator.h"

using namespace testing;
using namespace calculator;

static bool isEqual(double a, double b)
{
    return fabs(a - b) < DBL_EPSILON;
}

/**
 * @brief simple fixture for CustomCalculator for simple functions
 */
class CustomCalculatorTests: public ::testing::Test
{
    protected:
        std::string addThreeFormat = "{} + {} + {}";
        std::string threeFormat = "{} {} {}";
        std::string twoFormat = "{} {}";
        std::function<int(std::vector<int>)> sumInts =
                [](const std::vector<int>& terms)
                {
                    int sum = 0;
                    for(int term : terms)
                    {
                        sum += term;
                    }
                    return sum;
                };
        std::function<double(std::vector<double>)> sumDoubles =
                [](const std::vector<double>& terms)
                {
                    double sum = 0;
                    for(double term : terms)
                    {
                        sum += term;
                    }
                    return sum;
                };
};

/**
 * @brief Positive case to make sure result is correct
 */
TEST_F(CustomCalculatorTests, WhenGetResultIsCalledWithCustomCalculator_ThenAnswerReturned)
{
    CustomCalculator<int> calculator1{{1, 2, 3}, sumInts, addThreeFormat};
    ASSERT_EQ(6, calculator1.getResult());
    CustomCalculator<double> calculator2{{0.01, 2.5, 3.99}, sumDoubles, addThreeFormat};
    ASSERT_TRUE(isEqual(6.5, calculator2.getResult()));
}


/**
 * @brief positive case to make sure GetExpression is accurate
 */
TEST_F(CustomCalculatorTests, WhenGetExpressionIsCalledWithCustomCalculator_ThenFormattedExpressionReturned)
{
    CustomCalculator<int> calculator1 {{1, 5, 100}, [](auto f){return 0;}, threeFormat};
    ASSERT_EQ("1 5 100", calculator1.getExpression());

    // this is not ideal. But would need to not use vformat() ... but then I can't use dynamic_argument_store... so it
    // would require a pretty big rework.
    CustomCalculator<float> calculator2 {{1.1, 5.5, 100.25}, [](auto f){return 0;}, threeFormat};
    ASSERT_EQ("1 5 100", calculator2.getExpression());
}


/**
 * @brief Positive case to make sure toString is correctly concatenating expression and result
 */
TEST_F(CustomCalculatorTests, WhenToStringIsCalledWithCustomCalculator_ThenFormattedEquationReturned)
{
    CustomCalculator<int> calculator1 {{1, 5, 100}, [](auto f){return 0;}, threeFormat};
    ASSERT_EQ("1 5 100 = 0", calculator1.toString());

    CustomCalculator<float> calculator2 {{1.1, 5.5, 100.25}, [](auto f){return 0;}, threeFormat};
    ASSERT_EQ("1 5 100 = 0", calculator2.toString());
}

/**
 * @brief negative case if argument count does not match between terms and format string
 */
TEST_F(CustomCalculatorTests, WhenGetExpressionIsCalledWithCustomCalculatorWithMismatchedTermAndFormatArguments_ThenEmptyStringReturnedAndErrorMessageOut)
{
    CustomCalculator<int> calculator1 {{1, 5, 100}, [](auto f){return 0;}, twoFormat};
    testing::internal::CaptureStderr();
    std::string expression1 = calculator1.getExpression();
    std::string output1 = testing::internal::GetCapturedStderr();
    ASSERT_NE(output1, std::string(""));
    ASSERT_EQ("", expression1);

    CustomCalculator<int> calculator2 {{1}, [](auto f){return 0;}, twoFormat};
    testing::internal::CaptureStderr();
    std::string expression2 = calculator2.getExpression();
    std::string output2 = testing::internal::GetCapturedStderr();
    ASSERT_NE(output2, std::string(""));
    ASSERT_EQ("", expression2);
}