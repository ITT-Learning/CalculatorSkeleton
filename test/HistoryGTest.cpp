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
#include "flatbuffers/idl.h"

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
* @brief Unit test for addToHistory without history
*/
TEST_F(whenTestingHistory, WhenTestingAddToHistoryWithoutHistory_AllHistoryUpdatedProperly)
{

    historyInst->addToHistory("1 + 2 = 3");

    std::string historyFile = "historyData.bin";
    const char* checkFile = historyFile.c_str();
    if (flatbuffers::FileExists(checkFile))
    {
        std::remove(checkFile);  
    }
    testing::internal::CaptureStdout();
    historyInst->printHistory();
    std::string result = testing::internal::GetCapturedStdout();

    std::string expected = "No History Available";
    EXPECT_TRUE(result.find(expected));
}

TEST_F(whenTestingHistory, WhenTestingAddToHistoryWithHistory_AllHistoryUpdatedProperly)
{
    std::string historyFile = "historyData.bin";
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
