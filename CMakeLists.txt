cmake_minimum_required(VERSION 3.31)
project(GTFS_analyzer)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)


add_executable(gtfs-analyzer
    src/main.cpp
    src/Arg_Parser.cpp
    src/GTFS_Handler.cpp
)

target_include_directories(gtfs-analyzer PRIVATE include)