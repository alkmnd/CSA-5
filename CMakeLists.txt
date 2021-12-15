cmake_minimum_required(VERSION 3.20)
project(CSA_5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
add_executable(CSA_5 main.cpp Bee.cpp Bee.h HoneyPot.h WinnieThePooh.cpp WinnieThePooh.h HoneyPot.cpp)
