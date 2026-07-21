#include "Presentation/MainWindow/mainwindow.h"
#include "Network/Client/qtcpnetworkclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QTcpNetworkClient client;
    client.Connect("127.0.0.1", 5000);


    return a.exec();
}
