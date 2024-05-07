add_library(cmsis-core INTERFACE)
target_include_directories(cmsis-core INTERFACE vendor/CMSIS/Core/Include)

add_library(cmsis-air001 STATIC)
target_include_directories(cmsis-air001 PUBLIC vendor/CMSIS/Device/AIR001xx/Include)
target_sources(cmsis-air001 PRIVATE vendor/CMSIS/Device/AIR001xx/Source/system_air001xx.c)
target_sources(cmsis-air001 PRIVATE vendor/CMSIS/Device/AIR001xx/Source/gcc/startup_air001xx.s)
set_property(SOURCE vendor/cmsis-air001/Device/AIR001xx/Source/gcc/startup_air001xx.s PROPERTY LANGUAGE ASM)
target_link_libraries(cmsis-air001 PUBLIC cmsis-core)

option(USE_CMSIS_DSP "Use CMSIS DSP library" OFF)
if (USE_CMSIS_DSP)
    add_library(cmsis-dsp STATIC)
    target_include_directories(cmsis-dsp PUBLIC vendor/CMSIS-DSP/Include)
    file(GLOB_RECURSE CMSIS_DSP_SOURCES vendor/CMSIS-DSP/Source/*.c)
    target_sources(cmsis-dsp PRIVATE ${CMSIS_DSP_SOURCES})
    target_link_libraries(cmsis-dsp PUBLIC cmsis-air001)
    add_compile_definitions(USE_CMSIS_DSP)
endif ()

add_library(hal STATIC)
target_include_directories(hal PUBLIC vendor/AIR001xx_HAL_Driver/Inc)
file(GLOB_RECURSE HAL_SOURCES vendor/AIR001xx_HAL_Driver/Src/*.c)
target_sources(hal PRIVATE ${HAL_SOURCES})
target_link_libraries(hal PUBLIC config cmsis-air001)

add_compile_definitions(
        AIR001_DEV
        ARM_MATH_CM0PLUS
)
