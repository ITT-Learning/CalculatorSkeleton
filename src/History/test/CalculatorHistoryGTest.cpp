////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CalculatorHistoryGTest.cpp
 *  @date   Tue, June 22 2021
 *  @brief  Tests for Calculator History and implementation of flatbuffers
 */
////////////////////////////////////////////////////////////////////////////

#include <memory>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "AddCalculator.h"
#include "TermCalculator.h"
#include "CompoundExpressionCalculator.h"
#include "History.h"

using namespace testing;
using namespace calculator;

/**
 * @brief Fixture of Compound Expression Calculator. Contains calculators that are used in tests
 */
class CalculatorHistoryTests : public ::testing::Test
{
    protected:
        std::shared_ptr<History> history = History::getInstance();
        TermCalculator termCalculator {10};
        AddCalculator simpleCalculator{10,10};
        CompoundExpressionCalculator compoundCalculator{{{'a', 1}, {'b', 2}, {'c', 3}}, "a + b + c"};

        void SetUp() override
        {
            history->appendCalculator(TermCalculator(1));
            history->appendCalculator(simpleCalculator);
            history->appendCalculator(compoundCalculator);
        }

        void TearDown() override
        {
            history->clear();
        }

};

/**
 * @brief Simple test to check if history is a singleton
 */
TEST_F(CalculatorHistoryTests, WhenHistoryGetInstanceIsCalled_ThenHistorySingletonObjectReturned)
{
    EXPECT_EQ(history, History::getInstance());
}

/**
 * @brief Test to see if Calculators is increasing with each appended object
 */
TEST_F(CalculatorHistoryTests, WhenAppendCalculatorIsCalledWithCalculator_ThenCalculatorsSizeIncreases)
{
    int initialSize = history->getSize();
    history->appendCalculator(termCalculator);
    EXPECT_GT(history->getSize(), initialSize);

    initialSize = history->getSize();
    history->appendCalculator(compoundCalculator);
    EXPECT_GT(history->getSize(), initialSize);

    initialSize = history->getSize();
    history->appendCalculator(simpleCalculator);
    EXPECT_GT(history->getSize(), initialSize);
}

/**
 * @brief Test to make sure get calculator works -- 2 should be the last element
 */
TEST_F(CalculatorHistoryTests, WhenGetCalculatorIsCalledWithValidIndex_ThenCalculatorFlatbufferObjectIsReturned)
{
    EXPECT_TRUE(history->getCalculator(0));
    EXPECT_TRUE(history->getCalculator(1));
    EXPECT_TRUE(history->getCalculator(2));
}

/**
 * @brief test to make sure out of bound indices are handled with a nullptr
 */
TEST_F(CalculatorHistoryTests, WhenGetCalculatorIsCalledWithInvalidIndex_ThenNullptrIsReturned)
{
    EXPECT_FALSE(history->getCalculator(-1));
    EXPECT_FALSE(history->getCalculator(3));
    EXPECT_FALSE(history->getCalculator(999));
}

/**
 * @brief Test to make sure history is cleared with clear
 */
TEST_F(CalculatorHistoryTests, WhenClearIsCalled_ThenCalculatorsContainerIsEmpty)
{
    //expecting the history from the fixture to have a size
    int initialSize = history->getSize();
    EXPECT_GT(initialSize, 0);

    history->clear();

    EXPECT_EQ(history->getSize(), 0);
}

TEST_F(CalculatorHistoryTests, WhenBuildHistoryIsCalled_ThenFlatbufferHistoryObjectReturned)
{
    EXPECT_TRUE(history->getBuiltHistory());
}

TEST_F(CalculatorHistoryTests, WhenGetCalculatorIsCalled_ThenExpectedCalculatorIsReturned)
{
    auto calc0 = history->getCalculator(0); //1
    auto calc1 = history->getCalculator(1); //10 + 10 = 20
    auto calc2 = history->getCalculator(2); //1 + 2 + 3 = 6

    EXPECT_EQ("1", calc0->full_equation);
    EXPECT_EQ("10 + 10 = 20", calc1->full_equation);
    EXPECT_EQ("1 + 2 + 3 = 6", calc2->full_equation);
}

TEST_F(CalculatorHistoryTests, WhenGetBuiltHistoryIsCalled_ThenExpectedListOfIsReturned)
{
    auto &calc0 = history->getBuiltHistory()->list[0]; //1
    auto &calc1 = history->getBuiltHistory()->list[1]; //10 + 10 = 20
    auto &calc2 = history->getBuiltHistory()->list[2]; //1 + 2 + 3 = 6

    EXPECT_EQ("1", calc0->full_equation);
    EXPECT_EQ("10 + 10 = 20", calc1->full_equation);
    EXPECT_EQ("1 + 2 + 3 = 6", calc2->full_equation);
}