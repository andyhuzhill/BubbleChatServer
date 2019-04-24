# BubbleChatServer

![](https://img.shields.io/badge/language-cpp11-blue.svg)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/andyhuzhill/BubbleChatServer)
[![Travis (.org) branch](https://img.shields.io/travis/andyhuzhill/BubbleChatServer/master.svg)](https://github.com/andyhuzhill/BubbleChatServer.git)


BubbleChat is intended to be a open-source security instant message service in cpp.

## Build Requirements

* a cpp compiler support c++11 at least;
* cmake build system;
* libmysqlclient-dev or libmariadbclient-dev installed in your system (to connect to MySQL database);

## Optional Requirements

* Google Test Library (If you want to build unit test)

## Build Step

```bash
    git clone https://github.com/andyhuzhill/BubbleChatServer.git
    cd BubbleChatServer
    mkdir build && cd build
    cmake .. && make
    make test
```
