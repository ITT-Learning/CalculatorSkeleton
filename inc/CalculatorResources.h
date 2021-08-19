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
}

#endif //CALCULATORRESOURCES_H