////////////////////////////////////////////////////////////////////////////////
/**
* @file HistoryGTest.cpp
* @brief unit tests for history functions
*/
////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <string>
#include <vector>

#include "CalculatorMessages.h"
#include "flatbuffers/idl.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "History.h"

using namespace calculator;
using namespace testing;

/**
* @brief Unit Tests for History
*/
class whenTestingHistory : public ::testing::Test
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
* @brief Unit test for addToHistory without history
*/
TEST_F(whenTestingHistory, WhenTestingAddToHistoryWithoutHistory_AllHistoryUpdatedProperly)
{
    historyInst->addToHistory("1 + 2 = 3");

    std::string historyFile = CalculatorMessages::HISTORY_FILE;
    const char* checkFile = historyFile.c_str();
    if (flatbuffers::FileExists(checkFile))
    {
        std::remove(checkFile);  
    }
    testing::internal::CaptureStdout();
    historyInst->printHistory();
    std::string result = testing::internal::GetCapturedStdout();

    std::string expected = CalculatorMessages::NO_HISTORY;
    EXPECT_TRUE(result.find(expected));
}

/**
* @brief Unit test for addToHistory with history
*/
TEST_F(whenTestingHistory, WhenTestingAddToHistoryWithHistory_AllHistoryUpdatedProperly)
{
    std::string historyFile = CalculatorMessages::HISTORY_FILE;
    const char* checkFile = historyFile.c_str();
    if (flatbuffers::FileExists(checkFile))
    {
        std::remove(checkFile);  
    }

    historyInst->addToHistory("1 + 2 = 3");
    testing::internal::CaptureStdout();
    historyInst->printHistory();
    std::string result = testing::internal::GetCapturedStdout();

    std::string expected = "1 + 2 = 3";

    EXPECT_TRUE(result.find(expected));
}
