#ifndef CONSOLEIO_H
#define CONSOLEIO_H

#include <memory>
#include <string>

#include "IExpression.h"

namespace calculator {

template<typename T>
class ConsoleIo
{
public:
    static bool handleInput();
private:
    static void handleNonQuittingInput(const std::string &input);
    static void bindSymbols(std::unique_ptr<calculator::expression::IExpression<T>> &inputExpression);
};

}

#endif