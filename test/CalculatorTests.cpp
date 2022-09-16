#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

#include "Calculator.h"
#include "IOperationFactory.h"

// class MockOperationFactory : public IOperationFactory
// {

// };

// class GivenACalculatorWithAFourOperationFactory : public ::testing::Test
// {
//     protected:
//         const Calculator calculator_;
//         GivenACalculatorWithAFourOperationFactory()
//         : calculator_(MockOperationFactory()) {};
// };

// TEST_F(GivenACalculatorWithAFourOperationFactory, WhenGivenAnEmptyString_Then)
