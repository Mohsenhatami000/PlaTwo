#include "qtcpnetworkserver.h"
#include <QHostAddress>
#include "Network/Packet/packet.h"
#include "Network/Packet/authenticatepacket.h"

QTcpNetworkServer::QTcpNetworkServer(QObject *parent): QObject(parent){

    server_ = new QTcpServer(this);

    connect(server_,
            &QTcpServer::newConnection,
            this,
            &QTcpNetworkServer::onNewConnection);
}


QTcpNetworkServer::~QTcpNetworkServer(){
    if(server_){
        server_->close();
        delete server_;
    }
}


bool QTcpNetworkServer::start(){

    QHostAddress localIP;
    localIP.setAddress("127.0.0.1");
    quint16 port = 5000;
    if(!server_->listen(localIP, port)){
        qDebug() << "Server failed to start" << Qt::endl;
        return false;
    }
    else{

        qDebug() << "Server is now listening on IP:" << localIP.toString() << "| Port:" << port << Qt::endl;
        return true;
    }
}


void QTcpNetworkServer::onNewConnection(){

    QTcpSocket *newSocket = server_->nextPendingConnection();

    sessionManager_.initSession(newSocket);

    qDebug() << "Client" << sessionManager_.getClientCounter() << " was connected to the server!" << Qt::endl;

    connect(newSocket,
            &QTcpSocket::readyRead,
            this,
            [this, newSocket]{
                return onReadyRead(newSocket);
            });
}

void QTcpNetworkServer::onReadyRead(QTcpSocket *socket){

    QByteArray buffer = socket->readAll();
    QDataStream in(&buffer, QIODevice::ReadOnly);
    Type type;
    in >> type;

    switch(type){

        case Type::Authenticate:
        {
            AuthenticatePacket tmp;
            tmp.deserialize(in);
            sessionManager_.addUserInformation(socket, tmp.id(), tmp.name(), tmp.username());
            break;
        }
        case Type::CreateRoom:

            break;

        default:
            break;
    }
}


void QTcpNetworkServer::stop() noexcept{
    server_->close();
}

void QTcpNetworkServer::send() noexcept{
    return;
}

void QTcpNetworkServer::broadcast() noexcept{
    return;
}

void QTcpNetworkServer::disconnect() noexcept{
    return;
}




