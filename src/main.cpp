#include "application.h"

int main() 
{
    application& app = application::get();
    return app.run();
}