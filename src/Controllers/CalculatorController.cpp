#include "CalculatorController.h"

#include <string>

#include <pistache/router.h>
#include <pistache/http.h>

#include "CalculatorService.h"
#include "Result.h"



void CalculatorController::calculate(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res)
{
    std::string body = req.body();

    Result<std::string> result = CalculatorService::calculate(body);

    if (!result.isValid())
    {
        res.send(Pistache::Http::Code::Bad_Request, result.getError());
        return;
    }
    
    res.send(Pistache::Http::Code::Ok, result.getResult(), Pistache::Http::Mime::MediaType(Pistache::Http::Mime::Type::Text, Pistache::Http::Mime::Subtype::Plain));
    return;
};