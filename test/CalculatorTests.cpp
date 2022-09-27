#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

#include "Calculator.h"

#include <string>
#include <vector>
#include <memory>

#include "MathExpression.h"
#include "IOperationFactory.h"
#include "FourOperationFactory.h"
#include "Result.h"
#include "Addition.h"
#include "Constant.h"



class MockOperationFactory : public IOperationFactory
{
    public:
        MOCK_METHOD(
            std::unique_ptr<IMathOperation>, 
            getOperationFor,
            (
                std::string operatorName,
                std::unique_ptr<IMathOperation>&& lhs,
                std::unique_ptr<IMathOperation>&& rhs
            ),
            (const, override)
        );

        MOCK_METHOD(
            std::unique_ptr<IMathOperation>,
            getConstantFor,
            (double constantValue),
            (const, override)
        );
};



class MockMathOperation : public IMathOperation
{
    public:
        MOCK_METHOD(double, calculate, (), (override));
};



class GivenACalculatorWithAFourOperationFactory : public ::testing::Test
{
    protected:
        const Calculator calculator_;
        GivenACalculatorWithAFourOperationFactory()
        : calculator_(std::make_unique<FourOperationFactory>()) {};
};



TEST_F(GivenACalculatorWithAFourOperationFactory, WhenCalculatingOnAnEmptyString_ThenReturnsAnInvalidResultWithCorrectErrorMessage)
{
    auto result = calculator_.calculateResult("");
    std::string expectedErrorMessage = "No valid equation";

    EXPECT_FALSE(result.isValid()) << "Result should be invalid";
    EXPECT_EQ(expectedErrorMessage, result.getError()) << "Error message should be \"" << expectedErrorMessage << "\" (was \"" << result.getError() << "\")";
};



TEST(GivenACalculator, WhenCalculatingOnAStringWithInvalidCharacters_ThenReturnsAValidResultWhileIgnoringInvaildCharacters)
{

    std::string potentiallyBadString = "1+abc1";
    double expectedResult = 2;

    std::vector<double>       postfixConstants { 1, 1 };
    std::vector<std::string>  postfixOperators { "+" };

    int constantCallCount = postfixConstants.size();
    int operatorCallCount = postfixOperators.size();


    std::unique_ptr<MockOperationFactory> mockOperationFactory = std::make_unique<MockOperationFactory>();
    EXPECT_CALL(*mockOperationFactory, getConstantFor)
        .Times(Exactly(constantCallCount))
        .WillRepeatedly(Invoke(
            [&postfixConstants, &constantCallCount]
            (double constantValue) -> std::unique_ptr<IMathOperation>
            {
                EXPECT_EQ(postfixConstants[--constantCallCount], constantValue);
                return std::make_unique<MockMathOperation>();
            }
        ));

    EXPECT_CALL(*mockOperationFactory, getOperationFor)
        .Times(Exactly(operatorCallCount))
        .WillRepeatedly(Invoke(
            [&postfixOperators, &operatorCallCount, expectedResult]
            (std::string operatorName,
            std::unique_ptr<IMathOperation>&& lhs,
            std::unique_ptr<IMathOperation>&& rhs)
            {
                EXPECT_EQ(postfixOperators[--operatorCallCount], operatorName);
                std::unique_ptr<MockMathOperation> newOperation = std::make_unique<MockMathOperation>();
                EXPECT_CALL(*newOperation, calculate)
                    .WillRepeatedly(Invoke(
                        [expectedResult]
                        () -> double
                        {
                            return expectedResult;
                        }
                    ));
                return std::unique_ptr<MockMathOperation>(std::move(newOperation));
            }
        ));

    Calculator calculator(std::move(mockOperationFactory));

    auto result = calculator.calculateResult(potentiallyBadString);

    EXPECT_TRUE(result.isValid()) << "Result should be valid";
    EXPECT_DOUBLE_EQ(expectedResult, *result.consumeResult()) << "Should evaluate \"" << potentiallyBadString << "\" to " << expectedResult;
};



TEST_F(GivenACalculatorWithAFourOperationFactory, WhenCalculatingOnAStringWithBothMissingOperands_ThenReturnsAnInvalidResultWithCorrectErrorMessage)
{
    auto result = calculator_.calculateResult("+");
    std::string expectedErrorMessage = "Missing operands";

    EXPECT_FALSE(result.isValid()) << "Result should be invalid";
    EXPECT_EQ(expectedErrorMessage, result.getError()) << "Error message should be \"" << expectedErrorMessage << "\" (was \"" << result.getError() << "\")";
};



TEST_F(GivenACalculatorWithAFourOperationFactory, WhenCalculatingOnAStringWithMissingSecondOperand_ThenReturnsAnInvalidResultWithCorrectErrorMessage)
{
    auto result = calculator_.calculateResult("1+");
    std::string expectedErrorMessage = "Missing operands";

    EXPECT_FALSE(result.isValid()) << "Result should be invalid";
    EXPECT_EQ(expectedErrorMessage, result.getError()) << "Error message should be \"" << expectedErrorMessage << "\" (was \"" << result.getError() << "\")";
};



TEST_F(GivenACalculatorWithAFourOperationFactory, WhenCalculatingOnAStringWithMissingFirstOperand_ThenReturnsAnInvalidResultWithCorrectErrorMessage)
{
    auto result = calculator_.calculateResult("+1");
    std::string expectedErrorMessage = "Missing operands";

    EXPECT_FALSE(result.isValid()) << "Result should be invalid";
    EXPECT_EQ(expectedErrorMessage, result.getError()) << "Error message should be \"" << expectedErrorMessage << "\" (was \"" << result.getError() << "\")";
};



TEST_F(GivenACalculatorWithAFourOperationFactory, WhenCalculatingOnAStringWithMissingClosingParenthesis_ThenReturnsAnInvalidResultWithCorrectErrorMessage)
{
    auto result = calculator_.calculateResult("(1+1");
    std::string expectedErrorMessage = "Missing closing parenthesis";

    EXPECT_FALSE(result.isValid()) << "Result should be invalid";
    EXPECT_EQ(expectedErrorMessage, result.getError()) << "Error message should be \"" << expectedErrorMessage << "\" (was \"" << result.getError() << "\")";
};



TEST_F(GivenACalculatorWithAFourOperationFactory, WhenCalculatingOnAStringWithMissingMultipleClosingParenthesis_ThenReturnsAnInvalidResultWithCorrectErrorMessage)
{
    auto result = calculator_.calculateResult("(((1+1)");
    std::string expectedErrorMessage = "Missing closing parenthesis";

    EXPECT_FALSE(result.isValid()) << "Result should be invalid";
    EXPECT_EQ(expectedErrorMessage, result.getError()) << "Error message should be \"" << expectedErrorMessage << "\" (was \"" << result.getError() << "\")";
};



TEST_F(GivenACalculatorWithAFourOperationFactory, WhenCalculatingOnAStringWithMissingOpeningParenthesis_ThenReturnsAnInvalidResultWithCorrectErrorMessage)
{
    auto result = calculator_.calculateResult("1+1)");
    std::string expectedErrorMessage = "Too many closing parenthesis";

    EXPECT_FALSE(result.isValid()) << "Result should be invalid";
    EXPECT_EQ(expectedErrorMessage, result.getError()) << "Error message should be \"" << expectedErrorMessage << "\" (was \"" << result.getError() << "\")";
};



TEST_F(GivenACalculatorWithAFourOperationFactory, WhenCalculatingOnAStringWithMissingMultipleOpeningParenthesis_ThenReturnsAnInvalidResultWithCorrectErrorMessage)
{
    auto result = calculator_.calculateResult("(1+1)))");
    std::string expectedErrorMessage = "Too many closing parenthesis";

    EXPECT_FALSE(result.isValid()) << "Result should be invalid";
    EXPECT_EQ(expectedErrorMessage, result.getError()) << "Error message should be \"" << expectedErrorMessage << "\" (was \"" << result.getError() << "\")";
};



TEST_F(GivenACalculatorWithAFourOperationFactory, WhenCalculatingOnAStringWithMissingOperatorBeforeParenthesis_ThenReturnsAnInvalidResultWithCorrectErrorMessage)
{
    auto result = calculator_.calculateResult("1(1+1)");
    std::string expectedErrorMessage = "Missing operator before parenthesis";

    EXPECT_FALSE(result.isValid()) << "Result should be invalid";
    EXPECT_EQ(expectedErrorMessage, result.getError()) << "Error message should be \"" << expectedErrorMessage << "\" (was \"" << result.getError() << "\")";
};



TEST_F(GivenACalculatorWithAFourOperationFactory, WhenCalculatingOnAStringWithMissingOperatorAfterParenthesis_ThenReturnsAnInvalidResultWithCorrectErrorMessage)
{
    auto result = calculator_.calculateResult("(1+1)1");
    std::string expectedErrorMessage = "Missing operator after parenthesis";

    EXPECT_FALSE(result.isValid()) << "Result should be invalid";
    EXPECT_EQ(expectedErrorMessage, result.getError()) << "Error message should be \"" << expectedErrorMessage << "\" (was \"" << result.getError() << "\")";
};



TEST(GivenACalculator, WhenCalculatingOnALargeExpression_ThenRespectsOrderOfOperations)
{

    std::string               infixEquation1 = "10+10*10+(10*(10+10))";
    std::vector<double>       postfixConstants1 { 10, 10, 10, 10, 10, 10 };
    std::vector<std::string>  postfixOperators1 { "+", "*", "*", "+", "+" };
    double                    expectedResult1 = 310;

    int constantCallCount1 = 0;
    int operatorCallCount1 = 0;
    
    std::string               infixEquation2 = "10+10*10+10*10+10";
    std::vector<double>       postfixConstants2 { 10, 10, 10, 10, 10, 10 };
    std::vector<std::string>  postfixOperators2 { "*", "*", "+", "+", "+" };
    double                    expectedResult2 = 220;

    int constantCallCount2 = 0;
    int operatorCallCount2 = 0;

    std::unique_ptr<MockOperationFactory> mockOperationFactory1 = std::make_unique<MockOperationFactory>();
    EXPECT_CALL(*mockOperationFactory1, getConstantFor)
        .Times(Exactly(postfixConstants1.size()))
        .WillRepeatedly(Invoke(
            [&postfixConstants1, &constantCallCount1]
            (double constantValue) -> std::unique_ptr<IMathOperation>
            {
                EXPECT_EQ(postfixConstants1[constantCallCount1], constantValue) << "failed on constantCallCount1 = " << constantCallCount1;
                constantCallCount1++;
                return std::make_unique<MockMathOperation>();
            }
        ));

    EXPECT_CALL(*mockOperationFactory1, getOperationFor)
        .Times(Exactly(postfixOperators1.size()))
        .WillRepeatedly(Invoke(
            [&postfixOperators1, &operatorCallCount1, expectedResult1]
            (std::string operatorName,
            std::unique_ptr<IMathOperation>&& lhs,
            std::unique_ptr<IMathOperation>&& rhs) -> std::unique_ptr<IMathOperation>
            {
                EXPECT_EQ(postfixOperators1[operatorCallCount1], operatorName) << "failed on operatorCallCount1 = " << operatorCallCount1;
                operatorCallCount1++;
                std::unique_ptr<MockMathOperation> newOperation = std::make_unique<MockMathOperation>();
                EXPECT_CALL(*newOperation, calculate)
                    .WillRepeatedly(Invoke(
                        [expectedResult1]
                        () -> double
                        {
                            return expectedResult1;
                        }
                    ));
                return std::unique_ptr<MockMathOperation>(std::move(newOperation));
            }
        ));

    std::unique_ptr<MockOperationFactory> mockOperationFactory2 = std::make_unique<MockOperationFactory>();
    EXPECT_CALL(*mockOperationFactory2, getConstantFor)
        .Times(Exactly(postfixConstants2.size()))
        .WillRepeatedly(Invoke(
            [&postfixConstants2, &constantCallCount2]
            (double constantValue) -> std::unique_ptr<IMathOperation>
            {
                EXPECT_EQ(postfixConstants2[constantCallCount2], constantValue) << "failed on constantCallCount2 = " << constantCallCount2;
                constantCallCount2++;
                return std::make_unique<MockMathOperation>();
            }
        ));

    EXPECT_CALL(*mockOperationFactory2, getOperationFor)
        .Times(Exactly(postfixOperators2.size()))
        .WillRepeatedly(Invoke(
            [&postfixOperators2, &operatorCallCount2, expectedResult2]
            (std::string operatorName,
            std::unique_ptr<IMathOperation>&& lhs,
            std::unique_ptr<IMathOperation>&& rhs) -> std::unique_ptr<IMathOperation>
            {
                EXPECT_EQ(postfixOperators2[operatorCallCount2], operatorName)  << "failed on operatorCallCount2 = " << operatorCallCount2;
                operatorCallCount2++;
                std::unique_ptr<MockMathOperation> newOperation = std::make_unique<MockMathOperation>();
                EXPECT_CALL(*newOperation, calculate)
                    .WillRepeatedly(Invoke(
                        [expectedResult2]
                        () -> double
                        {
                            return expectedResult2;
                        }
                    ));
                return std::unique_ptr<MockMathOperation>(std::move(newOperation));
            }
        ));

    Calculator calculator1(std::move(mockOperationFactory1));
    Calculator calculator2(std::move(mockOperationFactory2));

    auto result1 = calculator1.calculateResult(infixEquation1);
    auto result2 = calculator2.calculateResult(infixEquation2);

    ASSERT_TRUE(result1.isValid()) << "Result 1 should be valid - error: " << result1.getError();
    ASSERT_TRUE(result2.isValid()) << "Result 2 should be valid - error: " << result2.getError();
    EXPECT_EQ(expectedResult1, *result1.consumeResult());
    EXPECT_EQ(expectedResult2, *result2.consumeResult());
};



TEST(GivenACalculator, WhenParsingAnEquationWithANegativeNumber_ThenDoesntTreatItAsSubtraction)
{
    std::string               infixEquation = "10+-2";
    std::vector<double>       postfixConstants { -2, 10 };
    std::vector<std::string>  postfixOperators { "+" };
    double                    expectedResult = 8;

    int constantCallCount = 0;
    int operatorCallCount = 0;

    std::unique_ptr<MockOperationFactory> mockOperationFactory = std::make_unique<MockOperationFactory>();
    EXPECT_CALL(*mockOperationFactory, getConstantFor)
        .Times(Exactly(postfixConstants.size()))
        .WillRepeatedly(Invoke(
            [&postfixConstants, &constantCallCount]
            (double constantValue) -> std::unique_ptr<IMathOperation>
            {
                EXPECT_EQ(postfixConstants[constantCallCount], constantValue) << "failed on constantCallCount = " << constantCallCount;
                constantCallCount++;
                return std::make_unique<MockMathOperation>();
            }
        ));

    EXPECT_CALL(*mockOperationFactory, getOperationFor)
        .Times(Exactly(postfixOperators.size()))
        .WillRepeatedly(Invoke(
            [&postfixOperators, &operatorCallCount, expectedResult]
            (std::string operatorName,
            std::unique_ptr<IMathOperation>&& lhs,
            std::unique_ptr<IMathOperation>&& rhs) -> std::unique_ptr<IMathOperation>
            {
                EXPECT_EQ(postfixOperators[operatorCallCount], operatorName) << "failed on operatorCallCount = " << operatorCallCount;
                operatorCallCount++;
                std::unique_ptr<MockMathOperation> newOperation = std::make_unique<MockMathOperation>();
                EXPECT_CALL(*newOperation, calculate)
                    .WillRepeatedly(Invoke(
                        [expectedResult]
                        () -> double
                        {
                            return expectedResult;
                        }
                    ));
                return std::unique_ptr<MockMathOperation>(std::move(newOperation));
            }
        ));

    Calculator calculator(std::move(mockOperationFactory));
    auto result = calculator.calculateResult(infixEquation);

    EXPECT_TRUE(result.isValid()) << "Result falied with message: \"" << result.getError() << "\"";
    EXPECT_DOUBLE_EQ(expectedResult, *result.consumeResult());
};

TEST_F(GivenACalculatorWithAFourOperationFactory, WhenParsingAnEquationSubtractingANegativeNumber_ThenActsLikeAddition)
{
    std::string  infixEquation  = "10--2";
    double       expectedResult = 12;

    auto result = calculator_.calculateResult(infixEquation);

    EXPECT_TRUE(result.isValid()) << "Result falied with message: \"" << result.getError() << "\"";
    EXPECT_DOUBLE_EQ(expectedResult, *result.consumeResult());
};