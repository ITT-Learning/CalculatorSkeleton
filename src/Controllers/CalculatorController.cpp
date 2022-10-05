#include "CalculatorController.h"

#include <string>
#include <unordered_map>
#include <iostream>

#include <pistache/router.h>
#include <pistache/http.h>
#include <rapidjson/document.h>

#include "CalculatorService.h"
#include "Result.h"



static void sendError(Pistache::Http::ResponseWriter& res, std::string message)
{
    res.send(Pistache::Http::Code::Bad_Request,
                 message.c_str(),
                 Pistache::Http::Mime::MediaType(
                     Pistache::Http::Mime::Type::Text,
                     Pistache::Http::Mime::Subtype::Plain));
    return;
};



void CalculatorController::calculate(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res)
{
    std::string bodyString = req.body();
    rapidjson::Document bodyJson;
    bodyJson.Parse(bodyString.c_str());
    if (!bodyJson.IsObject())
    {
        sendError(res, "Root value is not a valid object.");
        return;
    }

    if (!bodyJson.HasMember("equation"))
    {
        sendError(res, "Request body should be a JSON object with an \"equation\" string.");
        return;
    }
    const rapidjson::Value& equationJson = bodyJson["equation"];
    if (!equationJson.IsString())
    {
        sendError(res, "Equation should be a string.");
        return;
    }
    std::string equationString = equationJson.GetString();

    std::unordered_map<std::string, double> variables;
    if (bodyJson.HasMember("variables"))
    {
        const rapidjson::Value& variablesArray = bodyJson["variables"];
        if (!variablesArray.IsArray())
        {
            sendError(res, "Variables should be an array.");
            return;
        }

        for (rapidjson::Value::ConstValueIterator it = variablesArray.Begin(); it != variablesArray.End(); it++)
        {
            if (!it->IsObject())
            {
                sendError(res, "Items in the variables array must be objects.");
                return;
            }

            rapidjson::GenericObject variableObject = it->GetObject();
            if (!variableObject.HasMember("name"))
            {
                sendError(res, "A variable is missing a name.");
                return;
            }
            const rapidjson::Value& variableName = variableObject["name"];
            if (!variableName.IsString())
            {
                std::string message = "A variable has a non-string name. (";
                message += variableName.GetString();
                message += ")";

                sendError(res, message);
                return;
            }
            std::string name = variableName.GetString();

            if (!variableObject.HasMember("value"))
            {
                std::string message = "Variable '" + name + "' does not have a value.";
                sendError(res, message);
                return;
            }
            const rapidjson::Value& variableValue = variableObject["value"];
            if (!variableValue.IsNumber())
            {
                std::string message = "Variable '" + name + "' has a non-number value. (" + variableValue.GetString() + ")";
                sendError(res, message);
                return;
            }
            double value = variableValue.GetDouble();

            variables.erase  (name);
            variables.emplace(name, value);
        }
    }

    Result<std::string> result = CalculatorService::calculate(equationString, variables);

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