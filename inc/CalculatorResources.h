/**
 * @file CalculatorResources.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CALCULATORRESOURCES_H
#define CALCULATORRESOURCES_H

#include <map>
#include <vector>

namespace Calculator
{
    enum OPORDER { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX };

    const std::vector<OPORDER> OPORDERS{
        OPORDER::ZERO,
        OPORDER::ONE,
        OPORDER::TWO,
        OPORDER::THREE,
        OPORDER::FOUR,
        OPORDER::FIVE,
        OPORDER::SIX
    };

    struct OpSymbol {
            std::string Id;
            std::string Regex;
            OPORDER Order;
    };

    const std::map<std::string, OpSymbol> OpSymbols = {
        {"(",   OpSymbol {"("   , "\\(",    OPORDER::ONE}},
        {"abs", OpSymbol {"abs" , "abs",    OPORDER::TWO}},
        {"^",   OpSymbol {"^"   , "\\^",    OPORDER::THREE}},
        {"*",   OpSymbol {"*"   , "\\*",    OPORDER::FOUR}},
        {"/",   OpSymbol {"/"   , "/",      OPORDER::FOUR}},
        {"+",   OpSymbol {"+"   , "\\+",    OPORDER::FIVE }},
        {"-",   OpSymbol {"-"   , "-",      OPORDER::FIVE}}
    };
}

#endif //CALCULATORRESOURCES_H