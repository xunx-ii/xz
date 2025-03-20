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

# onnxruntime
add_compile_definitions(USE_CXX)
set(ORT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/onnxruntime/lib)


find_library(
    ONNXRUNTIME_LIBRARY
    NAMES libonnxruntime.so libonnxruntime.so.1 libonnxruntime.so.1.21.0
    HINTS ${ORT_LIB_DIR}
    PATHS ${ORT_LIB_DIR}
)
find_library(
    ONNXRUNTIME_PROVIDERS_LIBRARY
    NAMES libonnxruntime_providers_shared.so
    HINTS ${ORT_LIB_DIR}
    PATHS ${ORT_LIB_DIR}
)

set(ORT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/onnxruntime/include CACHE STRING "ort include path")