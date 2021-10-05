////////////////////////////////////////////////////////////////////////////////
/**
* @file ParserGTest.cpp
* @brief unit tests for the parser
*/
////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

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

TEST_F(whenTestingParser, WhenValidatingTwoPositiveIntegers_ThenTrueReturned)
{
    ASSERT_TRUE(parserInst->parseFullEquation("1+1").valid);
}
TEST_F(whenTestingParser, WhenValidatingIncorrectOperation_ThenFalseReturned)
{
    ASSERT_FALSE(parserInst->parseFullEquation("1?1").valid);
}
TEST_F(whenTestingParser, WhenValidatingTwoNegativeIntegers_ThenTrueReturned)
{
    ASSERT_TRUE(parserInst->parseFullEquation("-1+-1").valid);
}
TEST_F(whenTestingParser, WhenValidatingTwoPositiveFloats_ThenTrueReturned)
{
    ASSERT_TRUE(parserInst->parseFullEquation("1.55*30.43").valid);
}
TEST_F(whenTestingParser, WhenValidatingTwoNegativeFloats_ThenTrueReturned)
{
    ASSERT_TRUE(parserInst->parseFullEquation("-44.34--0.43").valid);
}
TEST_F(whenTestingParser, WhenValidatingANonNumber_ThenFalseReturned)
{
    ASSERT_FALSE(parserInst->parseFullEquation("-b/15").valid);
}
TEST_F(whenTestingParser, WhenValidatingNonNumbersInFrontOfNumbers_ThenFalseReturned)
{
    ASSERT_FALSE(parserInst->parseFullEquation("abc123*xyz123").valid);
}


