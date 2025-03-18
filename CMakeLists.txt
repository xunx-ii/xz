cmake_minimum_required(VERSION 3.10)

project(xz)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(deps)

add_executable(xz 
    src/main.cpp
    src/application.cpp
    src/ota.cpp
)

target_link_libraries(
    xz 
    PRIVATE 
    hv_static
    spdlog
    fmt
    nlohmann_json::nlohmann_json
)