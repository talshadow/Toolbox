cmake_minimum_required(VERSION 3.5)

project(FastPIMPL LANGUAGES CXX)

find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(${PROJECT_NAME}_SRC main.cpp test_interface.cpp test_impl.cpp)
set(${PROJECT_NAME}_HDR FastPIMPL.h test_interface.h test_impl.h)
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HDR})
target_link_libraries(${PROJECT_NAME} Threads::Threads)
