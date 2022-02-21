#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>

namespace Calculator {

/**
 * @brief Represents a symbol in a mathematical expression. Symbols can be any single character from a-z.
 * 
 */
template<typename T>
class Symbol {
public:
    const char symbol;
private:
    bool is_bound;
    T bound_value;
public:
    Symbol() = delete;

    Symbol(char c) : symbol(tolower(c)), is_bound(false) {
        if(!isalpha(c)) throw new std::domain_error("given character was not a letter");
    }

    bool hasValue() {
        return this->is_bound;
    }

    void setValue(T value_to_bind) {
        this->is_bound = true;
        this->bound_value = value_to_bind;
    }

    T getValue() { return this->bound_value; }

    void bindFromStdIO(void) {
        std::cout << symbol << " = ";
        this->is_bound = true;
        std::cin >> this->bound_value;
    }
};

}

#endif // #ifndef SYMBOL_H