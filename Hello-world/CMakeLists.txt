cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

INCLUDE_DIRECTORIES(headers)
add_executable(${CMAKE_PROJECT_NAME} 
               main.cpp 
               src/funcs.cpp)