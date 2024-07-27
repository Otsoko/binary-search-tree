cmake_minimum_required(VERSION 3.20)

project(binary-search-tree
    VERSION 1.0
    LANGUAGES C
)

set(CMAKE_C_FLAGS "-O3 -Wall -Wextra -pedantic")

add_library(binarysearchtree
    STATIC
    lib/binary_search_tree.c
)

add_executable(app
    app/app.c
)

target_include_directories(app
    PUBLIC lib
)

target_link_libraries(app
    PRIVATE binarysearchtree
)
