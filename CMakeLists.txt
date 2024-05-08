cmake_minimum_required(VERSION 3.20)
set(CMAKE_TOOLCHAIN_FILE toolchain-arm-none-eabi.cmake)
project(air-demo)
enable_language(ASM)
enable_language(C)
enable_language(CXX)

# target `config` should be defined before `hal`
# since `hal` depends on `config`
add_library(config INTERFACE)
add_subdirectory(lib)

target_include_directories(config INTERFACE config)
add_compile_definitions(
        AIR001_DEV
        ARM_MATH_CM0PLUS
)

add_executable(${PROJECT_NAME}.elf)
target_sources(${PROJECT_NAME}.elf PRIVATE src/main.cpp)
target_link_libraries(${PROJECT_NAME}.elf PRIVATE hal config)
