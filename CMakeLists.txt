# CMakeList.txt
cmake_minimum_required(VERSION 3.23)
project(tpi2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

file(GLOB DIR_TESTS "tests/*.cpp")

set(SOURCE_FILES
        main.cpp
        ejercicios.cpp
        ejercicios.h
        definiciones.h
        auxiliares.cpp
        auxiliares.h
        tests/cambiarBanderitaTEST.cpp
        tests/ganoTEST.cpp
        tests/perdioTEST.cpp
        tests/minasAdyacentesTEST.cpp
        tests/sugerir121TEST.cpp
        tests/jugarPlusTEST.cpp tests/definicionesTEST.h)

add_executable(tpi2 ${SOURCE_FILES} ${DIR_TESTS})

set(CMAKE_CXX_FLAGS "-g --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tpi2 gtest gtest_main)
