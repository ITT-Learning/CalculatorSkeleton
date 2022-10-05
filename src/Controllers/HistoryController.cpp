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

    std::stringstream hout;
    hout << "[";
    if (!history.isEmpty())
    {
        for (auto it = history.oldest(); it != history.newest(); it++)
        {
            if (it != history.oldest())
            {
                hout << ",";
            };
            hout << "{\"equation\":\"";
            hout << it->getEquation();
            hout << "\",\"result\":";
            hout << it->getResult();
            hout << "}";
        }
    }
    hout << "]";

    res.send(Pistache::Http::Code::Ok, hout.str().c_str(), Pistache::Http::Mime::MediaType(
                                                               Pistache::Http::Mime::Type::Text, 
                                                               Pistache::Http::Mime::Subtype::Json));
    return;
};