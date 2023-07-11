cmake_minimum_required(VERSION 3.10)

project(url_wrapper)

add_library(url_wrapper STATIC
    src/url.cpp
    src/url_parser.cpp
)

find_package(unofficial-http-parser CONFIG REQUIRED)

target_include_directories(url_wrapper PRIVATE include/url_wrapper)
target_include_directories(url_wrapper PUBLIC include)

target_link_libraries(url_wrapper PRIVATE unofficial::http_parser::http_parser)

set_target_properties(url_wrapper PROPERTIES CXX_STANDARD 11)
