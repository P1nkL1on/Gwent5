cmake_minimum_required(VERSION 2.8.11)
project(Gwent5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

enable_testing()
add_executable(ok1 ${PROJECT_SOURCE_DIR}/Tests/Cases/test1.cpp)
add_executable(ok2 ${PROJECT_SOURCE_DIR}/Tests/Cases/test2.cpp)
add_test(NAME main COMMAND ok1)
add_test(NAME main2 COMMAND ok2)
