#pragma once

#include "hv/mqtt_client.h"
#include "ota.h"

class application {
public:
	static application &get() {
		static application instance;
		return instance;
	}

	application(const application &) = delete;

	application &operator=(const application &) = delete;

public:
	int run();

protected:
    void connect_mqtt_server();

private:
	application();
	~application();

protected:
	ota *ota_server;

	struct {
		std::string host;
		int port;
		std::string username;
		std::string password;
	} mqtt_config;

	hv::MqttClient mqtt_client;
};