#ifndef SOCKETS_TCPCLIENT_H
#define SOCKETS_TCPCLIENT_H

#include "Socket.h"

#include <memory>

class TcpServer;

class TcpClient : public Socket {
public:
    static std::shared_ptr<TcpClient> accept_connection(TcpServer *server);

public:
    ~TcpClient() override;

    ssize_t read(char *buff, size_t len);

    ssize_t send(const char *buff, size_t len);
};

#endif //SOCKETS_TCPCLIENT_H
