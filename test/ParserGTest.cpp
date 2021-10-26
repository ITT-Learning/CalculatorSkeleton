////////////////////////////////////////////////////////////////////////////////
/**
* @file ParserGTest.cpp
* @brief unit tests for the parser
*/
////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <utility>

#include "CalculatorMessages.h"
#include "Parser.h"

using namespace calculator;
using namespace testing;

class whenTestingParser:public ::testing::Test
{
    public:
        Parser* parserInst;
        virtual void SetUp() override;
        virtual void TearDown() override;

    protected:
        ExpressionUnit unit1;
        ExpressionUnit unit2;
        ExpressionUnit unit3;
        ExpressionUnit unit4;
        ExpressionUnit unit5;
        ExpressionUnit unit6;
        ExpressionUnit unit7;
};
void whenTestingParser::SetUp()
{
    parserInst = new Parser();
}
void whenTestingParser::TearDown()
{
    delete parserInst;
}

/**
* @brief Unit test for breaking down equation with valid expression units 
*/
TEST_F(whenTestingParser, WhenBreakingDownEquationWithValidExpressionUnits_ThenTrueReturned)
{
    unit1.number = 1;
    unit1.isValid = true;
    unit2.operation = CalculatorMessages::OPERATIONS[0];
    unit2.isValid = true;
    unit3.number = 1;
    unit3.isValid = true;

    auto sampleVector = std::make_shared<std::vector<ExpressionUnit>>();
    sampleVector->push_back(unit1);
    sampleVector->push_back(unit2);
    sampleVector->push_back(unit3);

    Expression sampleExpression = parserInst->breakDownEquation(sampleVector);
    
    EXPECT_TRUE(sampleExpression.isValidExpression); //1+1
}

/**
* @brief Unit test for breaking down equation with invalid expression units 
*/
TEST_F(whenTestingParser, WhenBreakingDownEquationWithNotValidExpressionUnits_ThenFalseReturned)
{
    unit1.number = 1;
    unit1.isValid = true;
    unit2.operation = '?';
    unit2.isValid = false;
    unit3.number = 1;
    unit3.isValid = true;

    auto sampleVector = std::make_shared<std::vector<ExpressionUnit>> ();
    sampleVector->push_back(unit1);
    sampleVector->push_back(unit2);
    sampleVector->push_back(unit3);
    Expression sampleExpression = parserInst->breakDownEquation(sampleVector);
    
    EXPECT_FALSE(sampleExpression.isValidExpression); //1?1
}

/**
* @brief Unit test for breaking down equation with priority division operator
*/
TEST_F(whenTestingParser, WhenBreakingDownEquationWithDivision_ThenDivisionExpressionReturnedFirst)
{
    unit1.number = 1;
    unit1.isValid = true;
    unit2.operation = CalculatorMessages::OPERATIONS[0];
    unit2.isValid = true;
    unit3.number = 1;
    unit3.isValid = true;
    unit4.operation = CalculatorMessages::OPERATIONS[2];
    unit4.isValid = true;
    unit5.number = 5;
    unit5.isValid = true;

    auto sampleVector = std::make_shared<std::vector<ExpressionUnit>> ();
    sampleVector->push_back(unit1);
    sampleVector->push_back(unit2);
    sampleVector->push_back(unit3);
    sampleVector->push_back(unit4);
    sampleVector->push_back(unit5);

    Expression createdExpression = parserInst->breakDownEquation(sampleVector);
    char returnedExpressionOperator = CalculatorMessages::OPERATIONS[2];
    
    EXPECT_EQ(returnedExpressionOperator, createdExpression.operation); //1+1/5
}

/**
* @brief Unit test for breaking down equation with priority multiplication operator
*/
TEST_F(whenTestingParser, WhenBreakingDownEquationWithMultiplication_ThenMultiplicationExpressionReturnedFirst)
{
    unit1.number = 1;
    unit1.isValid = true;
    unit2.operation = CalculatorMessages::OPERATIONS[1];
    unit2.isValid = true;
    unit3.number = 1;
    unit3.isValid = true;
    unit4.operation = CalculatorMessages::OPERATIONS[4];
    unit4.isValid = true;
    unit5.number = 5;
    unit5.isValid = true;

    auto sampleVector = std::make_shared<std::vector<ExpressionUnit>> ();

    sampleVector->push_back(unit1);
    sampleVector->push_back(unit2);
    sampleVector->push_back(unit3);
    sampleVector->push_back(unit4);
    sampleVector->push_back(unit5);

    Expression createdExpression = parserInst->breakDownEquation(sampleVector);
    char returnedExpressionOperator = CalculatorMessages::OPERATIONS[4];
    
    EXPECT_EQ(returnedExpressionOperator, createdExpression.operation); //1+1*5
}

/**
* @brief Unit test for breaking down equation with two priority operators
*/
TEST_F(whenTestingParser, WhenBreakingDownEquationWithMultiplicationAndDivision_ThenFirstExpressionReturnedFirst)
{
    unit1.number = 1;
    unit1.isValid = true;
    unit2.operation = CalculatorMessages::OPERATIONS[2];
    unit2.isValid = true;
    unit3.number = 1;
    unit3.isValid = true;
    unit4.operation = CalculatorMessages::OPERATIONS[4];
    unit4.isValid = true;
    unit5.number = 5;
    unit5.isValid = true;

    auto sampleVector = std::make_shared<std::vector<ExpressionUnit>> ();

    sampleVector->push_back(unit1);
    sampleVector->push_back(unit2);
    sampleVector->push_back(unit3);
    sampleVector->push_back(unit4);
    sampleVector->push_back(unit5);

    Expression createdExpression = parserInst->breakDownEquation(sampleVector);
    char returnedExpressionOperator = CalculatorMessages::OPERATIONS[2];
    
    EXPECT_EQ(returnedExpressionOperator, createdExpression.operation); //1/1*5
}

/**
* @brief Unit test for creating an expression unit vector
*/
TEST_F(whenTestingParser, WhenCreatingVector_CorrectVectorReturned)
{
    unit1.number = 1;
    unit2.operation = CalculatorMessages::OPERATIONS[0];
    unit3.number = -2;
    unit4.operation = CalculatorMessages::OPERATIONS[2];
    unit5.number = 3.2;

    auto sampleVector = std::make_shared<std::vector<ExpressionUnit>> ();
    std::pair <std::shared_ptr<std::vector<ExpressionUnit>>,bool> createdVector = parserInst->createVector("1+-2/3.2");

    sampleVector->push_back(unit1);
    sampleVector->push_back(unit2);
    sampleVector->push_back(unit3);
    sampleVector->push_back(unit4);
    sampleVector->push_back(unit5);

    EXPECT_EQ(sampleVector->at(0).number, createdVector.first->at(0).number);
    EXPECT_EQ(sampleVector->at(1).operation, createdVector.first->at(1).operation);
    EXPECT_EQ(sampleVector->at(2).number, createdVector.first->at(2).number);
    EXPECT_EQ(sampleVector->at(3).operation, createdVector.first->at(3).operation);
    EXPECT_EQ(sampleVector->at(4).number, createdVector.first->at(4).number);
}

/**
* @brief Unit test for creating an expression unit vector with parenthesis
*/
TEST_F(whenTestingParser, WhenCreatingVectorWithParenthesis_CorrectVectorReturned)
{
    unit1.number = 1;
    unit2.operation = CalculatorMessages::OPERATIONS[0];
    unit3.operation = CalculatorMessages::OPEN_PARENTHESIS;
    unit4.number = -2;
    unit5.operation = CalculatorMessages::OPERATIONS[2];
    unit6.number = 3.2;
    unit7.operation = CalculatorMessages::CLOSE_PARENTHESIS;

    auto sampleVector = std::make_shared<std::vector<ExpressionUnit>> ();

    sampleVector->push_back(unit1);
    sampleVector->push_back(unit2);
    sampleVector->push_back(unit3);
    sampleVector->push_back(unit4);
    sampleVector->push_back(unit5);
    sampleVector->push_back(unit6);
    sampleVector->push_back(unit7);

    std::pair <std::shared_ptr<std::vector<ExpressionUnit>>,bool> createdVector = parserInst->createVector("1+(-2/3.2)");

    EXPECT_EQ(sampleVector->at(0).number, createdVector.first->at(0).number);
    EXPECT_EQ(sampleVector->at(1).operation, createdVector.first->at(1).operation);
    EXPECT_EQ(sampleVector->at(2).operation, createdVector.first->at(2).operation);
    EXPECT_EQ(sampleVector->at(3).number, createdVector.first->at(3).number);
    EXPECT_EQ(sampleVector->at(4).operation, createdVector.first->at(4).operation);
    EXPECT_EQ(sampleVector->at(5).number, createdVector.first->at(5).number);
    EXPECT_EQ(sampleVector->at(6).operation, createdVector.first->at(6).operation);
}

/**
* @brief Unit test for creating an invalid expression unit
*/
TEST_F(whenTestingParser, WhenBreakingDownEquationWithInvalidExpression_ValidExpressionIsFalse)
{
    unit1.operation = CalculatorMessages::OPEN_PARENTHESIS;
    unit1.isValid = true;
    unit2.number = 1;
    unit2.isValid = true;
    unit3.operation = CalculatorMessages::CLOSE_PARENTHESIS;
    unit3.isValid = true;

    auto sampleVector = std::make_shared<std::vector<ExpressionUnit>> ();
    sampleVector->push_back(unit1);
    sampleVector->push_back(unit2);
    sampleVector->push_back(unit3);
    Expression createdExpression = parserInst->breakDownEquation(sampleVector);
    
    EXPECT_FALSE(createdExpression.isValidExpression); //(1)
}
