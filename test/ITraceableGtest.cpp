/**
 * @file ITraceableGtest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include "../inc/ITraceable.h"

using namespace Calculator;

TEST(Week3ITraceableTests, ITraceableImplementableAsABaseClass)
{
    std::ostringstream oss;

    class TestClass : ITraceable
    {
        public:
            TestClass(std::ostringstream &os) : ITraceable(os) {}
            ~TestClass() {}
            void Test(std::string in) { Trace("test(" + in + ")"); }
            void PublicSetTrace(bool t) { SetTrace(t); }
    };

    TestClass tc(oss);

    tc.Test("msg1 default no trace");
    std::string Expected = "";
    EXPECT_EQ(oss.str(), Expected);

    tc.PublicSetTrace(true);
    tc.Test("msg2 traced!");
    Expected = "   test(msg2 traced!)\n";
    EXPECT_EQ(oss.str(), Expected);

    oss.str("");
    oss.clear();

    tc.PublicSetTrace(false);
    tc.Test("msg3 no trace");
    Expected = "";
    EXPECT_EQ(oss.str(), Expected);
}