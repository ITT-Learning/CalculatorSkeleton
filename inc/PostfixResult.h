#ifndef POSTFIX_RESULT_H
#define POSTFIX_RESULT_H

#include <stack>
#include <string>

struct PostfixResult
{
    public:
        PostfixResult(std::stack<std::string> resultStack, bool isValid = true, std::string errorString = "")
        : resultStack_{resultStack}, isValid_{isValid}, errorString_{errorString} {};

        std::stack<std::string> resultStack_;
        bool isValid_;
        std::string errorString_;
};

#endif