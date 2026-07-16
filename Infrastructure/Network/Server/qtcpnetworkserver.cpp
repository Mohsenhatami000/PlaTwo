#include "qtcpnetworkserver.h"
#include <QHostAddress>

QTcpNetworkServer::QTcpNetworkServer(QObject *parent): QObject(parent){

    server_ = new QTcpServer(this);
    ClientCounter_ = 0;


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
    ClientCounter_++;

    qDebug() << "Client" << ClientCounter_ << " was connected to the server!" << Qt::endl;

    ClientList_.insert(ClientCounter_, newSocket);

    connect(newSocket,
            &QTcpSocket::readyRead,
            this,
            [this, newSocket]{
                return onReadyRead(newSocket);
            });
}

void QTcpNetworkServer::onReadyRead(QTcpSocket *socket){

    QByteArray buffer = socket->readAll();

    QDataStream out(&buffer, QIODevice::ReadOnly);

    // read spected packets

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




