#include "tcpClient.h"

int main()
{
    tcpClient client;
    int socket;

    client.connectServer();
    socket = client.getServerSocket();
    client.sendDatatoServer();
    client.receiveDatafromServer();
    client.closeSocket(socket);

    return 0;

}