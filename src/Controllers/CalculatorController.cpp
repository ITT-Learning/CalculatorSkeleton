#include "CalculatorController.h"

#include <string>
#include <unordered_map>
#include <iostream>

#include <pistache/router.h>
#include <pistache/http.h>
#include <flatbuffers/flatbuffers.h>
#include <flatbuffers/idl.h>
#include <flatbuffers/util.h>

#include "CalculatorService.h"
#include "Result.h"
#include "HistoryService.h"
#include "CalcHistoryPair.h"
#include "Equation_generated.h"



static void sendError(Pistache::Http::ResponseWriter& res, std::string message)
{
    res.send(Pistache::Http::Code::Bad_Request,
                 message.c_str(),
                 Pistache::Http::Mime::MediaType(
                     Pistache::Http::Mime::Type::Text,
                     Pistache::Http::Mime::Subtype::Plain));
    return;
};



void CalculatorController::calculateYesHistory(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res)
{
    res.headers().add<Pistache::Http::Header::AccessControlAllowOrigin>("http://localhost:3000");
    auto result = calculate(req, true);
    if (!result.isValid())
    {
        sendError(res, result.getError());
        return;
    }

    res.send(Pistache::Http::Code::Ok, result.getResult(), Pistache::Http::Mime::MediaType(
                                                               Pistache::Http::Mime::Type::Text,
                                                               Pistache::Http::Mime::Subtype::Plain));
    return;
};



void CalculatorController::calculateNoHistory(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res)
{
    res.headers().add<Pistache::Http::Header::AccessControlAllowOrigin>("http://localhost:3000");
    auto result = calculate(req, false);
    if (!result.isValid())
    {
        sendError(res, result.getError());
        return;
    }

    res.send(Pistache::Http::Code::Ok, result.getResult(), Pistache::Http::Mime::MediaType(
                                                               Pistache::Http::Mime::Type::Text,
                                                               Pistache::Http::Mime::Subtype::Plain));
    return;
};



Result<std::string> CalculatorController::calculate(const Pistache::Rest::Request& req, bool saveHistory)
{
    std::string equationSchema;
    bool schemaLoaded = flatbuffers::LoadFile("./flatbuffers/Equation.fbs", false, &equationSchema);
    if (!schemaLoaded)
    {
        return Result<std::string>("", false, "Unable to initialize parsing");
    }

    flatbuffers::Parser parser;
    bool schemaParsed = parser.Parse(equationSchema.c_str());
    if (!schemaParsed)
    {
        return Result<std::string>("", false, "Unable to initialize equation parsing");
    }
    bool jsonParsed = parser.Parse(req.body().c_str());
    if (!jsonParsed)
    {
        return Result<std::string>("", false, parser.error_);
    }

    uint8_t *bufferPointer  = parser.builder_.GetBufferPointer();
    auto     equationBuffer = GetEquation(bufferPointer);

    std::string equationString  = equationBuffer->equation()->str();
    auto        variablesVector = equationBuffer->variables();

    std::unordered_map<std::string, double> variables;
    if (variablesVector != NULL)
    {
        int variablesCount = variablesVector->size();
        for (int i = 0; i < variablesCount; i++)
        {
            auto        variable      = variablesVector->Get(i);
            if(!variable->value().has_value())
            {
                continue;
            }
            double      variableValue = *(variable->value());
            std::string variableName  = variable->name()->str();

            variables.erase  (variableName);
            variables.emplace(variableName, variableValue);
        }
    }

    Result<std::string> result = CalculatorService::calculate(equationString, variables);

    if (!result.isValid())
    {
        return Result<std::string>("", false, result.getError());
    }

    if (saveHistory)
    {

        CalcHistoryPair newHistoryEntry(equationString, result.getResult());
        HistoryService::addEntry(newHistoryEntry);
    }
    
    return result;
};