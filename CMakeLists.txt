cmake_minimum_required(VERSION 3.5)

project(pp_scan_EREWPRAM LANGUAGES CXX)

find_package(OpenMP REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pp_scan_EREWPRAM main.cpp)

target_link_libraries(pp_scan_EREWPRAM PUBLIC OpenMP::OpenMP_CXX)

install(TARGETS pp_scan_EREWPRAM
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

