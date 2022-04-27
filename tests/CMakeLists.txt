cmake_minimum_required(VERSION 3.19.3)

project(PaperScissorsRocktTests)

# Fetch Google Test
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

enable_testing()

# Add test file
set(SOURCE_LIST "${CMAKE_CURRENT_SOURCE_DIR}/src/PaperScissorsRocktTests.cpp")

# Make a test executable
set(executable_name PaperScissorsRockGameTests)
add_executable(${executable_name} ${SOURCE_LIST})

# Add a dependency to ensure the correct build order
add_dependencies(${executable_name} PaperScissorsRockGame gtest_main)

# Add PaperScissorsRockGame, gtests link libraries
target_link_libraries(${executable_name} PRIVATE gtest_main gmock PaperScissorsRockGame)

# Add include directories
target_include_directories(${executable_name} PRIVATE "${PROJECT_SOURCE_DIR}/../include")

# discover tests
include(GoogleTest)
gtest_discover_tests(${executable_name})