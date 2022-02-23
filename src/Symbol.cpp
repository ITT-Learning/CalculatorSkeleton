#include "Symbol.h"

#include <cctype>
#include <stdexcept>
#include <functional>
#include <limits>

namespace calculator {



template<typename T>
Symbol<T>::Symbol(char symbol): symbol_{tolower(symbol)}, isBound_{false},
        boundValue_{defaultValue()}
{
    if(!isalpha(symbol)) 
    {
        throw std::domain_error("given character was not a letter");
    }
}



template<typename T>
char Symbol<T>::getSymbol()
{
    return symbol_;
}



template<typename T>
bool Symbol<T>::hasValue() const
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
T Symbol<T>::getValue() const
{
    return boundValue_;
}



template<typename T>
void Symbol<T>::bindFromStreams(std::istream &istream, std::ostream &ostream)
{
    bool goodInput{false};
    while(!goodInput)
    {
        ostream << symbol_ << " = ";
        if(istream >> boundValue_)
        {
            // good input, we can stop asking.
            goodInput = true;
        }
        else
        {
            istream.clear();
            istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ostream << "Please enter a valid integer." << std::endl;
        }
    }
    isBound_ = true;
}



// Explicit template specialization needed since template is defined in .cpp 
// file now.
template class Symbol<int>;
template<>
int Symbol<int>::defaultValue()
{
    // Exceptions are discouraged, but we ideally shouldn't ever use a variable 
    // that hasn't had a value bound to it, so let's use an unusual value that 
    // will cause an obviously wrong result.
    return std::numeric_limits<int>::min();
}

template class Symbol<double>;
template<>
double Symbol<double>::defaultValue()
{
    // Exceptions are discouraged, but we ideally shouldn't ever use a variable 
    // that hasn't had a value bound to it, so let's use an unusual value that 
    // will cause an obviously wrong result.
    return std::numeric_limits<double>::min();
}

}