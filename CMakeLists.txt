cmake_minimum_required(VERSION 3.20)
project(lib_ADS7830 C)

set(CMAKE_C_STANDARD 99)

# add dependencies
include(cpm/CPM.cmake)
CPMAddPackage("gh:JeroenVandezande/LowLevelCInterfaces@1.2.0")

add_library(lib_ADS7830 ADS7830.c)

target_include_directories (lib_ADS7830 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(lib_ADS7830 PUBLIC LowLevelCInterfaces m)