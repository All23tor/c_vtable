cmake_minimum_required(VERSION 3.11.0)
project(vtable)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.c 
  src/Animal.c
  src/Pets.c
  src/Farm.c
)
target_include_directories(${PROJECT_NAME} PUBLIC include)
