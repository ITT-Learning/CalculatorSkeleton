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


// I don't think my implementation of Calculator makes a lot with a fixture
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
        EXPECT_EQ("Error:  invalid input ", to_string(*calc));
    }
    EXPECT_EQ("Error:  divide by zero ", to_string(*divideByZeroCalculator_));
}

TEST_F(calculatorTest, validTests)
{
    for(Calculator* calc : validInputCalculators_)
    {
        EXPECT_NE("Error:  invalid input ", to_string(*calc));
    }
}