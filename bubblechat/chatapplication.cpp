///////////////////////////////////////////////////////////
///
///     file: bubblechatapplication.cpp
///
///   author: Andy Scout <andyhuzhill@gmail.com>
///     date: 2019/4/24
///
///////////////////////////////////////////////////////////
#include "chatapplication.hpp"
#include "chatsession.hpp"

#include <Poco/Data/Session.h>
#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/SQLite/Connector.h>

#include <Poco/Net/TCPServer.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Util/Option.h>
#include <Poco/Util/OptionSet.h>
#include <Poco/Util/HelpFormatter.h>

#include <iostream>

using Poco::UInt16;

using namespace Poco::Data::Keywords;
using Poco::Data::Connector;
using Poco::Data::Session;
using Poco::Data::Statement;

using Poco::Net::ServerSocket;
using Poco::Net::TCPServer;
using Poco::Net::TCPServerConnectionFactory;
using Poco::Net::TCPServerConnectionFactoryImpl;

using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;

using namespace Bubble;

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

    options.addOption(
        Option("help", "h", "display help information on command line arguments")
        .required(false)
        .repeatable(false));
}

void ChatApplication::handleOption(const std::string &name, const std::string &value)
{
    ServerApplication::handleOption(name, value);

    if (name == "help") {
        _helpRequested = true;
    }
}

int ChatApplication::main(const std::vector<std::string> &args)
{
    (void) args;
    
    if (_helpRequested) {
        displayHelp();
    } else {
        UInt16 port = static_cast<UInt16>(config().getUInt("port", 9999));

        auto pSessionFactory = TCPServerConnectionFactory::Ptr(new TCPServerConnectionFactoryImpl<ChatSession>());

        ServerSocket sock(port);
        sock.setReusePort(true);
        sock.setReuseAddress(true);

        TCPServer srv(pSessionFactory, sock);
        srv.start();

        logger().information("Start server listening on port %hu.", port);
        waitForTerminationRequest();

        logger().information("Stop server ...");
        srv.stop();
    }

    return EXIT_OK;
}

void ChatApplication::displayHelp()
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader("A instant message server application.");
    helpFormatter.format(std::cout);
}
