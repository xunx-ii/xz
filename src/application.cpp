#include "application.h"

application::application()
{

}

application::~application()
{
    
}

int application::run()
{
    // 先启动一下OTA服务器
    ota_server = new ota();
    ota_server->listen();

    connect_mqtt_server();    

    return 0;
}

void application::connect_mqtt_server()
{
    mqtt_client.setAuth(mqtt_config.username.c_str(), mqtt_config.password.c_str());
    
    mqtt_client.onConnect = [this](hv::MqttClient* client){

    };

    mqtt_client.onMessage = ([this](hv::MqttClient* client, mqtt_message_t* message){

    });

    mqtt_client.onClose = [this](hv::MqttClient* client){
        
    };

    mqtt_client.setPingInterval(90);
    mqtt_client.connect(mqtt_config.host.c_str(), mqtt_config.port, false);
    mqtt_client.run();
}