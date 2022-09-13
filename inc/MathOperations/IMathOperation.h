#ifndef I_MATH_OPERATION_H
#define I_MATH_OPERATION_H

/*******************************************************************************
*
* Interface for a math operation
*
* ——————————————————————————————————————————————————————————————————————————————
*
* double calulate() — return the result
*
*******************************************************************************/
class IMathOperation
{
    public:
        virtual double calculate() = 0;
};

#endif