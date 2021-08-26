/**
 * @file OperatorFactoryGtest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

#include "../inc/OperatorFactory.h"

using namespace Calculator;

TEST(Week3OperatorFactoryTests, OperatorFactorIsProperlyInstanciated)
{
    OperatorFactory *opfact = OperatorFactory::GetInstance();

    EXPECT_TRUE(opfact != nullptr);

    EXPECT_EQ(opfact->GetOperator("+")->GetOpSymbol().Id(), "+");
    EXPECT_EQ(opfact->GetOperator("-")->GetOpSymbol().Id(), "-");
    EXPECT_EQ(opfact->GetOperator("*")->GetOpSymbol().Id(), "*");
    EXPECT_EQ(opfact->GetOperator("/")->GetOpSymbol().Id(), "/");
    EXPECT_EQ(opfact->GetOperator("^")->GetOpSymbol().Id(), "^");
    EXPECT_EQ(opfact->GetOperator("inv")->GetOpSymbol().Id(), "inv");
    EXPECT_EQ(opfact->GetOperator("abs")->GetOpSymbol().Id(), "abs");
    EXPECT_EQ(opfact->GetOperator("sqrt")->GetOpSymbol().Id(), "sqrt");

    std::string s = "";
    for (OPORDER order : opfact->GetOpOrders())
    {
        std::vector<std::string> *v = opfact->GetOperatorListByOpOrder(order);
        std::for_each(v->begin(), v->end(), [&](const std::string &piece){ s += piece; });
    }
    
    EXPECT_EQ(s, "evalhelp(tronabs^invsqrt/*+-troff");
}