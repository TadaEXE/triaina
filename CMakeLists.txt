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
    grammar/parser.y
    ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.cpp
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.hpp
)
flex_target(Lexer grammar/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.yy.cpp)
add_flex_bison_dependency(Lexer Parser)

find_package(Protobuf CONFIG REQUIRED)
set(PROTO_FILES
  proto/graph/v1/graph.proto
)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

add_compile_definitions("DEBUG_BUILD=$<CONFIG:Debug>")
add_library(ds STATIC src/ds/gate.cpp src/ds/tree.cpp src/ds/trivec.cpp)

target_include_directories(ds PRIVATE src/)

add_executable(
    triaina_parser
    src/parser/main.cpp
    src/parser/lex_bridge.cpp
    src/parser/driver.cpp
    src/parser/ast/ast.cpp
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Lexer_OUTPUTS}
    ${PROTO_SRCS}
)

target_include_directories(
    triaina_parser
    PRIVATE src/ ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(triaina_parser PRIVATE protobuf::libprotobuf)

add_executable(triaina_runtime src/runtime/main.cpp)

target_link_libraries(triaina_runtime ds)

target_include_directories(triaina_runtime PRIVATE src/)

include(CTest)
enable_testing()

add_subdirectory(test EXCLUDE_FROM_ALL)

add_custom_target(build-tests DEPENDS triaina_tests)
target_compile_definitions(triaina_tests PUBLIC "TEST_BUILD=1")
target_compile_definitions(ds PUBLIC "TEST_BUILD=1")
