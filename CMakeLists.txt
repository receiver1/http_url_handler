cmake_minimum_required(VERSION 3.10)

project(http_url_handler)

add_library(http_url_handler STATIC
    src/url.cpp
    src/url_parser.cpp
)

find_package(unofficial-http-parser CONFIG REQUIRED)

target_include_directories(http_url_handler PRIVATE include/url_wrapper)
target_include_directories(http_url_handler PUBLIC include)

target_link_libraries(http_url_handler PRIVATE unofficial::http_parser::http_parser)

set_target_properties(http_url_handler PROPERTIES CXX_STANDARD 11)
