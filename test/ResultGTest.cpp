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
    sampleExpression.a=1;
    sampleExpression.b=2;
    sampleExpression.operation='+';

    resultInst = new Result("1 + 2", 3, "1 + 2 = 3");
}
void whenTestingResult::TearDown()
{
    delete resultInst;
}

TEST_F(whenTestingResult, WhenCreatingResult_CorrectFullResultReturned)
{
    ASSERT_EQ(resultInst->getFullResult(), "1 + 2 = 3");
}
