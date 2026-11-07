find_package(GTest 1.17 CONFIG QUIET)
if(NOT GTest_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
    GIT_SHALLOW TRUE
  )
  set(BUILD_GMOCK OFF CACHE BOOL "Build GoogleMock")
  set(INSTALL_GTEST OFF CACHE BOOL "Install GoogleTest")
  FetchContent_MakeAvailable(googletest)
endif()

add_executable(triaina_tests placeholder_test.cpp)
target_link_libraries(triaina_tests PRIVATE cmn GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(triaina_tests)
