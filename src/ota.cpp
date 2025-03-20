#include "ota.h"
#include "hv/HttpServer.h"
#include "nlohmann/json.hpp"
#include "spdlog/spdlog.h"
#include <string>

ota::ota() { listen_port = 3000; }

ota::~ota() {}

void ota::listen(int port, int worker_threads) {
	listen_port = port;

	ota_service.GET("/", [this](HttpRequest *req, HttpResponse *resp) {
		nlohmann::json ex1 = nlohmann::json::parse(R"(
        "mqtt": {
            "endpoint": "post-cn-apg3xckag01.mqtt.aliyuncs.com",
            "client_id": "GID_test@@@88_ae_dd_90_50_98",
            "username": "Signature|LTAI5tF8J3CrdWmRiuTjxHbF|post-cn-apg3xckag01",
            "password": "A36Z1YCv3yPb7MIGOoMHMli/FI4=",
            "publish_topic": "device-server",
            "subscribe_topic": "devices/88_ae_dd_90_50_98"
        },
        "server_time": {
            "timestamp": 1742440674422,
            "timezone_offset": 480
        },
        "firmware": {
            "version": "1.4.6",
            "url": "https://xiaozhi-voice-assistant.oss-cn-shenzhen.aliyuncs.com/firmwares/v1.4.6_bread-compact-wifi/xiaozhi.bin"
        },
        "activation": {
            "code": "702334",
            "message": "xiaozhi.me\n702334"
        }
        )");
        
		std::string data_str = ex1.dump().c_str();
        
		return resp->Data((void*)data_str.c_str(), data_str.length());
	});

	ota_server.port = port;
	ota_server.service = &ota_service;
	ota_server.worker_threads = worker_threads;
	spdlog::info("ota server start!");
	http_server_run(&ota_server, 0);
}