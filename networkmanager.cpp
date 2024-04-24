#include "networkmanager.h"

NetworkManager::NetworkManager() {
    socket.connectToHost("192.168.124.13",3333);
    qDebug()<<"connect server....";

}

NetworkManager::~NetworkManager()
{
    socket.close();
}

NetworkManager& NetworkManager::instance() {
    static NetworkManager _instance;
    return _instance;
}

QTcpSocket* NetworkManager::getSocket() {
    return &socket;
}
