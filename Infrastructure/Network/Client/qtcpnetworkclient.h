#ifndef QTCPNETWORKCLIENT_H
#define QTCPNETWORKCLIENT_H

#include "Domain/Interfaces/Services/inetworkclient.h"
#include <QObject>
#include <QTcpSocket>


class QTcpNetworkClient : public QObject, public INetworkClient
{
    Q_OBJECT
    QTcpSocket *socket_;

public:

    QTcpNetworkClient(QObject *parent = nullptr);
    void Connect(std::string IP,std::int64_t port) override;
    void Disconnect() override;
    void send(Packet &packet) override;

private slots:

    void onConnected();
    void onDisconnected();
    void onError();
    void onReadyRead(QTcpSocket *socket);

};

#endif // QTCPNETWORKCLIENT_H
