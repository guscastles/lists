cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(lists LANGUAGES C)
include_directories(include)
set(SOURCES 
        src/list_creation.c
        src/list_removal.c
        src/list_retrieval.c
        src/list_transformation.c
)
set(TEST_SOURCES
        test/test_list.c
        test/unittest.c
        test/test_remove.c
        test/test_list_object.c
)
list(APPEND flags "-Wall")
if (NOT WIN32)
    list(APPEND flags "-g")
endif()
add_library(list
    STATIC 
        ${SOURCES}
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

enable_testing()
add_executable(unittest ${TEST_SOURCES})
target_link_libraries(unittest list cunit)
add_test(unittest ${EXECUTABLE_OUTPUT_PATH}/unittest)
