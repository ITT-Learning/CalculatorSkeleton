////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorGtest.cpp
 *  @date   Wed May 26 2021
 *  @brief  CalculatorW2 Unit Tests
 */
////////////////////////////////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include <vector>
#include "CalculatorW2.h"

using namespace testing;
using namespace calculator;

/**
 * @brief Test to see if a valid calculator returns the correct equation
 * 
 */
TEST(Week2CalculatorTests, WhenToStringIsCalledWithValidCalculators_ThenFormattedEquationReturned)
{
    CalculatorW2 valid1(1, 2, CalculatorW2::Operation::ADD);
    CalculatorW2 valid2("10 / 5");

    EXPECT_EQ("1 + 2 = 3", to_string(valid1));
    EXPECT_EQ("10 / 5 = 2", to_string(valid2));
}

/**
 * @brief Test a calculator that had invalid input and returns appropriate error message
 * 
 */
TEST(Week2CalculatorTests, WhenToStringIsCalledWithInvalidCalculators_ThenErrorMessageReturnedWithInvalidInput)
{
    CalculatorW2 invalid1("");
    CalculatorW2 invalid2("10 100");
    CalculatorW2 invalid3("Hello CalculatorW2");

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
    CalculatorW2 divideByZero1("10 / 0");
    CalculatorW2 divideByZero2(10, 0, CalculatorW2::Operation::DIVIDE);

    EXPECT_EQ("Error: divide by zero", to_string(divideByZero1));
    EXPECT_EQ("Error: divide by zero", to_string(divideByZero2));
}

/**
 * @brief Test valid calculators if they return the correct result
 * 
 */
TEST(Week2CalculatorTests, WhenGetResultsIsCalledWithValidCalculator_ThenReturnCorrectResult)
{
    EXPECT_EQ(100, CalculatorW2("10 * 10").getResult());
    EXPECT_EQ(2, CalculatorW2("10 / 5").getResult());
    EXPECT_EQ(15, CalculatorW2("11 + 4").getResult());
    EXPECT_EQ(5, CalculatorW2("10 - 5").getResult());
    EXPECT_EQ(10, CalculatorW2(5, 5, CalculatorW2::Operation::ADD).getResult());
    EXPECT_EQ(1, CalculatorW2(10, 10, CalculatorW2::Operation::DIVIDE).getResult());
    EXPECT_EQ(50, CalculatorW2(50, 0, CalculatorW2::Operation::SUBTRACT).getResult());
    EXPECT_EQ(250, CalculatorW2(50, 5, CalculatorW2::Operation::MULTIPLY).getResult());
}

/**
 * @brief Test the result of a calculator if a calculator has invalid input or tried to divide by zero
 * 
 */
TEST(Week2CalculatorTests, WhenGetResultsIsCalledWithErrorCalculator_ThenReturnZero)
{
    EXPECT_EQ(0, CalculatorW2("").getResult());
    EXPECT_EQ(0, CalculatorW2(10, 0, CalculatorW2::Operation::DIVIDE).getResult());
}


// I am going to leave these test here instead of deleting them just for reference
// 


// I don't think my implementation of CalculatorW2 makes a lot sense with a fixture
// Mostly here so I can test it out -- week 3 implementation I should be able
// to do more with fixtures and mocks
class calculatorTest : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            divideByZeroCalculator_ = new CalculatorW2(10, 0, CalculatorW2::Operation::DIVIDE);
            defaultConstructorCalculator_ = new CalculatorW2();

            //try out smart pointers here instead
            invalidInputCalculators_ = 
                {
                new CalculatorW2("This should not work"),
                new CalculatorW2("100 & 1000"),
                new CalculatorW2("10 100"),
                new CalculatorW2("103 hello there")
                };
            validInputCalculators_ =
                {
                    new CalculatorW2("100 + 100"),
                    new CalculatorW2("-10 - -10"),
                    new CalculatorW2("500 * 1000"),
                    new CalculatorW2("10000 / 13")
                };

        }

        void TearDown() override
        {
            delete defaultConstructorCalculator_;
            delete divideByZeroCalculator_;
            for (CalculatorW2* calculator : invalidInputCalculators_)
            {
                delete calculator;
            }
            for (CalculatorW2* calculator : validInputCalculators_)
            {
                delete calculator;
            }
        }
    
    CalculatorW2* defaultConstructorCalculator_;
    CalculatorW2* divideByZeroCalculator_;
    std::vector<CalculatorW2*> invalidInputCalculators_;
    std::vector<CalculatorW2*> validInputCalculators_;
};

TEST_F(calculatorTest, defaultTest)
{
    CalculatorW2 c = *defaultConstructorCalculator_;
    EXPECT_EQ("0 + 0 = 0" ,to_string(c));
    EXPECT_EQ(0, c.getResult());
}

TEST_F(calculatorTest, invalidTests)
{
    for(CalculatorW2* calc : invalidInputCalculators_)
    {
        EXPECT_EQ("Error: invalid input", to_string(*calc));
    }
    EXPECT_EQ("Error: divide by zero", to_string(*divideByZeroCalculator_));
}

TEST_F(calculatorTest, validTests)
{
    for(CalculatorW2* calc : validInputCalculators_)
    {
        EXPECT_NE("Error: invalid input", to_string(*calc));
    }
}