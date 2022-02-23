#include "Symbol.h"

#include <cctype>
#include <stdexcept>

namespace calculator {

template<typename T>
Symbol<T>::Symbol(char symbol) : symbol(tolower(symbol)), is_bound(false)
{
    if(!isalpha(symbol)) 
    {
        throw new std::domain_error("given character was not a letter");
    }
}

template<typename T>
bool Symbol<T>::hasValue()
{
    return isBound_;
}

template<typename T>
void Symbol<T>::setValue(T valueToBind)
{
    isBound_ = true;
    boundValue_ = valueToBind;
}

template<typename T>
T Symbol<T>::getValue()
{
    if(!isBound_) throw new std::exception("attempted to get the value of a "
            "symbol with no bound value");
    return boundValue_;
}

template<typename T>
void Symbol<T>::bindFromStdIO()
{
    std::cout << symbol_ << " = ";
    isBound_ = true;
    std::cin >> boundValue_;
}

// Explicit template specialization needed since template is defined in .cpp 
// file now.
template class Symbol<int>;
template class Symbol<double>;

}