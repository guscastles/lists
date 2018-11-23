cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(lists LANGUAGES C)
list(APPEND flags "-Wall")
if (NOT WIN32)
    list(APPEND flags "-g")
endif()
add_library(list
    STATIC
        include/list.h
        src/list_creation.c
        src/list_removal.c
        src/list_retrieval.c
        src/list_transformation.c
)
target_compile_options(list
    PRIVATE
        ${flags}
)
add_executable(lists src/lists.c)
target_compile_options(lists
    PRIVATE
        ${flags}
)
target_link_libraries(lists list)
