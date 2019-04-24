cmake_minimum_required(VERSION 2.8)

project(BubbleChatServer)

aux_source_directory(bubblechat SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

find_package(Poco REQUIRED Foundation Data Util Net)
target_link_libraries(${PROJECT_NAME} Poco::Foundation Poco::Data Poco::Util Poco::Net)
