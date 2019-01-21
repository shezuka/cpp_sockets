#ifndef SOCKETS_SOCKET_H
#define SOCKETS_SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

class Socket {
private:
    int _descriptor = 0;
    ushort _port = 1024;
    struct sockaddr_in *_addr = nullptr;

protected:
    void error(const std::string &reason) const;

    void set_descriptor(int val);

    void set_addr(struct sockaddr_in *addr);

    void init_addr();

    void close_descriptor();

    void clear_addr();

public:
    virtual ~Socket() = 0;

    Socket();

    Socket(int descriptor, struct sockaddr_in *addr);

    void close();

    int descriptor() const;

    int port() const;

    void set_port(ushort port);

    struct sockaddr *addr() const;

    struct sockaddr_in *addr_in() const;

    bool is_open() const;
};

#endif //SOCKETS_SOCKET_H
