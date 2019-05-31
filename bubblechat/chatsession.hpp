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

namespace Bubble {

struct Session {
    
};

class ChatSession
        : public TCPServerConnection
{
public:
    explicit ChatSession(const StreamSocket& socket);

    void run() final;
    
private:
    Session _session;
};

} // Bubble namespace

#endif // CHATSESSION_HPP
