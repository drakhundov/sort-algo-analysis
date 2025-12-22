cmake_minimum_required(VERSION 3.16)
project(sort_algo_analysis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE ALL_SRC CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

set(COMMON_SRC ${ALL_SRC})
list(FILTER COMMON_SRC EXCLUDE REGEX ".*/main\\.cpp$")

add_library(sort_algo_lib ${COMMON_SRC})
target_include_directories(sort_algo_lib PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_executable(app
        "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)
target_link_libraries(app PRIVATE sort_algo_lib)

# playground: shared code + playground.cpp (no main.cpp)
add_executable(playground
        "${CMAKE_CURRENT_SOURCE_DIR}/playground.cpp"
)
target_link_libraries(playground PRIVATE sort_algo_lib)
