cmake_minimum_required(VERSION 3.16)
project(ProgrammingQuiz)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES
    src/*.cpp
)

add_executable(prog ${SOURCES})
target_include_directories(prog
 PRIVATE
  include/)