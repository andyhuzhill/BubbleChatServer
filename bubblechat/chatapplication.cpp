///////////////////////////////////////////////////////////
///
///     file: bubblechatapplication.cpp
///
///   author: andy
///     date: 2019/4/24
///
///////////////////////////////////////////////////////////
#include "chatapplication.hpp"
#include "chatsession.hpp"

#include <Poco/Net/TCPServer.h>

#include <iostream>

using Poco::UInt16;

using Poco::Net::TCPServer;
using Poco::Net::TCPServerConnectionFactory;
using Poco::Net::TCPServerConnectionFactoryImpl;

ChatApplication::ChatApplication()
{

}

void ChatApplication::initialize(Application &self)
{
    loadConfiguration();
    ServerApplication::initialize(self);
}

void ChatApplication::uninitialize()
{
    ServerApplication::uninitialize();
}

void ChatApplication::reinitialize(Poco::Util::Application &self)
{
    ServerApplication::reinitialize(self);
}

void ChatApplication::defineOptions(OptionSet &options)
{
    ServerApplication::defineOptions(options);
}

void ChatApplication::handleOption(const std::string &name, const std::string &value)
{
    ServerApplication::handleOption(name, value);
}

int ChatApplication::main(const std::vector<std::string> &args)
{
    (void) args;

    UInt16 port = static_cast<UInt16>(config().getUInt("port", 8080));

    logger().information("Start server listening on port %hu.", port);

    auto pSessionFactory = TCPServerConnectionFactory::Ptr(new TCPServerConnectionFactoryImpl<ChatSession>());
    TCPServer srv(pSessionFactory, port);
    srv.start();
    waitForTerminationRequest();

    logger().information("Stop server ...");
    srv.stop();
    return EXIT_OK;
}
