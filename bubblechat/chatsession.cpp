///////////////////////////////////////////////////////////
///
///     file: chatsession.cpp
///
///   author: andy
///     date: 2019/4/24
///
///////////////////////////////////////////////////////////
#include "chatsession.hpp"

#include <Poco/Util/ServerApplication.h>

using Poco::Util::ServerApplication;

ChatSession::ChatSession(const StreamSocket &socket)
    : TCPServerConnection (socket)
{

}

void ChatSession::run()
{
     auto& logger = ServerApplication::instance().logger();

     logger.information("socket = %s", socket().peerAddress().toString());

     for (;;) {
//         socket().receiveBytes()
     }
}
