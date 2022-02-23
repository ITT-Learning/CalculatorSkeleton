#include "Symbol.h"

#include <cctype>
#include <stdexcept>
#include <functional>
#include <limits>

namespace calculator {

template<typename T>
Symbol<T>::Symbol(char symbol) : symbol_(tolower(symbol)), isBound_(false)
{
    if(!isalpha(symbol)) 
    {
        throw std::domain_error("given character was not a letter");
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
    return boundValue_;
}

template<typename T>
void Symbol<T>::bindFromStreams(std::istream& istream, std::ostream& ostream)
{
    do
    {
        ostream << symbol_ << " = ";
        if(istream >> boundValue_)
        {
            // good input, we can stop asking.
            break;
        }
        else
        {
            istream.clear();
            istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ostream << "Please enter a valid integer." << std::endl;
        }
    } while (true);
    isBound_ = true;
}

// Explicit template specialization needed since template is defined in .cpp 
// file now.
template class Symbol<int>;
template class Symbol<double>;

}