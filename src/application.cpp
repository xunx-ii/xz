#include "application.h"

#include "nlohmann/json.hpp"
#include "spdlog/spdlog.h"

#include <thread>

application::application() {
    should_stop_server = false;
    
}

application::~application() { 

    mqtt_thread.join(); 
}

int application::run() {
	// 先启动一下OTA服务器 OTA服务器在异步跑
	ota_server = new ota();
	ota_server->listen();

	mqtt_thread = std::thread([this]() 
        { 
            spdlog::info("mqtt thread start!");
            connect_mqtt_server(); 
        });

    main_loop();

	return 0;
}

void application::process(mqtt_message_t *message)
{

}

void application::main_loop() {
    while (!should_stop_server) {
        auto val = rev_safe_queue.dequeue();
        if(val.has_value()){
            process(val.value());
        }
    }
}

void application::connect_mqtt_server() {
	mqtt_client.setAuth(mqtt_config.username.c_str(), mqtt_config.password.c_str());

	mqtt_client.onConnect = [this](hv::MqttClient *client) {

	};

	mqtt_client.onMessage = ([this](hv::MqttClient *client, mqtt_message_t *message) {
        rev_safe_queue.enqueue(message);
	});

	mqtt_client.onClose = [this](hv::MqttClient *client) {

	};

	mqtt_client.setPingInterval(90);
	mqtt_client.connect(mqtt_config.host.c_str(), mqtt_config.port, false);
	mqtt_client.run();
}