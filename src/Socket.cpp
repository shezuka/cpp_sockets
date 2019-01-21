#include <Socket.h>

#include <unistd.h>
#include <cstring>
#include <iostream>

Socket::~Socket() {
    close();
}

Socket::Socket() = default;

Socket::Socket(int descriptor, struct sockaddr_in *addr)
        : _descriptor(descriptor),
          _addr(addr) {
}

void Socket::set_descriptor(int val) {
    if (val <= 0)
        error("set_descriptor");

    _descriptor = val;
}

void Socket::set_addr(struct sockaddr_in *addr) {
    _addr = addr;
}

inline void Socket::close_descriptor() {
    if (_descriptor > 0) {
        ::close(_descriptor);
        _descriptor = 0;
    }
}

void Socket::clear_addr() {
    if (_addr != nullptr) {
        delete _addr;
        _addr = nullptr;
    }
}

void Socket::close() {
    close_descriptor();
    clear_addr();
}

int Socket::descriptor() const {
    return _descriptor;
}

int Socket::port() const {
    return _port;
}

void Socket::set_port(ushort port) {
    _port = port;
}

struct sockaddr *Socket::addr() const {
    return reinterpret_cast<sockaddr *>(_addr);
}

struct sockaddr_in *Socket::addr_in() const {
    return _addr;
}

bool Socket::is_open() const {
    return _descriptor > 0 && _addr != nullptr;
}

void Socket::error(const std::string &reason) const {
    std::cerr << reason << std::endl;
}

void Socket::init_addr() {
    clear_addr();
    _addr = new struct sockaddr_in;
    ::bzero(_addr, sizeof(*_addr));
}
