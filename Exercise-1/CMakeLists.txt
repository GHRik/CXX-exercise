cmake_minimum_required(VERSION 3.10)
project(Exercise-1)


set(SOURCES 
    src/Cat.cpp
    src/Dog.cpp
    src/Monkey.cpp
    src/Interfaces/Animal.cpp
    )
set(TEST_SOURCES
   )

INCLUDE_DIRECTORIES(headers)
add_executable(${CMAKE_PROJECT_NAME}
               ${SOURCES} 
               main.cpp 
               )

project(Tests)
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

INCLUDE_DIRECTORIES(headers)
add_executable(${CMAKE_PROJECT_NAME}
               tests/run_tests.cpp
               ${SOURCES}
               ${TEST_SOURCES} 
               )

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  gtest_main
)

add_custom_command( TARGET ${CMAKE_PROJECT_NAME}
                    POST_BUILD
                    COMMAND ${CMAKE_PROJECT_NAME}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )