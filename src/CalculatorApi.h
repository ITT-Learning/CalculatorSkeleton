#include <iostream>

#include <pistache/router.h>
#include <pistache/endpoint.h>

#include "CalculatorController.h"
#include "HistoryController.h"

using namespace Pistache;



Rest::Router getRouter()
{
    Rest::Router router;

    Rest::Routes::Get(router, "/api/calculate", Rest::Routes::bind(&CalculatorController::calculate));

    Rest::Routes::Get(router, "/api/history", Rest::Routes::bind(&HistoryController::getAllHistory));

    return router;
};



void runInApiMode()
{
    Address addr(Ipv4::any(), Port(5000));
    auto opts = Http::Endpoint::options().threads(1);
    Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(getRouter().handler());
    std::cout << "\nServer running\n\nPress <CTRL-C> to exit...\n";
    std::cout.flush();
    server.serve();
};