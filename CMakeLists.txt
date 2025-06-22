cmake_minimum_required(VERSION 3.10)
project(BackTesting)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/strategies"
)

# Collect all .cpp files in the src/ directory
file(GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/strategies/*.cpp"
)

# Executable target
add_executable(BackTesting ${SOURCES})