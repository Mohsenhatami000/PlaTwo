#include "qtcpnetworkclient.h"

QTcpNetworkClient::QTcpNetworkClient(QObject *parent): QObject(parent){
    socket_ = new QTcpSocket(this);

    connect(socket_,
            &QTcpSocket::connected,
            this,
            &QTcpNetworkClient::onConnected);
    connect(socket_,
            &QTcpSocket::disconnected,
            this,
            &QTcpNetworkClient::onDisconnected);
    connect(socket_,
            &QTcpSocket::errorOccurred,
            this,
            &QTcpNetworkClient::onError);


}


void QTcpNetworkClient::Connect(std::string IP,std::int64_t port){
    QHostAddress HostIP;
    HostIP.setAddress(QString::fromStdString(IP));
    quint16 HostPort = port;

    socket_->connectToHost(HostIP, HostPort);

}


void QTcpNetworkClient::onConnected(){
    qDebug() << "Client was successfully Connected to the server" << Qt::endl;
}


void QTcpNetworkClient::onDisconnected(){
    qDebug() << "You were disconnected from the server" << Qt::endl;
}


void QTcpNetworkClient::onError(){
    qDebug() << "Couldn't connect to the server" << Qt::endl;
}


void QTcpNetworkClient::onReadyRead(QTcpSocket *socket){

    QByteArray buffer = socket->readAll();

    QDataStream out(&buffer, QIODevice::ReadOnly);

    // read spected packets

}



