////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorGtest.cpp
 *  @date   Wed May 26 2021
 *  @brief  Calculator Unit Tests
 */
////////////////////////////////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include <vector>
#include "Calculator.h"

using namespace testing;
using namespace calculator;

/**
 * @brief Test to see if a valid calculator returns the correct equation
 * 
 */
TEST(Week2CalculatorTests, WhenToStringIsCalledWithValidCalculators_ThenFormattedEquationReturned)
{
    Calculator valid1(1, 2, Calculator::Operation::ADD);
    Calculator valid2("10 / 5");

    EXPECT_EQ("1 + 2 = 3", to_string(valid1));
    EXPECT_EQ("10 / 5 = 2", to_string(valid2));
}

/**
 * @brief Test a calculator that had invalid input and returns appropriate error message
 * 
 */
TEST(Week2CalculatorTests, WhenToStringIsCalledWithInvalidCalculators_ThenErrorMessageReturnedWithInvalidInput)
{
    Calculator invalid1("");
    Calculator invalid2("10 100");
    Calculator invalid3("Hello Calculator");

    EXPECT_EQ("Error: invalid input", to_string(invalid1));
    EXPECT_EQ("Error: invalid input", to_string(invalid2));
    EXPECT_EQ("Error: invalid input", to_string(invalid3));
}

/**
 * @brief Test if calculator returns divide by zero error if it attempted to divide by zero
 * 
 */
TEST(Week2CalculatorTests, WhenToStringIsCalledWithDivideByZeroCalculator_ThenErrorMessageReturnedWithDivideByZero)
{
    Calculator divideByZero1("10 / 0");
    Calculator divideByZero2(10, 0, Calculator::Operation::DIVIDE);

    EXPECT_EQ("Error: divide by zero", to_string(divideByZero1));
    EXPECT_EQ("Error: divide by zero", to_string(divideByZero2));
}

/**
 * @brief Test valid calculators if they return the correct result
 * 
 */
TEST(Week2CalculatorTests, WhenGetResultsIsCalledWithValidCalculator_ThenReturnCorrectResult)
{
    EXPECT_EQ(100, Calculator("10 * 10").getResult());
    EXPECT_EQ(2, Calculator("10 / 5").getResult());
    EXPECT_EQ(15, Calculator("11 + 4").getResult());
    EXPECT_EQ(5, Calculator("10 - 5").getResult());
    EXPECT_EQ(10, Calculator(5, 5, Calculator::Operation::ADD).getResult());
    EXPECT_EQ(1, Calculator(10, 10, Calculator::Operation::DIVIDE).getResult());
    EXPECT_EQ(50, Calculator(50, 0, Calculator::Operation::SUBTRACT).getResult());
    EXPECT_EQ(250, Calculator(50, 5, Calculator::Operation::MULTIPLY).getResult());
}

/**
 * @brief Test the result of a calculator if a calculator has invalid input or tried to divide by zero
 * 
 */
TEST(Week2CalculatorTests, WhenGetResultsIsCalledWithErrorCalculator_ThenReturnZero)
{
    EXPECT_EQ(0, Calculator("").getResult());
    EXPECT_EQ(0, Calculator(10, 0, Calculator::Operation::DIVIDE).getResult());
}


// I am going to leave these test here instead of deleting them just for reference
// 


// I don't think my implementation of Calculator makes a lot sense with a fixture
// Mostly here so I can test it out -- week 3 implementation I should be able
// to do more with fixtures and mocks
class calculatorTest : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            divideByZeroCalculator_ = new Calculator(10, 0, Calculator::Operation::DIVIDE);
            defaultConstructorCalculator_ = new Calculator();

            //try out smart pointers here instead
            invalidInputCalculators_ = 
                {
                new Calculator("This should not work"),
                new Calculator("100 & 1000"),
                new Calculator("10 100"),
                new Calculator("103 hello there")
                };
            validInputCalculators_ =
                {
                    new Calculator("100 + 100"),
                    new Calculator("-10 - -10"),
                    new Calculator("500 * 1000"),
                    new Calculator("10000 / 13")
                };

        }

        void TearDown() override
        {
            delete defaultConstructorCalculator_;
            delete divideByZeroCalculator_;
            for (Calculator* calculator : invalidInputCalculators_)
            {
                delete calculator;
            }
            for (Calculator* calculator : validInputCalculators_)
            {
                delete calculator;
            }
        }
    
    Calculator* defaultConstructorCalculator_;
    Calculator* divideByZeroCalculator_;
    std::vector<Calculator*> invalidInputCalculators_;
    std::vector<Calculator*> validInputCalculators_;
};

TEST_F(calculatorTest, defaultTest)
{
    Calculator c = *defaultConstructorCalculator_;
    EXPECT_EQ("0 + 0 = 0" ,to_string(c));
    EXPECT_EQ(0, c.getResult());
}

TEST_F(calculatorTest, invalidTests)
{
    for(Calculator* calc : invalidInputCalculators_)
    {
        EXPECT_EQ("Error: invalid input", to_string(*calc));
    }
    EXPECT_EQ("Error: divide by zero", to_string(*divideByZeroCalculator_));
}

TEST_F(calculatorTest, validTests)
{
    for(Calculator* calc : validInputCalculators_)
    {
        EXPECT_NE("Error: invalid input", to_string(*calc));
    }
}