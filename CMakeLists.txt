cmake_minimum_required(VERSION 2.0)

set(CMAKE_SUPPRESS_REGENERATION true)

project(SnakeGame)

set(CMAKE_GENERATOR_PLATFORM win32)
set(CMAKE_GENERATOR_PLATFORM x64)
set(CMAKE_CXX_STANDARD 17)	

set(SOURCE_EXE SnakeGame/SnakeMain.cpp SnakeGame/Fruit.cpp SnakeGame/Game.cpp SnakeGame/Map.cpp SnakeGame/randomize.cpp SnakeGame/Snake.cpp)		# Установка переменной со списком исходников для исполняемого файла

set(SOURCE_HEADER SnakeGame/crt_memory_leaks.h SnakeGame/data.h SnakeGame/Fruit.h SnakeGame/Game.h SnakeGame/Map.h SnakeGame/randomize.hpp SnakeGame/Snake.h)	

add_executable(${PROJECT_NAME} ${SOURCE_EXE})
add_library(${PROJECT_NAME} MODULE ${SOURCE_HEADER})

target_compile_definitions(SnakeGame PUBLIC "$<$<CONFIG:Debug>:MYDEBUG_MACRO>")