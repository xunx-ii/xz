#pragma once

#include "ota.h"

class application {
public:
    static application& get() {
        static application instance;
        return instance;
    }

    application(const application&) = delete;
    
    application& operator=(const application&) = delete;
public:
    int run();

private:
    application();
    ~application();
    
    ota* ota_server;

    //hv::MqttClient cli;
};