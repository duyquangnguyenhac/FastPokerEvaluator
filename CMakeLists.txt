cmake_minimum_required(VERSION 3.0)

project(PokerEvaluator)
set(CMAKE_CXX_STANDARD 17)

find_package(benchmark REQUIRED)
add_executable(PokerEvaluator src/main.cpp)
target_link_libraries(PokerEvaluator benchmark::benchmark)
