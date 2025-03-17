#pragma once

#include <string>

#include "hv/HttpServer.h"

class ota {
public:
    ota();
    ~ota();

    // 开始监听
    void listen(int port = 41300, int worker_threads = 2);

protected:
    // 监听的端口
    int listen_port;
    // 当前的版本
    std::string current_version;

    // OTA响应服务器
    HttpService ota_service;
    http_server_t ota_server;
};