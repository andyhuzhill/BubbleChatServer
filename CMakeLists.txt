cmake_minimum_required(VERSION 3.10)

project(BubbleChatServer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_FLAGS -Werror)
set(CMAKE_C_FLAGS -Werror)

include_directories(bubblechat)
include_directories(bubblechat/model)

aux_source_directory(bubblechat SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

find_package(Poco REQUIRED Foundation Util Net Data DataMySQL DataSQLite)
target_link_libraries(${PROJECT_NAME} PUBLIC Poco::Foundation Poco::Util Poco::Net Poco::Data Poco::DataMySQL Poco::DataSQLite)

############# Unit Test ##############

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

#--------------------------------------------------------------

add_executable(model_user_test test/model_user_test.cpp)
target_link_libraries(model_user_test PUBLIC Poco::Foundation Poco::Util Poco::Net Poco::Data Poco::DataMySQL Poco::DataSQLite GTest::GTest GTest::Main)

add_test(testUserModel model_user_test)  
