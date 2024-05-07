cmake_minimum_required(VERSION 3.20)
set(CMAKE_TOOLCHAIN_FILE toolchain-arm-none-eabi.cmake)
project(air-demo)
enable_language(ASM)
enable_language(C)
enable_language(CXX)

add_subdirectory(lib)

add_library(config INTERFACE)
target_include_directories(config INTERFACE config)

add_executable(${PROJECT_NAME}.elf)
target_sources(${PROJECT_NAME}.elf PRIVATE src/main.cpp)
target_link_libraries(${PROJECT_NAME}.elf PRIVATE hal config)
