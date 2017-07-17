#include "networkmanager.h"

NetworkManager::NetworkManager(bool legacy, QObject *parent) : QObject(parent), legacyModeEnabled(legacy)
{
    initSockets();
}

void NetworkManager::initSockets() {
    if(legacyModeEnabled) {
        legacySocket.reset(new QUdpSocket(this));
    }
}

void NetworkManager::sendNotification(QString target, QString message) {
    if(legacyModeEnabled) {
        sendLegacy(target, message);
    }
}

void NetworkManager::sendLegacy(QString target, QString message) {
    QByteArray datagram = target.toUtf8() + "::" + message.toUtf8();

    legacySocket->writeDatagram(datagram.data(), datagram.size(),
                                 QHostAddress::Broadcast, 3141);
}
