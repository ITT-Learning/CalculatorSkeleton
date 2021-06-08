////////////////////////////////////////////////////////////////////////////
/**
 *  @file   SimpleExpressionCalculatorGTest.cpp
 *  @date   Fri, June 11 2021
 *  @brief  Tests for Simple Expression Calculators
 */
////////////////////////////////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "ICalculator.h"
#include "SimpleExpressionCalculatorFactory.h"
#include "AddCalculator.h"
#include "SubtractCalculator.h"
#include "MultiplyCalculator.h"
#include "DivideCalculator.h"

using namespace testing;
using namespace calculator;

/**
 * @brief fixtures for simple expression calculator factory
 * 
 */
class SimpleExpressionCalculatorFactoryTest : public ::testing::Test
{
    protected:
        SimpleExpressionCalculatorFactory simpleExpressionFactory;
};

/**
 * @brief Test to make sure division by zero is handled correctly
 * 
 */
TEST(DivideCalculatorTests, WhenDivideByZeroDivideCalculatorIsConstructed_ThenErrorPrintedToStdError)
{
    testing::internal::CaptureStderr();
    DivideCalculator divideCalculator = DivideCalculator(10, 0);
    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_NE(output, std::string(""));
}


/**
 * @brief Test to make sure a fully formed equation is formed when toString is called
 * 
 */
TEST(DivideCalculatorTests, WhenToStringIsCalledOnDivideCalculators_ThenFullFormattedEquationIsReturned)
{
    DivideCalculator divideCalculator = DivideCalculator(5, 5);
    std::string actual = divideCalculator.toString();
    std::string expected = "5 / 5 = 1";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure a fully formed equation is formed when getExpression is called
 * 
 */
TEST(DivideCalculatorTests, WhenGetExpressionIsCalledOnDivideCalculators_ThenExpressionIsReturned)
{
    DivideCalculator divideCalculator = DivideCalculator(5, 5);
    std::string actual = divideCalculator.getExpression();
    std::string expected = "5 / 5";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure the math is happening as expected
 * @note divide by zero has it's own tests
 * 
 */
TEST(DivideCalculatorTests, WhenGetResultIsCalledOnDivideCalculators_ThenAnswerIsReturned)
{
    DivideCalculator divideCalculator = DivideCalculator(5, 5);
    ASSERT_EQ(1, divideCalculator.getResult());
    
    divideCalculator = DivideCalculator(-10, 5);
    ASSERT_EQ(-2, divideCalculator.getResult());

    divideCalculator = DivideCalculator(10, -5);
    ASSERT_EQ(-2, divideCalculator.getResult());

    divideCalculator = DivideCalculator(0, 100);
    ASSERT_EQ(0, divideCalculator.getResult());

    divideCalculator = DivideCalculator(0, -10);
    ASSERT_EQ(0, divideCalculator.getResult());
}


/**
 * @brief Test to make sure a fully formed equation is formed when toString is called
 * 
 */
TEST(AddCalculatorTests, WhenToStringIsCalledOnAddCalculators_ThenFullFormattedEquationIsReturned)
{
    AddCalculator addCalculator = AddCalculator(5, 5);
    std::string actual = addCalculator.toString();
    std::string expected = "5 + 5 = 10";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure a fully formed equation is formed when getExpression is called
 * 
 */
TEST(AddCalculatorTests, WhenGetExpressionIsCalledOnAddCalculators_ThenExpressionIsReturned)
{
    AddCalculator addCalculator = AddCalculator(5, 5);
    std::string actual = addCalculator.getExpression();
    std::string expected = "5 + 5";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure the math is happening as expected
 * 
 */
TEST(AddCalculatorTests, WhenGetResultIsCalledOnAddCalculators_ThenAnswerIsReturned)
{
    AddCalculator addCalculator = AddCalculator(5, 5);
    ASSERT_EQ(10, addCalculator.getResult());
    
    addCalculator = AddCalculator(-10, 5);
    ASSERT_EQ(-5, addCalculator.getResult());

    addCalculator = AddCalculator(10, -5);
    ASSERT_EQ(5, addCalculator.getResult());

    addCalculator = AddCalculator(0, 100);
    ASSERT_EQ(100, addCalculator.getResult());

    addCalculator = AddCalculator(0, -10);
    ASSERT_EQ(-10, addCalculator.getResult());
}


/**
 * @brief Test to make sure a fully formed equation is formed when toString is called
 * 
 */
TEST(SubtractCalculatorTests, WhenToStringIsCalledOnSubtractCalculators_ThenFullFormattedEquationIsReturned)
{
    SubtractCalculator subtractCalculator = SubtractCalculator(5, 5);
    std::string actual = subtractCalculator.toString();
    std::string expected = "5 - 5 = 0";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure a fully formed equation is formed when getExpression is called
 * 
 */
TEST(SubtractCalculatorTests, WhenGetExpressionIsCalledOnSubtractCalculators_ThenExpressionIsReturned)
{
    SubtractCalculator subtractCalculator = SubtractCalculator(5, 5);
    std::string actual = subtractCalculator.getExpression();
    std::string expected = "5 - 5";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure the math is happening as expected
 * 
 */
TEST(SubtractCalculatorTests, WhenGetResultIsCalledOnSubtractCalculators_ThenAnswerIsReturned)
{
    SubtractCalculator subtractCalculator = SubtractCalculator(5, 5);
    ASSERT_EQ(0, subtractCalculator.getResult());
    
    subtractCalculator = SubtractCalculator(-10, 5);
    ASSERT_EQ(-15, subtractCalculator.getResult());

    subtractCalculator = SubtractCalculator(10, -5);
    ASSERT_EQ(15, subtractCalculator.getResult());

    subtractCalculator = SubtractCalculator(100, 0);
    ASSERT_EQ(100, subtractCalculator.getResult());

    subtractCalculator = SubtractCalculator(0, -10);
    ASSERT_EQ(10, subtractCalculator.getResult());
}


/**
 * @brief Test to make sure a fully formed equation is formed when toString is called
 * 
 */
TEST(MultiplyCalculatorTests, WhenToStringIsCalledOnMultiplyCalculators_ThenFullFormattedEquationIsReturned)
{
    MultiplyCalculator multiplyCalculator = MultiplyCalculator(5, 5);
    std::string actual = multiplyCalculator.toString();
    std::string expected = "5 * 5 = 25";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure a fully formed equation is formed when getExpression is called
 * 
 */
TEST(MultiplyCalculatorTests, WhenGetExpressionIsCalledOnMultiplyCalculators_ThenExpressionIsReturned)
{
    MultiplyCalculator multiplyCalculator = MultiplyCalculator(5, 5);
    std::string actual = multiplyCalculator.getExpression();
    std::string expected = "5 * 5";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure the math is happening as expected
 * 
 */
TEST(MultiplyCalculatorTests, WhenGetResultIsCalledOnMultiplyCalculators_ThenAnswerIsReturned)
{
    MultiplyCalculator multiplyCalculator = MultiplyCalculator(5, 5);
    ASSERT_EQ(25, multiplyCalculator.getResult());
    
    multiplyCalculator = MultiplyCalculator(-10, 5);
    ASSERT_EQ(-50, multiplyCalculator.getResult());

    multiplyCalculator = MultiplyCalculator(10, -5);
    ASSERT_EQ(-50, multiplyCalculator.getResult());

    multiplyCalculator = MultiplyCalculator(0, 100);
    ASSERT_EQ(0, multiplyCalculator.getResult());

    multiplyCalculator = MultiplyCalculator(-10, 0);
    ASSERT_EQ(0, multiplyCalculator.getResult());
}


/**
 * @brief Test to make sure the calculator factory does not contruct calculator objects if the input is invalid
 * 
 */
TEST_F(SimpleExpressionCalculatorFactoryTest, WhenCreateCalculatorIsCalledWithInvalidString_ThenNullPtrIsReturned)
{
    ASSERT_FALSE(simpleExpressionFactory.createCalculator(""));
    ASSERT_FALSE(simpleExpressionFactory.createCalculator("Invalid Input"));
    ASSERT_FALSE(simpleExpressionFactory.createCalculator("100x2 + 34k0"));
    ASSERT_FALSE(simpleExpressionFactory.createCalculator("\n"));
    ASSERT_FALSE(simpleExpressionFactory.createCalculator("                                                                                                      "));
    ASSERT_FALSE(simpleExpressionFactory.createCalculator("10 ? 10"));
    ASSERT_FALSE(simpleExpressionFactory.createCalculator("10 : 10"));
    ASSERT_FALSE(simpleExpressionFactory.createCalculator("10 & 10"));
}

/**
 * @brief Test to make sure a calculator object is constructed if the input is valid
 * 
 */
TEST_F(SimpleExpressionCalculatorFactoryTest, WhenCreateCalculatorIsCalledWithValidString_ThenObjectIsReturned)
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

class MockCalculator : public ICalculator
{
    public:
        MOCK_METHOD(std::string, toString, (), (const final));
        MOCK_METHOD(int, getResult, (), (const final));
        MOCK_METHOD(std::string, getExpression, (), (const final));
};

TEST(CalculatorWeek3Test, ThisIsATestTest)
{
    MockCalculator c;
    EXPECT_CALL(c, toString()).WillOnce(Return("Hello World"));

    std::string s = c.toString();

    EXPECT_EQ(s, "Hello World");
}