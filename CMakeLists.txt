cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Указываем путь к vcpkg toolchain file
#set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(seagame)




# Устанавливаем пути к заголовочным файлам
include_directories("./src/headers")
include_directories("./src/headers/Serializers")
include_directories("./src/headers/Loaders")
include_directories("./nlohmann-json/include")
include_directories("./src/headers/IO")
include_directories("./src/headers/Views")
include_directories("D:/2_git_sea_battle/sea-battle/vcpkg_installed/x64-windows/include/cryptopp")
include_directories("C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um")  # Путь к заголовочным файлам Windows SDK
include_directories("C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/shared")  # Путь к заголовочным файлам Windows SDK

# Собираем все исходные файлы
aux_source_directory("./src/source" SRC)
aux_source_directory("./src/source/Serializers" SERIALIZERS)
aux_source_directory("./src/source/Loaders" LOADERS)
aux_source_directory("./src/source/IO" IO)
aux_source_directory("./src/source/Views" VIEWS)

add_library(llibcryptopp STATIC IMPORTED)

find_package(cryptopp CONFIG REQUIRED)


# Добавляем исполняемый файл
add_executable(seagame
  ./src/main.cpp
  ${SRC}
  ${SERIALIZERS}
  ${LOADERS}
  ${IO}
  ${VIEWS}
)



target_link_libraries(seagame PRIVATE cryptopp::cryptopp)