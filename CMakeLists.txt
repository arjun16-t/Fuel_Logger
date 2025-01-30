cmake_minimum_required(VERSION 3.10)

# Project name
project(Fuel_Logger)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(Fuel_Logger 
    main.cpp
    file_handling.cpp
    fillups.cpp
    login.cpp
)

# Include directories
target_include_directories(Fuel_Logger PRIVATE .)
