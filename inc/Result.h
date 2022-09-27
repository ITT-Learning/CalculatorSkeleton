#ifndef RESULT_H
#define RESULT_H

#include <string>
#include <memory>

template <typename T>
class Result
{
    public:
        Result()
        : isValid_(false), errorMessage_("No value given") {};
        
        // REVIEW could this just be a rvr: T&&
        Result(std::unique_ptr<T>&& result, bool isValid = true, std::string errorMessage = "")
        : result_(std::move(result)), isValid_{isValid}, errorMessage_{errorMessage} {};

        std::unique_ptr<T> consumeResult();

        inline  bool         isValid()   const  { return isValid_; };
        inline  std::string  getError()  const  { return errorMessage_; };

    private:
        std::unique_ptr<T>  result_;
        bool                isValid_;
        std::string         errorMessage_;
};



template <typename T>
std::unique_ptr<T> Result<T>::consumeResult()
{
    isValid_ = false;
    errorMessage_ = "Result has been consumed";
    return std::unique_ptr<T>(std::move(result_));
};

#endif