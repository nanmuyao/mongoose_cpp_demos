#include <assert.h>
#include <fstream>
#include <json/json.h> // 添加这行以包含Json库

#include "AppConfig.h"

using namespace std;

AppConfig* AppConfig::instance = NULL;

AppConfig::AppConfig()
{
    env = new struct env();
    // 读取app_config.json文件, 设置env
    std::ifstream configFile("app_config.json");
    if (configFile.is_open()) {
        Json::Value config;
        configFile >> config;
        env->port = config["port"].asInt();
        // 设置其他env字段
        configFile.close();
    } else {
        std::cerr << "Unable to open config file" << std::endl;
        assert(false);
    }
}

AppConfig* AppConfig::getInstance()
{
    if (instance == NULL) {
        instance = new AppConfig();
    }
    return instance;
}
