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

#include <Poco/FIFOBuffer.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/StreamCopier.h>

using Poco::FIFOBuffer;
using Poco::StreamCopier;
using Poco::Util::ServerApplication;
using Poco::Net::SocketStream;

using namespace Bubble;

ChatSession::ChatSession(const StreamSocket &socket)
    : TCPServerConnection (socket)
{

}

void ChatSession::run()
{
    auto& logger = ServerApplication::instance().logger();

    logger.information("peer socket = %s", socket().peerAddress().toString());
    
    auto sock = socket();
    FIFOBuffer fifo(4 * 1024);
    
    for (;;) {
        auto cnt = sock.receiveBytes(fifo);
        if (!cnt) {
            logger.information("Disconnected! %s", sock.peerAddress().toString());
            break;
        }
    }
}
