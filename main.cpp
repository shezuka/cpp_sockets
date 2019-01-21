#include <string>
#include <iostream>
#include <TcpServer.h>
#include <TcpClient.h>

using namespace std;

int main() {

    TcpServer serv;
    serv.listen(3005);

    auto client = TcpClient::accept_connection(&serv);

    const size_t BUFF_SIZE = 1024;
    char buff[BUFF_SIZE + 1] = {0};
    client->read(buff, BUFF_SIZE);

    string body = "Hello from C++, HTTP server is coming";
    string response = "HTTP/1.1 200 OK\r\n"
                      "Content-Type: text/plain\r\n"
                      "Content-Length: " + to_string(body.length()) + "\r\n";

    response += "\r\n" + body;

    client->send(response.c_str(), response.size());

    client->close();
    serv.close();

    return 0;
}