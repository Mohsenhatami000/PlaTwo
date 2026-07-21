#include <QCoreApplication>
#include "Network/Server/qtcpnetworkserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpNetworkServer server;

    server.start();

    return a.exec();
}
