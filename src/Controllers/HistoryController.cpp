#include "HistoryController.h"

#include <string>

#include <pistache/mime.h>

#include "HistoryService.h"



void HistoryController::getAllHistory(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res)
{
    std::string history = HistoryService::getAllHistory();

    res.send(
        Pistache::Http::Code::Ok,
        history.c_str(),
        Pistache::Http::Mime::MediaType(
            Pistache::Http::Mime::Type::Text, 
            Pistache::Http::Mime::Subtype::Json)
    );
    return;
};



void HistoryController::getByIndex(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res)
{
    int index = req.param(":index").as<int>();

    Result<std::string> found = HistoryService::getByIndex(index);

    if (!found.isValid())
    {
        res.send(
            Pistache::Http::Code::Bad_Request,
            found.getError().c_str(),
            Pistache::Http::Mime::MediaType(
                Pistache::Http::Mime::Type::Text, 
                Pistache::Http::Mime::Subtype::Plain)
        );
        return;
    }

    res.send(
        Pistache::Http::Code::Ok,
        found.getResult().c_str(),
        Pistache::Http::Mime::MediaType(
            Pistache::Http::Mime::Type::Text, 
            Pistache::Http::Mime::Subtype::Json)
    );
    return;
};


void HistoryController::deleteByIndex(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res)
{
    int index = req.param(":index").as<int>();
    Result<std::string> removed = HistoryService::deleteByIndex(index);

    if (!removed.isValid())
    {
        res.send(
            Pistache::Http::Code::Bad_Request,
            removed.getError().c_str(),
            Pistache::Http::Mime::MediaType(
                Pistache::Http::Mime::Type::Text, 
                Pistache::Http::Mime::Subtype::Plain)
        );
        return;
    }

    res.send(
        Pistache::Http::Code::Ok,
        removed.getResult().c_str(),
        Pistache::Http::Mime::MediaType(
            Pistache::Http::Mime::Type::Text, 
            Pistache::Http::Mime::Subtype::Json)
    );
    return;
};