#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>

namespace calculator {

/**
 * @brief Represents a symbol in a mathematical expression. Symbols have a single associated glyph from a-z 
 * and can optionally have a value bound to them.
 * 
 */
template<typename T>
class Symbol
{
public:
    Symbol() = delete;
    Symbol(char symbol);

    bool hasValue();
    void setValue(T valueToBind);
    T getValue();
    void bindFromStreams(std::istream& istream, std::ostream& ostream);
private:
    const char symbol_;
    bool isBound_;
    T boundValue_;
};

}

#endif // #ifndef SYMBOL_H