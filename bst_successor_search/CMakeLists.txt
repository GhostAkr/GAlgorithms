cmake_minimum_required(VERSION 3.0.0)
project(BSTSuccessorSearcher VERSION 1.0)

set(HEADERS include/BSTSuccessorSearcher.hpp)
set(SOURCES 
    src/BSTSuccessorSearcher.cpp
    src/main.cpp
)

add_executable(main ${HEADERS} ${SOURCES})
