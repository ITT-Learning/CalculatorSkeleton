#ifndef CONTROLLERS_HISTORY_CONTROLLER_H
#define CONTROLLERS_HISTORY_CONTROLLER_H

#include <pistache/router.h>
#include <pistache/http.h>



class HistoryController
{
    public:
        static void getAllHistory(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res);
        static void getByIndex   (const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res);
        static void deleteByIndex(const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res);
        static void cors         (const Pistache::Rest::Request& req, Pistache::Http::ResponseWriter res);

    private:
        HistoryController() {};
};

#endif