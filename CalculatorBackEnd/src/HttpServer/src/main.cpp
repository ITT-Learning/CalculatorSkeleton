#include <pistache/endpoint.h>
#include <pistache/net.h>
#include <pistache/router.h>

#include "HttpRequestHandler.h"

int main(int argc, char *argv[])
{
    Pistache::Port port{80};
    Pistache::Address address{Pistache::Ipv4::any(), port};
    calculator::httpserver::CalculatorEndPoint<double> endPoint{address};
    endPoint.start();
}