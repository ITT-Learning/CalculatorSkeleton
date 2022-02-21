////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

#include "Symbol.h"

int main() 
{
    using namespace std;
    using namespace Calculator;
    // Fill in or change code here as necessary.  See also Calculator.cpp
    cout << "Welcome to the Calculator C++ learning project." << endl;
    vector<Symbol<int>> symbols { Symbol<int>{'a'}, Symbol<int>{'b'} };

    for(Symbol<int>& s : symbols) {
        s.bindFromStdIO();
    }
    cout << symbols[0].getValue() << " + " << symbols[1].getValue() << " = " << symbols[0].getValue() + symbols[1].getValue() << endl;
    cout << symbols[0].getValue() << " * " << symbols[1].getValue() << " = " << symbols[0].getValue() * symbols[1].getValue() << endl;
    cout << symbols[0].getValue() << " / " << symbols[1].getValue() << " = " << symbols[0].getValue() / symbols[1].getValue() << endl;
    cout << symbols[0].getValue() << " % " << symbols[1].getValue() << " = " << symbols[0].getValue() % symbols[1].getValue() << endl;

    return 0;
}