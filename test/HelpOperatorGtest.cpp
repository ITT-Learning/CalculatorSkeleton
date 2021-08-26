/**
 * @file HelpOperatorGtest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../inc/HelpOperator.h"

using namespace Calculator;

TEST(Week3HelpOperatorTests, HelpOperatorIsImplementableAsABaseClass)
{
    HelpOperator ho;
    EXPECT_EQ(ho.help(), "TBD");
}