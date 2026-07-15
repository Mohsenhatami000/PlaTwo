#ifndef QTCPNETWORKSERVER_H
#define QTCPNETWORKSERVER_H

#include "Domain/Interfaces/Services/INetworkServer.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QHash>


class QTcpNetworkServer : public QObject, public INetworkServer
{
    Q_OBJECT;
    QTcpServer *server_;
    int ClientCounter_;
    QHash<int, QTcpSocket*> ClientList_;

public:

    QTcpNetworkServer(QObject *parent = nullptr);
    ~QTcpNetworkServer();
    void start() override;
    void stop() noexcept override;
    void send() const noexcept;
    void broadcast() const noexcept;
    void disconnect() const noexcept;

private slots:
    void onNewConnection();
    void onReadyRead(QTcpSocket *socket);

};

#endif // QTCPNETWORKSERVER_H
