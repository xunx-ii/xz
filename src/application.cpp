#include "application.h"

application::application()
{

}

application::~application()
{
    
}

int application::run()
{
    ota_server = new ota();
    // 先启动一下OTA服务器
    ota_server->listen();

    

    return 0;
}