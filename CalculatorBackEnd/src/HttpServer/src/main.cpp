#include <pistache/endpoint.h>
#include <pistache/net.h>
#include <pistache/router.h>

#include "HttpRequestHandler.h"

int main(int argc, char *argv[])
{
    Pistache::Port port{80};
    Pistache::Address address{Pistache::Ipv4::any(), port};
    auto server = std::make_shared<Pistache::Http::Endpoint>(address);
    auto options = Pistache::Http::Endpoint::options().threads(4);
    Pistache::Rest::Router router;
    //Pistache::Rest::Routes::Post("/store");


    server->init(options);
    server->setHandler(Pistache::Http::make_handler<calculator::httpserver::HttpRequestHandler>());
    server->serve();
}