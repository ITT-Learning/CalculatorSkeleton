#include <iostream>

#include <pistache/endpoint.h>

using namespace Pistache;



class TestHandler : public Http::Handler
{
    public:

        HTTP_PROTOTYPE(TestHandler)

        void onRequest(const Http::Request &req, Http::ResponseWriter res) override
        {
            res.send(Http::Code::Ok, "hi");
        };
};



void runInApiMode()
{
    Address addr(Ipv4::any(), Port(5000));
    auto opts = Http::Endpoint::options().threads(1);
    Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(Http::make_handler<TestHandler>());
    server.serve();
};