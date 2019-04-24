///////////////////////////////////////////////////////////
///
///     file: chatsession.cpp
///
///   author: andy
///     date: 2019/4/24
///
///////////////////////////////////////////////////////////
#include "chatsession.hpp"

#include <iostream>

#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/StreamCopier.h>

using Poco::StreamCopier;
using Poco::Util::ServerApplication;
using Poco::Net::SocketStream;

ChatSession::ChatSession(const StreamSocket &socket)
    : TCPServerConnection (socket)
{

}

void ChatSession::run()
{
    auto& logger = ServerApplication::instance().logger();

    logger.information("socket = %s", socket().peerAddress().toString());

    SocketStream stream(socket());
    for (;;) {
        StreamCopier::copyStreamUnbuffered(stream, std::cout);
    }
}
