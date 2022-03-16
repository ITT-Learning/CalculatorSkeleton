////////////////////////////////////////////////////////////////////////////
/**
 *  @file   mainGtest.cpp
 *  @date   Fri April 16 2021
 *
 */
////////////////////////////////////////////////////////////////////////////

#include <gtest/gtest.h>


/**
 * @brief Google test main function
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
   
    return RUN_ALL_TESTS();
}
