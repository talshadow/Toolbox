cmake_minimum_required(VERSION 3.5)

project(LoggerHelper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(${PROJECT_NAME}_SRC main.cpp)
set(${PROJECT_NAME}_HDR LoggerHelper.hpp)
add_executable(LoggerHelper ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HDR})
