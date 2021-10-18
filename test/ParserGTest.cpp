////////////////////////////////////////////////////////////////////////////////
/**
* @file ParserGTest.cpp
* @brief unit tests for the parser
*/
////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
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
};
void whenTestingParser::SetUp()
{
    parserInst = new Parser();
}
void whenTestingParser::TearDown()
{
    delete parserInst;
}

TEST_F(whenTestingParser, WhenBreakingDownEquationWithValidExpressionUnits_ThenTrueReturned)
{
    ExpressionUnit a;
    ExpressionUnit b;
    ExpressionUnit c;
    a.number = 1;
    a.valid = true;
    b.operation = '+';
    b.valid = true;
    c.number = 1;
    c.valid = true;

    std::vector<ExpressionUnit> sampleVector = {a, b, c};
    Expression sampleExpression = parserInst->breakDownEquation(sampleVector);
    
    ASSERT_TRUE(sampleExpression.validExpression); //1+1
}
TEST_F(whenTestingParser, WhenBreakingDownEquationWithNotValidExpressionUnits_ThenFalseReturned)
{
    ExpressionUnit a;
    ExpressionUnit b;
    ExpressionUnit c;
    a.number = 1;
    a.valid = true;
    b.operation = '?';
    b.valid = false;
    c.number = 1;
    c.valid = true;

    std::vector<ExpressionUnit> sampleVector = {a, b, c};
    Expression sampleExpression = parserInst->breakDownEquation(sampleVector);
    
    ASSERT_FALSE(sampleExpression.validExpression); //1?1
}
TEST_F(whenTestingParser, WhenBreakingDownEquationWithDivision_ThenDivisionExpressionReturnedFirst)
{
    ExpressionUnit a;
    ExpressionUnit b;
    ExpressionUnit c;
    ExpressionUnit d;
    ExpressionUnit e;
    a.number = 1;
    a.valid = true;
    b.operation = '+';
    b.valid = true;
    c.number = 1;
    c.valid = true;
    d.operation = '/';
    d.valid = true;
    e.operation = '5';
    e.valid = true;

    std::vector<ExpressionUnit> sampleVector = {a, b, c, d, e};
    Expression createdExpression = parserInst->breakDownEquation(sampleVector);
    char returnedExpressionOperator = '/';
    
    ASSERT_EQ(createdExpression.operation, returnedExpressionOperator); //1+1/5
}
TEST_F(whenTestingParser, WhenBreakingDownEquationWithMultiplication_ThenDivisionExpressionReturnedFirst)
{
    ExpressionUnit a;
    ExpressionUnit b;
    ExpressionUnit c;
    ExpressionUnit d;
    ExpressionUnit e;
    a.number = 1;
    a.valid = true;
    b.operation = '+';
    b.valid = true;
    c.number = 1;
    c.valid = true;
    d.operation = '*';
    d.valid = true;
    e.operation = '5';
    e.valid = true;

    std::vector<ExpressionUnit> sampleVector = {a, b, c, d, e};
    Expression createdExpression = parserInst->breakDownEquation(sampleVector);
    char returnedExpressionOperator = '*';
    
    ASSERT_EQ(createdExpression.operation, returnedExpressionOperator); //1+1*5
}
TEST_F(whenTestingParser, WhenBreakingDownEquationWithMultiplicationAndDivision_ThenFirstExpressionReturnedFirst)
{
    ExpressionUnit a;
    ExpressionUnit b;
    ExpressionUnit c;
    ExpressionUnit d;
    ExpressionUnit e;
    a.number = 1;
    a.valid = true;
    b.operation = '/';
    b.valid = true;
    c.number = 1;
    c.valid = true;
    d.operation = '*';
    d.valid = true;
    e.operation = '5';
    e.valid = true;

    std::vector<ExpressionUnit> sampleVector = {a, b, c, d, e};
    Expression createdExpression = parserInst->breakDownEquation(sampleVector);
    char returnedExpressionOperator = '/';
    
    ASSERT_EQ(createdExpression.operation, returnedExpressionOperator); //1/1*5
}

TEST_F(whenTestingParser, WhenCreatingVector_CorrectVectorReturned)
{
    ExpressionUnit a;
    ExpressionUnit b;
    ExpressionUnit c;
    ExpressionUnit d;
    ExpressionUnit e;
    
    a.number = 1;
    b.operation = '+';
    c.number = -2;
    d.operation = '/';
    e.number = 3.2;
    std::vector<ExpressionUnit> sampleVector = {a, b, c, d, e};

    std::pair <std::vector<ExpressionUnit>,bool> createdVector = parserInst->createVector("1+-2/3.2");

    ASSERT_EQ(sampleVector.at(0).number, createdVector.first.at(0).number);
    ASSERT_EQ(sampleVector.at(1).operation, createdVector.first.at(1).operation);
    ASSERT_EQ(sampleVector.at(2).number, createdVector.first.at(2).number);
    ASSERT_EQ(sampleVector.at(3).operation, createdVector.first.at(3).operation);
    ASSERT_EQ(sampleVector.at(4).number, createdVector.first.at(4).number);
}

TEST_F(whenTestingParser, WhenCreatingVectorWithParenthesis_CorrectVectorReturned)
{
    ExpressionUnit a;
    ExpressionUnit b;
    ExpressionUnit c;
    ExpressionUnit d;
    ExpressionUnit e;
    ExpressionUnit f;
    ExpressionUnit g;
    
    a.number = 1;
    b.operation = '+';
    c.operation = '(';
    d.number = -2;
    e.operation = '/';
    f.number = 3.2;
    g.operation = ')';
    std::vector<ExpressionUnit> sampleVector = {a, b, c, d, e, f, g};

    std::pair <std::vector<ExpressionUnit>,bool> createdVector = parserInst->createVector("1+(-2/3.2)");

    ASSERT_EQ(sampleVector.at(0).number, createdVector.first.at(0).number);
    ASSERT_EQ(sampleVector.at(1).operation, createdVector.first.at(1).operation);
    ASSERT_EQ(sampleVector.at(2).operation, createdVector.first.at(2).operation);
    ASSERT_EQ(sampleVector.at(3).number, createdVector.first.at(3).number);
    ASSERT_EQ(sampleVector.at(4).operation, createdVector.first.at(4).operation);
    ASSERT_EQ(sampleVector.at(5).number, createdVector.first.at(5).number);
    ASSERT_EQ(sampleVector.at(6).operation, createdVector.first.at(6).operation);
}

TEST_F(whenTestingParser, WhenCreatingVectorWithIncorrectParenthesis_InvalidVectorReturned)
{
    std::pair <std::vector<ExpressionUnit>,bool> createdVector = parserInst->createVector("(1)");

    ASSERT_FALSE(createdVector.second);
}


