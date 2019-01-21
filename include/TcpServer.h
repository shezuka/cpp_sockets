#ifndef SOCKETS_TCPSERVER_H
#define SOCKETS_TCPSERVER_H

#include "Socket.h"

class TcpServer : public Socket {
public:
    ~TcpServer() override;

    void listen(ushort port);
};

#endif //SOCKETS_TCPSERVER_H
