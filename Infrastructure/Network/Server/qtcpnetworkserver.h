#ifndef QTCPNETWORKSERVER_H
#define QTCPNETWORKSERVER_H

#include "Domain/Interfaces/Services/INetworkServer.h"
#include "Session/sessionmanager.h"
#include "Manager/RoomManager.h"
#include <QTcpServer>
#include <QTcpSocket>



class QTcpNetworkServer : public QObject, public INetworkServer
{
    Q_OBJECT;
    QTcpServer *server_;
    SessionManager sessionManager_;
    RoomManager roomManager_;

public:

    QTcpNetworkServer(QObject *parent = nullptr);
    ~QTcpNetworkServer();
    bool start() override;
    void stop() noexcept override;
    void send() noexcept override;
    void broadcast() noexcept override;
    void disconnect() noexcept override;

private slots:
    void onNewConnection();
    void onReadyRead(QTcpSocket *socket);

};

#endif // QTCPNETWORKSERVER_H
