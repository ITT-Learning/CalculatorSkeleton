#ifndef RESULT_H
#define RESULT_H

#include <string>

template <typename T>
class Result
{
    public:
        inline  T            getResult()        { return result_; }        const;
        inline  bool         isValid()          { return isValid_; }       const;
        inline  std::string  getErrorMessage()  { return errorMessage_; }  const;

        Result(T result, bool isValid = true, std::string errorMessage = "")
            : result_{result}, isValid_{isValid}, errorMessage_{errorMessage}
            {};

    private:
        T            result_;
        bool         isValid_;
        std::string  errorMessage_;
};

#endif