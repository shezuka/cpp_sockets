#include <TcpServer.h>
#include <unistd.h>
#include <cstring>

TcpServer::~TcpServer() {

}

void TcpServer::listen(ushort port) {
    set_port(port);

    int descriptor = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    set_descriptor(descriptor);

    int opt_val = 1;
    if (::setsockopt(descriptor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt_val, sizeof(opt_val)) < 0)
        error("setsockopt");

    init_addr();
    addr_in()->sin_port = htons(port);
    addr_in()->sin_family = AF_INET;
    addr_in()->sin_addr.s_addr = INADDR_ANY;

    if (::bind(descriptor, addr(), sizeof(*addr())) < 0)
        error("bind");

    if (::listen(descriptor, 200) < 0)
        error("listen");
}
