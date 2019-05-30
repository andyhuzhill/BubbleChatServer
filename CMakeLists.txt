cmake_minimum_required(VERSION 2.8)

project(BubbleChatServer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_FLAGS -Werror)
set(CMAKE_C_FLAGS -Werror)

aux_source_directory(bubblechat SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

find_package(Poco REQUIRED Foundation Data Util Net DataMySQL DataSQLite)
target_link_libraries(${PROJECT_NAME} PUBLIC Poco::Foundation Poco::Data Poco::Util Poco::Net Poco::DataMySQL Poco::DataSQLite)
