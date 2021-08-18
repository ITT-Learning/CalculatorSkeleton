////////////////////////////////////////////////////////////////////////////
/**
 *  @file   sampleClassGtest.cpp
 *  @date   Fri April 16 2021
 *  @brief  Sample Unit Test Class
 */
////////////////////////////////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace testing;

class whenTestingMain: public ::testing::Test{};
TEST_F(whenTestingMain, sampleUnitTest){
    ASSERT_FALSE(false);
}
