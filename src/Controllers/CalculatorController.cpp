#include "CalculatorController.h"

#include <string>
#include <unordered_map>
#include <iostream>

#include <pistache/router.h>
#include <pistache/http.h>
#include <rapidjson/document.h>

#include "CalculatorService.h"
#include "Result.h"
#include "HistoryService.h"
#include "CalcHistoryPair.h"



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
    std::string bodyString = req.body();
    rapidjson::Document bodyJson;
    bodyJson.Parse(bodyString.c_str());
    if (!bodyJson.IsObject())
    {
        return Result<std::string>("", false, "Root value is not a valid object.");
    }

    if (!bodyJson.HasMember("equation"))
    {
        return Result<std::string>("", false, "Request body should be a JSON object with an \"equation\" string.");
    }
    const rapidjson::Value& equationJson = bodyJson["equation"];
    if (!equationJson.IsString())
    {
        return Result<std::string>("", false, "Equation should be a string.");
        
    }
    std::string equationString = equationJson.GetString();

    std::unordered_map<std::string, double> variables;
    if (bodyJson.HasMember("variables"))
    {
        const rapidjson::Value& variablesArray = bodyJson["variables"];
        if (!variablesArray.IsArray())
        {
            return Result<std::string>("", false, "Variables should be an array.");
        }

        for (rapidjson::Value::ConstValueIterator it = variablesArray.Begin(); it != variablesArray.End(); it++)
        {
            if (!it->IsObject())
            {
                return Result<std::string>("", false, "Items in the variables array must be objects.");
            }

            rapidjson::GenericObject variableObject = it->GetObject();
            if (!variableObject.HasMember("name"))
            {
                return Result<std::string>("", false, "A variable is missing a name.");
            }
            const rapidjson::Value& variableName = variableObject["name"];
            if (!variableName.IsString())
            {
                std::string message = "A variable has a non-string name. (";
                message += variableName.GetString();
                message += ")";

                return Result<std::string>("", false, message);
            }
            std::string name = variableName.GetString();

            if (!variableObject.HasMember("value"))
            {
                std::string message = "Variable '" + name + "' does not have a value.";
                return Result<std::string>("", false, message);
            }
            const rapidjson::Value& variableValue = variableObject["value"];
            if (!variableValue.IsNumber())
            {
                std::string message = "Variable '" + name + "' has a non-number value. (" + variableValue.GetString() + ")";
                return Result<std::string>("", false, message);
            }
            double value = variableValue.GetDouble();

            variables.erase  (name);
            variables.emplace(name, value);
        }
    }

    Result<std::string> result = CalculatorService::calculate(equationString, variables);

    if (!result.isValid())
    {
        return result;
    }

    if (saveHistory)
    {
        CalcHistoryPair newHistoryEntry(equationString, result.getResult());
        HistoryService::addEntry(newHistoryEntry);
    }

    return result;
};