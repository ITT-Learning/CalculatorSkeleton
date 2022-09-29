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
        virtual int    getDepth()  = 0;

        virtual ~IMathOperation() {};

    protected:
        static const int THREADING_THRESHOLD = 50;
};

#endif