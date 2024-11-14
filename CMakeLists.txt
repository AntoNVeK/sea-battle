cmake_minimum_required(VERSION 3.20)
set(CMAKE_CPP_COMPILER g++)
set(CMAKE_CPP_STANDARD 17)

project(seagame)

include_directories("./src/headers")
include_directories("./src/headers/Serializers")
include_directories("./nlohmann-json/include")

aux_source_directory("./src/source" SRC)
aux_source_directory("./src/source/Serializers" SERIALIZERS)

add_executable(seagame
  ./src/main.cpp
  ${SRC}
  ${SERIALIZERS}
)
