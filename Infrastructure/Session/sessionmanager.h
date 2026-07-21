#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include "Session/clientsession.h"



class SessionManager
{
    std::unordered_map<QTcpSocket*, ClientSession*> Sessions_;
    int clientCounter;

public:

    SessionManager();
    void initSession(QTcpSocket *socket);
    void removeSession(QTcpSocket *socket);
    void addUserInformation(QTcpSocket *socket, std::int64_t ID, std::string name, std::string username);
    void addRoomID(std::int64_t roomID);
    int getClientCounter() const;



};

#endif // SESSIONMANAGER_H
