cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


project(seagame)




# ������������� ���� � ������������ ������
include_directories("./src/headers")
include_directories("./src/headers/Serializers")
include_directories("./src/headers/Loaders")
include_directories("./nlohmann-json/include")
include_directories("./src/headers/IO")
include_directories("./src/headers/Views")


# �������� ��� �������� �����
aux_source_directory("./src/source" SRC)
aux_source_directory("./src/source/Serializers" SERIALIZERS)
aux_source_directory("./src/source/Loaders" LOADERS)
aux_source_directory("./src/source/IO" IO)
aux_source_directory("./src/source/Views" VIEWS)




# ��������� ����������� ����
add_executable(seagame
  ./src/main.cpp
  ${SRC}
  ${SERIALIZERS}
  ${LOADERS}
  ${IO}
  ${VIEWS}
)
