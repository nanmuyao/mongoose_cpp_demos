#include "AppConfig.h"

AppConfig* AppConfig::instance = NULL;


AppConfig::AppConfig()
{
    env = new struct env();
}

AppConfig* AppConfig::getInstance()
{
    if (instance == NULL) {
        instance = new AppConfig();
    }
    return instance;
}
