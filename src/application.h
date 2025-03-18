#pragma once

#include <thread>

#include "hv/mqtt_client.h"
#include "ota.h"
#include "queue.h"

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

	void main_loop();
protected:
	void connect_mqtt_server();

	void process(mqtt_message_t *message);
private:
	application();
	~application();

protected:

	bool should_stop_server;

	ota *ota_server;

	struct {
		std::string host;
		int port;
		std::string username;
		std::string password;
	} mqtt_config;

	hv::MqttClient mqtt_client;

	std::thread mqtt_thread;

	safe_queue_no_block<mqtt_message_t *> rev_safe_queue;
};