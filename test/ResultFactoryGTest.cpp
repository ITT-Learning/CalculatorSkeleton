////////////////////////////////////////////////////////////////////////////////
/**
* @file ResultFactoryGTest.cpp
* @brief unit tests for the resultFactory
*/
////////////////////////////////////////////////////////////////////////////////


#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "CalculatorMessages.h"
#include "Parser.h"
#include "IResult.h"
#include "ResultFactory.h"

using namespace calculator;
using namespace testing;

class whenTestingResultFactory:public ::testing::Test
{
    public:
        ResultFactory* resultFactoryInst;
        virtual void SetUp() override;
        virtual void TearDown() override;
};
void whenTestingResultFactory::SetUp()
{
    resultFactoryInst = new ResultFactory();
}
void whenTestingResultFactory::TearDown()
{
    delete resultFactoryInst;
}

TEST_F(whenTestingResultFactory, WhenCreatingResult_CorrectFullResultReturned)
{
    Expression sampleExpression;
    sampleExpression.a=1;
    sampleExpression.b=2;
    sampleExpression.operation='+';
    sampleExpression.valid=true;

    Result sampleResult{sampleExpression, 3, "1 + 2 = 3\n"};
    std::shared_ptr<IResult> sampleIResult = resultFactoryInst->createResult(sampleExpression, 3);

    ASSERT_EQ(sampleIResult->getFullResult(), sampleResult.getFullResult());
}
