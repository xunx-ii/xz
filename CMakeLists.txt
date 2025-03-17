cmake_minimum_required(VERSION 3.10)

project(xz)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(fmt CONFIG REQUIRED)
find_package(libhv CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_executable(xz src/main.cpp)

target_link_libraries(
    xz 
    PRIVATE 
    fmt::fmt
    hv_static
    nlohmann_json::nlohmann_json
    spdlog::spdlog
)