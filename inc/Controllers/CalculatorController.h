#ifndef CONTROLLERS_CALCULATOR_CONTROLLER_H
#define CONTROLLERS_CALCULATOR_CONTROLLER_H

#include <pistache/router.h>
#include <pistache/http.h>



class CalculatorController
{
    public:
        static void calculate(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res);
    
    private:
        CalculatorController() {};
};

#endif