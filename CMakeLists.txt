cmake_minimum_required(VERSION 3.16)
project(StrategyGameEngine VERSION 0.1 LANGUAGE CXX)

#use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add engine subdir
add_subdirectory(Engine)

#add nlohman_json
include(FetchContent)
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

#Gather main
add_executable(StrategyGameEngine main.cpp)

#Link engine target
target_link_libraries(StrategyGameEngine PRIVATE Engine)

#Add include paths
target_include_directories(StrategyGameEngine PRIVATE Engine/include)