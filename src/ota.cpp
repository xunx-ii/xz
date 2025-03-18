#include "ota.h"
#include "hv/HttpServer.h"

#include "spdlog/spdlog.h"

ota::ota()
{
    listen_port = 41300;
}

ota::~ota()
{

}

void ota::listen(int port, int worker_threads)
{
    listen_port = port;

    ota_service.GET("/ota", [](HttpRequest* req, HttpResponse* resp) {
        static char data[] = "0123456789";
        return resp->Data(data, 10);
    });

    ota_server.port = port;
    ota_server.service = &ota_service;
    ota_server.worker_threads = worker_threads;
    spdlog::info("ota server start!");
    http_server_run(&ota_server, 0);
}