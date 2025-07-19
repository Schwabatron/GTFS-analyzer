cmake_minimum_required(VERSION 3.16)
project(GTFSAnalyzer)

set(CMAKE_CXX_STANDARD 17)

# Source files
add_executable(gtfs-analyzer
    src/main.cpp
    src/Arg_Parser.cpp
    src/GTFS_Handler.cpp
)

# Header include directories
target_include_directories(gtfs-analyzer PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
