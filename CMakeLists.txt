cmake_minimum_required(VERSION 3.16)

# 设置项目名称和版本
project(
    CPlusPlus
    VERSION 1.0.0
    LANGUAGES CXX
)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 主程序的可执行文件
add_executable(CPlusPlus Main.cpp)

# 添加子目录 App
add_subdirectory(App)

# 链接 App 库到主程序
target_link_libraries(
    CPlusPlus
    PRIVATE App
)

# 设置包含目录
target_include_directories(
    CPlusPlus
    PUBLIC ${PROJECT_SOURCE_DIR}
)

# 安装配置
install(TARGETS CPlusPlus DESTINATION bin)
