cmake_minimum_required(VERSION 3.20)
project(triaina LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)
bison_target(
    Parser
    src/grammar/parser.y
    ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.cpp
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.hpp
)
flex_target(Lexer src/grammar/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.yy.cpp)
add_flex_bison_dependency(Lexer Parser)

add_library(cmn STATIC
  src/cmn/trit_vector.cpp
)
target_include_directories(cmn PRIVATE src/)

add_executable(
    triaina_compiler
    src/compiler/main.cpp
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Lexer_OUTPUTS}
    ${PROTO_SRCS}
)

target_include_directories(triaina_compiler PRIVATE
    src/
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(
    triaina_runtime
    src/runtime/main.cpp
)

target_link_libraries(triaina_runtime cmn)

target_include_directories(triaina_runtime PRIVATE
  src/
)

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(test)
endif()

