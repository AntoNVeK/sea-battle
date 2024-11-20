cmake_minimum_required(VERSION 3.20)
set(CMAKE_CPP_COMPILER g++)
set(CMAKE_CPP_STANDARD 17)

project(seagame)

include_directories("./src/headers")
include_directories("./src/headers/Serializers")
include_directories("./src/headers/Loaders")
include_directories("./nlohmann-json/include")

include_directories("./src/headers/Controllers")
include_directories("./src/headers/Views")

aux_source_directory("./src/source" SRC)
aux_source_directory("./src/source/Serializers" SERIALIZERS)
aux_source_directory("./src/source/Loaders" LOADERS)
aux_source_directory("./src/source/Controllers" CONTROLLERS)
aux_source_directory("./src/source/Views" VIEWS)

add_executable(seagame
  ./src/main.cpp
  ${SRC}
  ${SERIALIZERS}
  ${LOADERS}
  ${CONTROLLERS}
  ${VIEWS}
)
