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

    std::remove("historyData.bin");
    testing::internal::CaptureStdout();
    historyInst->printHistory();
    std::string result = testing::internal::GetCapturedStdout();

    std::string expected = "No History Available";

    EXPECT_EQ(expected, result);
}

TEST_F(whenTestingHistory, WhenTestingAddToHistoryWithHistory_AllHistoryUpdatedProperly)
{
    std::remove("historyData.bin");
    historyInst->addToHistory("1 + 2 = 3");

    testing::internal::CaptureStdout();
    historyInst->printHistory();
    std::string result = testing::internal::GetCapturedStdout();

    std::string expected = "---History---\n1 + 2 = 3\n---End History---\n";

    EXPECT_EQ(expected, result);
}

TEST_F(whenTestingHistory, WhenTestingAddToHistoryWithMoreHistory_AllHistoryUpdatedProperly)
{
    std::remove("historyData.bin");
    historyInst->addToHistory("1 + 2 = 3");
    historyInst->addToHistory("14-2 = 12");

    testing::internal::CaptureStdout();
    historyInst->printHistory();
    std::string result = testing::internal::GetCapturedStdout();

    std::string expected = "---History---\n1 + 2 = 3\n14-2 = 12\n---End History---\n";

    EXPECT_EQ(expected, result);
}

// I NEED TO START WITH A FRESH REMOVED HISTORY FILE FOR THESE TO WORK
//STD::REMOVE IS NOT WORKING