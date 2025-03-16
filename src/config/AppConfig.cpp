#include "AppConfig.h"
#include <fstream>
#include <json/json.h> // Add this line to include the Json library

using namespace std;

AppConfig* AppConfig::instance = NULL;


AppConfig::AppConfig()
{
    env = new struct env();
    // 读取app_config.json文件, 设置env
    // std::ifstream configFile("/path/to/app_config.json");
    // if (configFile.is_open()) {
    //     Json::Value config;
    //     configFile >> config;
    //     env->someField = config["someField"].asString();
    //     // 设置其他env字段
    //     configFile.close();
    // } else {
    //     std::cerr << "Unable to open config file" << std::endl;
    // }
    

}

AppConfig* AppConfig::getInstance()
{
    if (instance == NULL) {
        instance = new AppConfig();
    }
    return instance;
}
