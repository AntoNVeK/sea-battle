cmake_minimum_required(VERSION 3.20)
set(CMAKE_CPP_COMPILER clang++)
set(CMAKE_CPP_STANDARD 17)

project(seagame)

include_directories("./src/headers")

aux_source_directory("./src/source" SRC)

add_executable(seagame
  ./src/main.cpp
  ${SRC}
)
