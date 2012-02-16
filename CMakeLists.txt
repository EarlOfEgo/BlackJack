cmake_minimum_required(VERSION 2.6)
set(PROJECT_NAME blackjack)
project(${PROJECT_NAME})

set(INCLUDES ${PROJECT_SOURCE_DIR}/include)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests/googletest)
