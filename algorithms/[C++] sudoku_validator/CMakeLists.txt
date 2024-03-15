cmake_minimum_required(VERSION 3.0.0)
project(SudokuValidator VERSION 1.0)

set(HEADERS include/SudokuValidator.hpp)
set(SOURCES 
    src/SudokuValidator.cpp
    src/main.cpp
)

add_executable(main ${HEADERS} ${SOURCES})
