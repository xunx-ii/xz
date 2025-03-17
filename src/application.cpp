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

    

    return 0;
}