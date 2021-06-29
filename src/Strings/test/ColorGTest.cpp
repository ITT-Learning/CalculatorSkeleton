////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ColorGTest.cpp
 *  @date   Fri, June 25 2021
 *  @brief  Tests for Color string decorator
 */
////////////////////////////////////////////////////////////////////////////

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Color.h"

using namespace testing;

namespace calculator
{
    /**
     * @brief This is hard to test accurately since ANSI codes can be configured in a couple way.
     *        We could test the specific codes, but \033[1;94m and \033[1m\033[94m are both valid ways to make something blue and bold
     */
    class ColorTests : public ::testing::Test
    {
        protected:
            std::string            endEscape       = "m";
            std::string            escapeSequence  = "\033[";
            std::string::size_type notFound        = std::string::npos;
            std::string            reset           = "\033[0m";
            std::string            test            = "Hello Tests";
            std::string            unalteredString = "Hello Tests";
    };

    /**
     * @brief test for error decorator to make sure it is red and bold
     */
    TEST_F(ColorTests, WhenErrorIsCalledThenStringRedAndBoldAndReset)
    {
        std::string red = "31";
        std::string bold = "1";

        std::string result = Color::error(test);

        //test to make sure test is mutated as well
        EXPECT_EQ(result, test);

        //make sure string is reset
        std::string expectedEnd = result.substr(result.length() - reset.length());
        ASSERT_EQ(expectedEnd, reset);

        //remove reset bit so we can make sure other escape characters are kept
        result = result.substr(0, result.length() - reset.length());

        EXPECT_NE(result.find(escapeSequence), notFound);
        EXPECT_NE(result.find(endEscape), notFound);
        EXPECT_NE(result.find(unalteredString), notFound);
        EXPECT_NE(result.find(red), notFound);
        EXPECT_NE(result.find(bold), notFound);
    }

    /**
     * @brief test for info decorator to make sure it is blue and italic
     */
    TEST_F(ColorTests, WhenInfoIsCalledThenStringBlueAndItalicAndReset)
    {
        std::string blue = "94";
        std::string italics = "3";

        std::string result = Color::info(test);

        //test to make sure test is mutated as well
        EXPECT_EQ(result, test);

        //make sure string is reset
        std::string expectedEnd = result.substr(result.length() - reset.length());
        ASSERT_EQ(expectedEnd, reset);

        //remove reset bit so we can make sure other escape characters are kept
        result = result.substr(0, result.length() - reset.length());

        EXPECT_NE(result.find(escapeSequence), notFound);
        EXPECT_NE(result.find(endEscape), notFound);
        EXPECT_NE(result.find(unalteredString), notFound);
        EXPECT_NE(result.find(blue), notFound);
        EXPECT_NE(result.find(italics), notFound);
    }

    /**
     * @brief test for message decorator to make sure it is green
     */
    TEST_F(ColorTests, WhenMessageIsCalledThenStringGreenAndReset)
    {
        std::string green = "92";

        std::string result = Color::message(test);

        //test to make sure test is mutated as well
        EXPECT_EQ(result, test);

        //make sure string is reset
        std::string expectedEnd = result.substr(result.length() - reset.length());
        ASSERT_EQ(expectedEnd, reset);

        //remove reset bit so we can make sure other escape characters are kept
        result = result.substr(0, result.length() - reset.length());

        EXPECT_NE(result.find(escapeSequence), notFound);
        EXPECT_NE(result.find(endEscape), notFound);
        EXPECT_NE(result.find(unalteredString), notFound);
        EXPECT_NE(result.find(green), notFound);
    }

    /**
     * @brief test for sub decorator to make sure it is gray and faint
     */
    TEST_F(ColorTests, WhenSubIsCalledThenStringGrayAndFaintAndReset)
    {
        std::string faint = "2";
        std::string gray = "90";

        std::string result = Color::sub(test);

        //test to make sure test is mutated as well
        EXPECT_EQ(result, test);

        //make sure string is reset
        std::string expectedEnd = result.substr(result.length() - reset.length());
        ASSERT_EQ(expectedEnd, reset);

        //remove reset bit so we can make sure other escape characters are kept
        result = result.substr(0, result.length() - reset.length());

        EXPECT_NE(result.find(escapeSequence), notFound);
        EXPECT_NE(result.find(endEscape), notFound);
        EXPECT_NE(result.find(unalteredString), notFound);
        EXPECT_NE(result.find(faint), notFound);
        EXPECT_NE(result.find(gray), notFound);
    }
}