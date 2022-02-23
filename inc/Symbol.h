#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>

namespace Calculator {

/**
 * @brief Represents a symbol in a mathematical expression. Symbols have a single associated glyph from a-z 
 * and can optionally have a value bound to them.
 * 
 */
template<typename T>
class Symbol
{
private:
    const char symbol_;
    bool isBound_;
    T boundValue_;
public:
    Symbol(void) = delete;
    Symbol(char symbol);

    bool hasValue(void);
    void setValue(T valueToBind);
    T getValue(void);
    void bindFromStdIO(void);
};

}

#endif // #ifndef SYMBOL_H