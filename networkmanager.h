#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QUdpSocket>

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(bool legacy, QObject *parent = 0);
    void sendNotification(QString target, QString message);

private:
    void sendLegacy(QString target, QString message);
    void initSockets();

private:
    bool legacyModeEnabled;
    QScopedPointer<QUdpSocket> legacySocket;

signals:

public slots:
};

#endif // NETWORKMANAGER_H
