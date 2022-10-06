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
        
        Result(T&& result, bool isValid = true, std::string errorMessage = "")
        : result_(std::move(result)), isValid_{isValid}, errorMessage_{errorMessage} {};

        inline T& getResult() { return result_; };

        inline  bool         isValid()   const  { return isValid_; };
        inline  std::string  getError()  const  { return errorMessage_; };

    private:
        T           result_;
        bool        isValid_;
        std::string errorMessage_;
};

#endif