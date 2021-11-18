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
#include "Result.h"
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

/**
* @brief Unit test for creating a result object
*/
TEST_F(whenTestingResultFactory, WhenCreatingResult_CorrectFullResultReturned)
{
    Result sampleResult{"1 + 2", 3, "1 + 2 = 3"};
    std::shared_ptr<IResult> sampleIResult = resultFactoryInst->createResult("1 + 2", 3);

    EXPECT_EQ(sampleResult.getFullResult(), sampleIResult->getFullResult());
}
