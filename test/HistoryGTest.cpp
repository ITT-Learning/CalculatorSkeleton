////////////////////////////////////////////////////////////////////////////////
/**
* @file HistoryGTest.cpp
* @brief unit tests for history functions
*/
////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "History.h"

using namespace calculator;
using namespace testing;

class whenTestingHistory:public ::testing::Test
{
    public:
        History* historyInst;
        virtual void SetUp() override;
        virtual void TearDown() override;
};
void whenTestingHistory::SetUp()
{
    historyInst = new History();
}
void whenTestingHistory::TearDown()
{
    delete historyInst;
}

/**
* @brief Unit test for getCurrentHistory
*/
TEST_F(whenTestingHistory, WhenGettingCurrentHistoryWithoutHistory_CorrectEmptyVectorReturned)
{
    std::vector<std::string> expected = std::vector<std::string>{};
    std::vector<std::string> result = historyInst->getCurrentHistory();

    EXPECT_EQ(expected, result);
}

/**
* @brief Unit test for addToHistory
*/
TEST_F(whenTestingHistory, WhenGettingCurrentHistoryWithHistory_CorrectVectorReturned)
{
    std::vector<std::string> expected = std::vector<std::string>{};
    expected.push_back("1 + 1 = 2");

    historyInst->addToHistory("1 + 1 = 2");
    std::vector<std::string> result = historyInst->getCurrentHistory();

    EXPECT_EQ(expected.at(0), result.at(0));
}

