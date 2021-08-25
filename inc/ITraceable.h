/**
 * @file ITraceable.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ITRACEABLE_H
#define ITRACEABLE_H

#include <string>

namespace Calculator
{
    class ITraceable
    {
        protected:
            ITraceable();
            ~ITraceable();
            void SetTrace(bool trace);
            void Trace(std::string message);
        private:
            static bool trace_;
    };
}

#endif //ITRACEABLE_H