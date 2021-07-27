/**
 * @file tokenizerW2Gtest.cpp
 * @author Gary Dean Jenkins (gary.jenkins@intimetec.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/CalculatorStrings.h"
#include "../inc/TokenizerW2.h"

using namespace calculatorw2;

TEST(WeekTwoTokenizerW2Tests, WhenValidMathExpressionStringsAreProvidedThenTheTokenizerReturnsValidLeftRightAndOperatorValues)
{
    double a, b;
    char op;

    TokenizerW2 tokenizer1("1 + 2");
    tokenizer1.getMathExpression(a, b, op);
    EXPECT_DOUBLE_EQ(a, 1);
    EXPECT_DOUBLE_EQ(b, 2);
    EXPECT_EQ(op, '+');
    EXPECT_EQ((Operators)op, Operators::ADD);

    TokenizerW2 tokenizer2("3 - 0");
    tokenizer2.getMathExpression(a, b, op);
    EXPECT_DOUBLE_EQ(a, 3);
    EXPECT_DOUBLE_EQ(b, 0);
    EXPECT_EQ(op, '-');
    EXPECT_EQ((Operators)op, Operators::SUBTRACT);

    TokenizerW2 tokenizer3("-2 * .1");
    tokenizer3.getMathExpression(a, b, op);
    EXPECT_DOUBLE_EQ(a, -2);
    EXPECT_DOUBLE_EQ(b, .1);
    EXPECT_EQ(op, '*');
    EXPECT_EQ((Operators)op, Operators::MULTIPLY);

    TokenizerW2 tokenizer4("3.333 / -3");
    tokenizer4.getMathExpression(a, b, op);
    EXPECT_DOUBLE_EQ(a, 3.333);
    EXPECT_DOUBLE_EQ(b, -3);
    EXPECT_EQ(op, '/');
    EXPECT_EQ((Operators)op, Operators::DIVIDE);
}

TEST(WeekTwoTokenizerW2Tests, WhenValidOperationStringsAreGivenThenTheTokenizerSetsCorrectOperatorAndExtendedInformation)
{
    char op;
    std::string extendedInformation;

    TokenizerW2 tokenizer1("q");
    tokenizer1.getControlExpression(op, extendedInformation);
    EXPECT_EQ(op, 'q');
    EXPECT_EQ(extendedInformation, "");
    EXPECT_EQ((Operators)op, Operators::QUIT);

    TokenizerW2 tokenizer2("h additional help information!");
    tokenizer2.getControlExpression(op, extendedInformation);
    EXPECT_EQ(op, 'h');
    EXPECT_EQ(extendedInformation, "additional help information!");
    EXPECT_EQ((Operators)op, Operators::HELP);
}

TEST(WeekTwoTokenizerW2Tests, WhenGivenACorrectQuitSTringTheTokenizerSetsTheCorrectOperationAndExtendedValue)
{
    char op;
    std::string extendedInformation;
    
    TokenizerW2 tokenizer1("q do we get a quit?");
    tokenizer1.getControlExpression(op, extendedInformation);
    EXPECT_EQ(op, 'q');
    EXPECT_EQ(extendedInformation, "do we get a quit?");
    EXPECT_EQ((Operators)op, Operators::QUIT);
}