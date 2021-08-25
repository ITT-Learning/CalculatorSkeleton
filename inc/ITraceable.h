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

#include <iostream>
#include <string>

namespace Calculator
{
    class ITraceable
    {
        protected:
            ITraceable(std::ostream &oStream = std::cout);
            ~ITraceable();
            void SetTrace(bool trace);
            void Trace(std::string message);
        private:
            std::ostream &ostream_;
            static bool trace_;
    };
}

#endif //ITRACEABLE_H