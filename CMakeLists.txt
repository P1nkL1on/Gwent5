cmake_minimum_required(VERSION 2.8)
project(GwentTests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/Cards/archieve.cpp
    ${PROJECT_SOURCE_DIR}/Cards/card.cpp
    ${PROJECT_SOURCE_DIR}/Cards/view.cpp
    ${PROJECT_SOURCE_DIR}/Cards/testcase.cpp)

add_library(cards_lib ${SOURCE_FILES})

enable_testing()

file(GLOB TEST_CASE_SOURCES ${PROJECT_SOURCE_DIR}/Tests/Cases/*.cpp)
foreach (test_case_source ${TEST_CASE_SOURCES})
    get_filename_component(test_name ${test_case_source} NAME_WLE)
    add_executable(${test_name} ${test_case_source})
    target_link_libraries(${test_name} PUBLIC cards_lib)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach (test_case_source ${TEST_CASE_SOURCES})
