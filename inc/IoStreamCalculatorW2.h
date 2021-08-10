/**
 * @file IoStreamCalculatorW2.h
 * @author Gary Dean Jenkins (gary.jenkins@intimetec.com)
 * @brief Implements an iostream (istream and ostream) based calculator. Input parsing is
 *          accomplished using the TokenizerW2 class, and arithmetic is performed using the
 *          CalculatorW2 class.
 * @note Communication of error conditions is through the error_ property.
 *          Any non-nullptr value is considered an error.
 * @version 0.1
 * @date 2021-07-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef IOSTREAMCALCULATORW2_H
#define IOSTREAMCALCULATORW2_H

#include <iostream>

#include "CalculatorW2.h"
#include "TokenizerW2.h"

namespace calculatorw2
{
    class IoStreamCalculatorW2
    {
        public:

            /**
             * @brief Construct a new Io Stream Calculator W 2 object
             * 
             * @param IN,OUT inputStream 
             * @param IN,OUT outputStream 
             */
            IoStreamCalculatorW2(std::istream &inputStream = std::cin, std::ostream &outputStream = std::cout);

            /**
             * @brief Destroy the Io Stream Calculator W 2 object
             * 
             */
            ~IoStreamCalculatorW2();
            
            /**
             * @brief Print Hello and Help information to the commandline
             * 
             */
            void OutputHelloAndHelp();

            /**
             * @brief Callable by main, and implements the logic to parse input, display output, and
             *          perform control commands (QUIT).
             * 
             */
            void Run();

        private:

            CalculatorW2 calculatorW2_;

            const char* error_;

            std::istream& inputStream_;

            std::ostream& outputStream_;

    };
}

#endif //IOSTREAMCALCULATORW2_H