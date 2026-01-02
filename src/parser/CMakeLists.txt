cmake_minimum_required(VERSION 3.20)
project(triaina LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(Parser grammar/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.cpp
  DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.hpp
)

FLEX_TARGET(Lexer grammar/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.yy.cpp)

ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

add_executable(triaina_parser
  main.cpp
  lex_bridge.cpp
  ast.hpp
  dump.hpp
  driver.hpp
  ${BISON_Parser_OUTPUTS}
  ${FLEX_Lexer_OUTPUTS}
)

target_include_directories(triaina_parser PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
)

