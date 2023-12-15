cmake_minimum_required(VERSION 3.13)

option(ENABLE_COVERAGE "Enable coverage" OFF)

if(ENABLE_COVERAGE)
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

project(KeyLimePie)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

add_executable(KeyLimePieTest node.cc data_structure.cc set.cc insert.cc find.cc erase.cc rank.cc test.cc)
target_link_libraries(KeyLimePieTest ${GTEST_LIBRARIES})
