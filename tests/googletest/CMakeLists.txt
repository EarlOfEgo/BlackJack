find_package(GTest REQUIRED)

set(PROJECT_TEST_NAME "${PROJECT_NAME}_test")
include_directories(${GTEST_INCLUDE_DIRS} ${INCLUDES})

add_executable(${PROJECT_TEST_NAME} "testMain.cpp" "BlackJackCardsTests.cpp" "CheckGameTests.cpp")
target_link_libraries(${PROJECT_TEST_NAME} ${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} pthread)

add_test(${PROJECT_TEST_NAME} ${PROJECT_TEST_NAME})



