#include <TcpClient.h>

#include <TcpServer.h>
#include <unistd.h>

std::shared_ptr<TcpClient> TcpClient::accept_connection(TcpServer *server) {
    auto client = std::make_shared<TcpClient>();
    client->init_addr();

    socklen_t addr_len = sizeof(*client->addr_in());
    int descriptor = ::accept(server->descriptor(), client->addr(), &addr_len);

    client->set_descriptor(descriptor);

    return client;
}

TcpClient::~TcpClient() = default;

ssize_t TcpClient::read(char *buff, size_t len) {
    return ::read(descriptor(), buff, len);
}

ssize_t TcpClient::send(const char *buff, size_t len) {
    return ::send(descriptor(), buff, len, 0);
}
