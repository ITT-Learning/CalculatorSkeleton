/**
 * @file IHelper.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef IHELPER_H
#define IHELPER_H

#include <string>

namespace Calculator
{
    class IHelper
    {
        public:
            virtual const std::string help() = 0;
    };
}

#endif //IHELPER_H