#ifndef CONTROLLERS_CALCULATOR_CONTROLLER_H
#define CONTROLLERS_CALCULATOR_CONTROLLER_H

#include <pistache/router.h>
#include <pistache/http.h>

#include "Result.h"



class CalculatorController
{
    public:
        static void calculateYesHistory(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res);
        static void calculateNoHistory (const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res);
    
    private:
        CalculatorController() {};

        static Result<std::string> calculate(const Pistache::Rest::Request& req, bool saveHistory);
};

#endif