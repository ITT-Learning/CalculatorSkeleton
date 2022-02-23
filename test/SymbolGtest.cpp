////////////////////////////////////////////////////////////////////////////
/**
 *  @file   SymbolGtest.cpp
 *  @date   Wed February 23 2022
 *  @brief  Unit test suite for the Sample class
 */
////////////////////////////////////////////////////////////////////////////

#include <limits>
#include <sstream>

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "../inc/Symbol.h"

using namespace testing;

class SymbolFixture: public ::testing::Test
{
    protected:
        calculator::Symbol<int> intSymbolA;
        calculator::Symbol<int> intSymbolBBound;
        calculator::Symbol<int> intSymbolCBound;
        calculator::Symbol<int> intSymbolDBound;
        calculator::Symbol<int> intSymbolEBound;
        calculator::Symbol<int> intSymbolFBound;
        calculator::Symbol<int> intSymbolZ;
        
        calculator::Symbol<double> doubleSymbolA;
        calculator::Symbol<double> doubleSymbolBBound;
        calculator::Symbol<double> doubleSymbolCBound;
        calculator::Symbol<double> doubleSymbolDBound;
        calculator::Symbol<double> doubleSymbolEBound;
        calculator::Symbol<double> doubleSymbolFBound;
        calculator::Symbol<double> doubleSymbolZ;

        SymbolFixture(): 
                intSymbolA{'a'},
                intSymbolBBound{'B'}, 
                intSymbolCBound{'c'},
                intSymbolDBound{'d'},
                intSymbolEBound{'e'},
                intSymbolFBound{'f'},
                intSymbolZ{'Z'},
                doubleSymbolA{'A'},
                doubleSymbolBBound{'b'},
                doubleSymbolCBound{'C'},
                doubleSymbolDBound{'d'},
                doubleSymbolEBound{'e'},
                doubleSymbolFBound{'f'},
                doubleSymbolZ{'z'}
        {
            intSymbolBBound.setValue(-12);
            intSymbolCBound.setValue(0);
            intSymbolDBound.setValue(42);
            intSymbolEBound.setValue(std::numeric_limits<int>::max());
            intSymbolFBound.setValue(std::numeric_limits<int>::min());

            doubleSymbolBBound.setValue(-123.45);
            doubleSymbolCBound.setValue(0.0);
            doubleSymbolDBound.setValue(42.42e10);
            doubleSymbolEBound.setValue(std::numeric_limits<double>::max());
            doubleSymbolFBound.setValue(std::numeric_limits<double>::min());
        }
};
TEST_F(SymbolFixture, hasValue)
{
    EXPECT_FALSE(intSymbolA.hasValue());
    EXPECT_TRUE(intSymbolBBound.hasValue());
    EXPECT_FALSE(doubleSymbolA.hasValue());
    EXPECT_TRUE(doubleSymbolBBound.hasValue());
}
TEST_F(SymbolFixture, setValueAndGetValue)
{
    // In practice, setValue is tested for the most part in the test fixture's 
    // constructor.
    // We allow re-setting the value if the symbol already has a bound value, so
    // this shouldn't conflict with the fixture's constructor at all.
    intSymbolDBound.setValue(41);
    EXPECT_EQ(intSymbolDBound.getValue(), 41);
    doubleSymbolDBound.setValue(41.42e10);
    EXPECT_EQ(doubleSymbolDBound.getValue(), 41.42e10);
    EXPECT_EQ(intSymbolA.getValue(), calculator::Symbol<int>::defaultValue());
    EXPECT_EQ(doubleSymbolZ.getValue(),
            calculator::Symbol<double>::defaultValue());
}

TEST_F(SymbolFixture, bindFromStreams)
{
    std::stringstream inStream;
    std::stringstream outStream;
    inStream << 43 << std::endl;
    intSymbolDBound.bindFromStreams(inStream, outStream);
    EXPECT_EQ(intSymbolDBound.getValue(), 43);
    EXPECT_EQ(outStream.str(),
            std::string{intSymbolDBound.getSymbol()} + " = ");
    
    inStream.str(std::string{});
    outStream.str(std::string{});
    inStream << 43.43e10 << std::endl;
    doubleSymbolDBound.bindFromStreams(inStream, outStream);
    EXPECT_EQ(intSymbolDBound.getValue(), 43.43e10);
    EXPECT_EQ(outStream.str(),
            std::string{intSymbolDBound.getSymbol()} + " = ");
}
