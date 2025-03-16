## 安装jsoncpp
1. 安装编译
    ```
    git clone https://github.com/open-source-parsers/jsoncpp.git
    cd jsoncpp
    mkdir build
    cd build
    cmake ..
    make
    ```
2. 在build目录下的lib中生成静态库，修改CmakeLists进行构建

使用conan,conan仓库没有这个项目,在third_party中引入https://github.com/Gregwar/mongoose-cpp
在main.cpp中导入使用

## 在main.cpp中导入mongoose-cpp库

1. 确保你已经将`mongoose-cpp`库克隆到`third_party`目录中：
    ```sh
    git clone https://github.com/Gregwar/mongoose-cpp third_party/mongoose-cpp
    ```

2. 在你的`CMakeLists.txt`文件中添加以下内容以包含`mongoose-cpp`库：
    ```cmake
    add_subdirectory(third_party/mongoose-cpp)
    include_directories(third_party/mongoose-cpp)
    target_link_libraries(your_target_name mongoose-cpp)
    ```

3. 在`main.cpp`中导入并使用`mongoose-cpp`库：
    ```cpp
    // filepath: /Users/hanzhiqiang/Documents/workspace_lx/mongoose_cpp_demos/main.cpp
    #include "mongoose/mongoose.h"
    #include "mongoose-cpp/Server.h"

    int main() {
        // ...existing code...

        // 使用mongoose-cpp库的示例代码
        Mongoose::Server server(8080);
        server.start();

        // ...existing code...
    }
    ```

## 启动main.cpp

1. 在项目根目录下创建并进入`build`目录：
    ```sh
    mkdir build
    cd build
    ```

2. 运行`cmake`命令生成Makefile：
    ```sh
    cmake ..
    ```

3. 编译项目：
    ```sh
    make
    ```

4. 运行生成的可执行文件：
    ```sh
    ./mongoose_cpp_demos
    ```