cmake_minimum_required(VERSION 2.8.11)
project(GwentTests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

enable_testing()

file(GLOB TEST_CASE_SOURCES ${PROJECT_SOURCE_DIR}/Tests/Cases/*.cpp)
foreach (test_case_source ${TEST_CASE_SOURCES})
    get_filename_component(test_name ${test_case_source} NAME_WLE)
    add_executable(${test_name} ${test_case_source})
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach (testsourcefile ${TEST_CASE_SOURCES})
