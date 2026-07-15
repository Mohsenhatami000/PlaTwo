#include "qtcpnetworkserver.h"
#include <QHostAddress>

QTcpNetworkServer::QTcpNetworkServer(QObject *parent){

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


void QTcpNetworkServer::start(){

    QHostAddress localIP;
    localIP.setAddress("127.0.0.1");
    server_->listen(localIP, 5000);
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

