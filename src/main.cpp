#include "hv/HttpServer.h"
using namespace hv;

int main() {
    HttpService router;
    router.GET("/", [](HttpRequest* req, HttpResponse* resp) {
        static char data[] = "0123456789";
        return resp->Data(data, 10);
    });

    HttpServer server(&router);
    server.setPort(48080);
    server.setThreadNum(64);
    server.run();
    return 0;
}