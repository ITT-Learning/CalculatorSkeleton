#ifndef ADDITION_H
#define ADDITION_H

#include "IMathOperation.h"

class Addition : public IMathOperation
{
    private:
        IMathOperation* lhs;
        IMathOperation* rhs;
    
    public:
        Addition(IMathOperation* p_lhs, IMathOperation* p_rhs);
        ~Addition();

        virtual double calculate();
};

#endif