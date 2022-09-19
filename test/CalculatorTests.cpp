#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

#include "Calculator.h"
#include "IOperationFactory.h"
#include "FourOperationFactory.h"
#include "Result.h"



class GivenACalculatorWithAFourOperationFactory : public ::testing::Test
{
    protected:
        const Calculator calculator_;
        GivenACalculatorWithAFourOperationFactory()
        : calculator_(std::make_unique<FourOperationFactory>()) {};
};

TEST_F(GivenACalculatorWithAFourOperationFactory, WhenCalculatingOnAnEmptyString_ThenReturnsAnInvalidResult)
{
    auto result = calculator_.calculateResult("");
    EXPECT_FALSE(result.isValid());
    EXPECT_EQ(result.getError(), "No valid equation");
};