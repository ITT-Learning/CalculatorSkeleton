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
TEST(DivideCalculatorW3Tests, WhenDivideByZeroDivideCalculatorIsConstructed_ThenErrorPrintedToStdError)
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
TEST(DivideCalculatorW3Tests, WhenToStringIsCalledOnDivideCalculators_ThenFullFormattedEquationIsReturned)
{
    DivideCalculatorW3 divideCalculator = DivideCalculatorW3(5, 5);
    std::string actual = divideCalculator.toString();
    std::string expected = "5 / 5 = 1";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure a fully formed equation is formed when getExpression is called
 * 
 */
TEST(DivideCalculatorW3Tests, WhenGetExpressionIsCalledOnDivideCalculators_ThenExpressionIsReturned)
{
    DivideCalculatorW3 divideCalculator = DivideCalculatorW3(5, 5);
    std::string actual = divideCalculator.getExpression();
    std::string expected = "5 / 5";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure the math is happening as expected
 * @note divide by zero has it's own tests
 * 
 */
TEST(DivideCalculatorW3Tests, WhenGetResultIsCalledOnDivideCalculators_ThenAnswerIsReturned)
{
    DivideCalculatorW3 divideCalculator = DivideCalculatorW3(5, 5);
    ASSERT_EQ(1, divideCalculator.getResult());
    
    divideCalculator = DivideCalculatorW3(-10, 5);
    ASSERT_EQ(-2, divideCalculator.getResult());

    divideCalculator = DivideCalculatorW3(10, -5);
    ASSERT_EQ(-2, divideCalculator.getResult());

    divideCalculator = DivideCalculatorW3(0, 100);
    ASSERT_EQ(0, divideCalculator.getResult());

    divideCalculator = DivideCalculatorW3(0, -10);
    ASSERT_EQ(0, divideCalculator.getResult());
}


/**
 * @brief Test to make sure a fully formed equation is formed when toString is called
 * 
 */
TEST(AddCalculatorW3Tests, WhenToStringIsCalledOnAddCalculators_ThenFullFormattedEquationIsReturned)
{
    AddCalculatorW3 addCalculator = AddCalculatorW3(5, 5);
    std::string actual = addCalculator.toString();
    std::string expected = "5 + 5 = 10";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure a fully formed equation is formed when getExpression is called
 * 
 */
TEST(AddCalculatorW3Tests, WhenGetExpressionIsCalledOnAddCalculators_ThenExpressionIsReturned)
{
    AddCalculatorW3 addCalculator = AddCalculatorW3(5, 5);
    std::string actual = addCalculator.getExpression();
    std::string expected = "5 + 5";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure the math is happening as expected
 * 
 */
TEST(AddCalculatorW3Tests, WhenGetResultIsCalledOnAddCalculators_ThenAnswerIsReturned)
{
    AddCalculatorW3 addCalculator = AddCalculatorW3(5, 5);
    ASSERT_EQ(10, addCalculator.getResult());
    
    addCalculator = AddCalculatorW3(-10, 5);
    ASSERT_EQ(-5, addCalculator.getResult());

    addCalculator = AddCalculatorW3(10, -5);
    ASSERT_EQ(5, addCalculator.getResult());

    addCalculator = AddCalculatorW3(0, 100);
    ASSERT_EQ(100, addCalculator.getResult());

    addCalculator = AddCalculatorW3(0, -10);
    ASSERT_EQ(-10, addCalculator.getResult());
}


/**
 * @brief Test to make sure a fully formed equation is formed when toString is called
 * 
 */
TEST(SubtractCalculatorW3Tests, WhenToStringIsCalledOnSubtractCalculators_ThenFullFormattedEquationIsReturned)
{
    SubtractCalculatorW3 subtractCalculator = SubtractCalculatorW3(5, 5);
    std::string actual = subtractCalculator.toString();
    std::string expected = "5 - 5 = 0";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure a fully formed equation is formed when getExpression is called
 * 
 */
TEST(SubtractCalculatorW3Tests, WhenGetExpressionIsCalledOnSubtractCalculators_ThenExpressionIsReturned)
{
    SubtractCalculatorW3 subtractCalculator = SubtractCalculatorW3(5, 5);
    std::string actual = subtractCalculator.getExpression();
    std::string expected = "5 - 5";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure the math is happening as expected
 * 
 */
TEST(SubtractCalculatorW3Tests, WhenGetResultIsCalledOnSubtractCalculators_ThenAnswerIsReturned)
{
    SubtractCalculatorW3 subtractCalculator = SubtractCalculatorW3(5, 5);
    ASSERT_EQ(0, subtractCalculator.getResult());
    
    subtractCalculator = SubtractCalculatorW3(-10, 5);
    ASSERT_EQ(-15, subtractCalculator.getResult());

    subtractCalculator = SubtractCalculatorW3(10, -5);
    ASSERT_EQ(15, subtractCalculator.getResult());

    subtractCalculator = SubtractCalculatorW3(100, 0);
    ASSERT_EQ(100, subtractCalculator.getResult());

    subtractCalculator = SubtractCalculatorW3(0, -10);
    ASSERT_EQ(10, subtractCalculator.getResult());
}


/**
 * @brief Test to make sure a fully formed equation is formed when toString is called
 * 
 */
TEST(MultiplyCalculatorW3Tests, WhenToStringIsCalledOnMultiplyCalculators_ThenFullFormattedEquationIsReturned)
{
    MultiplyCalculatorW3 multiplyCalculator = MultiplyCalculatorW3(5, 5);
    std::string actual = multiplyCalculator.toString();
    std::string expected = "5 * 5 = 25";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure a fully formed equation is formed when getExpression is called
 * 
 */
TEST(MultiplyCalculatorW3Tests, WhenGetExpressionIsCalledOnMultiplyCalculators_ThenExpressionIsReturned)
{
    MultiplyCalculatorW3 multiplyCalculator = MultiplyCalculatorW3(5, 5);
    std::string actual = multiplyCalculator.getExpression();
    std::string expected = "5 * 5";
    ASSERT_EQ(expected, actual);
}

/**
 * @brief Test to make sure the math is happening as expected
 * 
 */
TEST(MultiplyCalculatorW3Tests, WhenGetResultIsCalledOnMultiplyCalculators_ThenAnswerIsReturned)
{
    MultiplyCalculatorW3 multiplyCalculator = MultiplyCalculatorW3(5, 5);
    ASSERT_EQ(25, multiplyCalculator.getResult());
    
    multiplyCalculator = MultiplyCalculatorW3(-10, 5);
    ASSERT_EQ(-50, multiplyCalculator.getResult());

    multiplyCalculator = MultiplyCalculatorW3(10, -5);
    ASSERT_EQ(-50, multiplyCalculator.getResult());

    multiplyCalculator = MultiplyCalculatorW3(0, 100);
    ASSERT_EQ(0, multiplyCalculator.getResult());

    multiplyCalculator = MultiplyCalculatorW3(-10, 0);
    ASSERT_EQ(0, multiplyCalculator.getResult());
}


/**
 * @brief Test to make sure the calculator factory does not contruct calculator objects if the input is invalid
 * 
 */
TEST_F(SimpleExpressionCalculatorW3FactoryTest, WhenCreateCalculatorIsCalledWithInvalidString_ThenNullPtrIsReturned)
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