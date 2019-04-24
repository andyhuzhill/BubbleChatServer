///////////////////////////////////////////////////////////
///
///     file: chatsession.hpp
///
///   author: andy
///     date: 2019/4/24
///
///////////////////////////////////////////////////////////
#ifndef CHATSESSION_HPP
#define CHATSESSION_HPP

#include <Poco/Net/TCPServerConnection.h>

using Poco::Net::TCPServerConnection;
using Poco::Net::StreamSocket;

class ChatSession
        : public TCPServerConnection
{
public:
    ChatSession(const StreamSocket& socket);

    void run() final;
};

#endif // CHATSESSION_HPP
