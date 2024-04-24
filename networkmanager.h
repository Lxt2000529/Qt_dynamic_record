// NetworkManager.h
#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QTcpSocket>

class NetworkManager {
public:
    static NetworkManager& instance();

    QTcpSocket* getSocket();

    // 禁止拷贝和移动构造
    NetworkManager(const NetworkManager&) = delete;
    NetworkManager& operator=(const NetworkManager&) = delete;
    NetworkManager(NetworkManager&&) = delete;
    NetworkManager& operator=(NetworkManager&&) = delete;

private:
    NetworkManager();// 私有构造函数
    ~NetworkManager();

    QTcpSocket socket;
};

#endif // NETWORKMANAGER_H
