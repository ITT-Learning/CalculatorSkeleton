////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorGtest.cpp
 *  @date   Wed May 26 2021
 *  @brief  Calculator Unit Tests
 */
////////////////////////////////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "ICalculatorW3.h"
#include "SimpleExpressionCalculatorW3Factory.h"
#include "AddCalculatorW3.h"
#include "SubtractCalculatorW3.h"
#include "MultiplyCalculatorW3.h"
#include "DivideCalculatorW3.h"

using namespace testing;
using namespace calculator;

/**
 * @brief Fixture for Simple expression calulcators
 * 
 */
class SimpleExpressionCalculatorW3Test : public ::testing::Test 
{
    protected:
        AddCalculatorW3 addCalculator = AddCalculatorW3(10,10);
        SubtractCalculatorW3 subtractCalculator = SubtractCalculatorW3(10, 10);
        MultiplyCalculatorW3 multiplyCalculator = MultiplyCalculatorW3(10, 10);
        DivideCalculatorW3 divideCalculator = DivideCalculatorW3(10, 10);
};

/**
 * @brief fixtures for simple expression calculator factory
 * 
 */
class SimpleExpressionCalculatorW3FactoryTest : public ::testing::Test
{
    protected:
        SimpleExpressionCalculatorW3Factory simpleExpressionFactory;
};

/**
 * @brief Test to make sure division by zero is handled correctly
 * 
 */
TEST(CalculatorW3Tests, WhenDivideByZeroDivideCalculatorIsConstructed_ThenErrorPrintedToStdError)
{
    testing::internal::CaptureStderr();
    DivideCalculatorW3 divideCalculator = DivideCalculatorW3(10, 0);
    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_NE(output, std::string(""));
}

/**
 * @brief Test to make sure a fully formed equation is formed when toString is called
 * 
 */
TEST_F(SimpleExpressionCalculatorW3Test, WhenToStringIsCalledOnSimpleExpressionCalculators_ThenFullFormattedEquationIsReturned)
{
    ASSERT_TRUE(addCalculator.toString().find('=') != std::string::npos);
    ASSERT_TRUE(addCalculator.toString().find('+') != std::string::npos);
    ASSERT_TRUE(subtractCalculator.toString().find('=') != std::string::npos);
    ASSERT_TRUE(subtractCalculator.toString().find('-') != std::string::npos);
    ASSERT_TRUE(multiplyCalculator.toString().find('=') != std::string::npos);
    ASSERT_TRUE(multiplyCalculator.toString().find('*') != std::string::npos);
    ASSERT_TRUE(divideCalculator.toString().find('=') != std::string::npos);
    ASSERT_TRUE(divideCalculator.toString().find('/') != std::string::npos);
}

/**
 * @brief Test to make sure the math is happening as expected
 * 
 */
TEST_F(SimpleExpressionCalculatorW3Test, WhenGetResultIsCalledOnSimpleExpressionCalculators_ThenAnswerIsReturned)
{
    ASSERT_EQ(20, addCalculator.getResult());
    ASSERT_EQ(0, subtractCalculator.getResult());
    ASSERT_EQ(100, multiplyCalculator.getResult());
    ASSERT_EQ(1, divideCalculator.getResult());
}

/**
 * @brief Test to make sure the expression is NOT a fully formed equation, i.e. it should NOT have an '='
 * 
 */
TEST_F(SimpleExpressionCalculatorW3Test, WhenGetExpressionIsCalledOnSimpleExpessionCalculators_ThenExpressionIsReturned)
{
    ASSERT_TRUE(addCalculator.getExpression().find('=') == std::string::npos);
    ASSERT_TRUE(addCalculator.getExpression().find('+') != std::string::npos);
    ASSERT_TRUE(subtractCalculator.getExpression().find('=') == std::string::npos);
    ASSERT_TRUE(subtractCalculator.getExpression().find('-') != std::string::npos);
    ASSERT_TRUE(multiplyCalculator.getExpression().find('=') == std::string::npos);
    ASSERT_TRUE(multiplyCalculator.getExpression().find('*') != std::string::npos);
    ASSERT_TRUE(divideCalculator.getExpression().find('=') == std::string::npos);
    ASSERT_TRUE(divideCalculator.getExpression().find('/') != std::string::npos);
}

/**
 * @brief Test to make sure the calculator factory does not contruct calculator objects if the input is invalid
 * 
 */
TEST_F(SimpleExpressionCalculatorW3FactoryTest, WhenCreateCalculatorIsCalledWithInvalidString_ThenNullPtrIsReturned)
{
    ASSERT_FALSE(simpleExpressionFactory.createCalculator(""));
    ASSERT_FALSE(simpleExpressionFactory.createCalculator("Invalid Input"));
    ASSERT_FALSE(simpleExpressionFactory.createCalculator("10 ? 10"));
}

/**
 * @brief Test to make sure a calculator object is constructed if the input is valid
 * 
 */
TEST_F(SimpleExpressionCalculatorW3FactoryTest, WhenCreateCalculatorIsCalledWithValidString_ThenObjectIsReturned)
{
    ASSERT_TRUE(simpleExpressionFactory.createCalculator("5 + 5"));
    ASSERT_TRUE(simpleExpressionFactory.createCalculator("5 - 5"));
    ASSERT_TRUE(simpleExpressionFactory.createCalculator("5 * 5"));
    ASSERT_TRUE(simpleExpressionFactory.createCalculator("5 / 5"));
}

// With my current implementation I don't think mocking makes a lot of sense
// leaving this here just for reference. I think in later implementations it will make more sense
using ::testing::AtLeast;
using ::testing::Return;

class MockCalculator : public ICalculatorW3
{
    public:
        MOCK_METHOD(std::string, toString, (), (override));
        MOCK_METHOD(int, getResult, (), (override));
        MOCK_METHOD(std::string, getExpression, (), (override));
};

TEST(CalculatorWeek3Test, ThisIsATestTest)
{
    MockCalculator c;
    EXPECT_CALL(c, toString()).WillOnce(Return("Hello World"));

    std::string s = c.toString();

    EXPECT_EQ(s, "Hello World");
}