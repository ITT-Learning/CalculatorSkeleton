////////////////////////////////////////////////////////////////////////////////
/**
* @file ResultGTest.cpp
* @brief unit tests for the result
*/
////////////////////////////////////////////////////////////////////////////////


#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "CalculatorMessages.h"
#include "Parser.h"
#include "Result.h"

using namespace calculator;
using namespace testing;

class whenTestingResult:public ::testing::Test
{
    public:
        Result* resultInst;
        virtual void SetUp() override;
        virtual void TearDown() override;
};
void whenTestingResult::SetUp()
{
    Expression sampleExpression;
    sampleExpression.number1 = 1;
    sampleExpression.number2 = 2;
    sampleExpression.operation = CalculatorMessages::ADD;

    resultInst = new Result("1 + 2", 3, "1 + 2 = 3");
}
void whenTestingResult::TearDown()
{
    delete resultInst;
}

/**
* @brief Unit test for getting the full Result from a Result object
*/
TEST_F(whenTestingResult, WhenGettingFullResult_CorrectFullResultReturned)
{
    EXPECT_EQ("1 + 2 = 3", resultInst->getFullResult());
}
