cmake_minimum_required(VERSION 3.10)

project(deps)

# libhv
set(WITH_MQTT ON)
set(BUILD_EXAMPLES OFF)
add_subdirectory(libhv)

# fmt
add_subdirectory(fmt)
set_property(TARGET fmt PROPERTY FOLDER "ThirdParty")

# spdlog
set(SPDLOG_FMT_EXTERNAL ON)
add_subdirectory(spdlog)
set_property(TARGET spdlog PROPERTY FOLDER "ThirdParty")

# nlohmann_json
set(JSON_BuildTests OFF CACHE INTERNAL "")
set(JSON_Install OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)

