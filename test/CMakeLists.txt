cmake_minimum_required(VERSION 3.20)

find_package(GTest QUIET)

if(NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

add_executable(
    triaina_tests
    ds/trivec_test.cpp
    ds/trit_test.cpp
    ds/tree_test.cpp
    ds/gate_test.cpp
    resty_test.cpp
)

target_link_libraries(triaina_tests PRIVATE ds GTest::gtest_main)

target_include_directories(
    triaina_tests
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

include(GoogleTest)

gtest_discover_tests(triaina_tests DISCOVERY_MODE PRE_TEST)

add_custom_target(
    run-tests
    COMMENT ""
    COMMAND
        ${CMAKE_CTEST_COMMAND} --test-dir ${CMAKE_BINARY_DIR}
        --output-on-failure
    DEPENDS triaina_tests
)
