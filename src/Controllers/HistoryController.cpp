#include "HistoryController.h"

#include <string>
#include <sstream>

#include <pistache/mime.h>

#include "CalcHistory.h"



void HistoryController::getAllHistory(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res)
{
    CalcHistory history;
    std::string filePath = getenv("HOME");
                filePath += "/calc/history";
    history.initialzeFromFilePath(filePath);

    std::string output = "[";
    if (!history.isEmpty())
    {
        for (auto it = history.oldest(); it != history.newest(); it++)
        {
            if (it != history.oldest())
            {
                output += ",";
            };
            output += "{\"equation\"=\"";
            output += it->getEquation();
            output += "\",\"result\"=\"";
            output += it->getResult();
            output += "\"}";
        }
    }
    output += "]";

    res.send(Pistache::Http::Code::Ok, output, Pistache::Http::Mime::MediaType(Pistache::Http::Mime::Type::Text, Pistache::Http::Mime::Subtype::Json));
    return;
};