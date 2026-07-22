#ifndef CLIENTSESSION_H
#define CLIENTSESSION_H

#include <cstdint>
#include <QTcpSocket>
#include <string>
#include <optional>
#include "Domain/Entities/authenticateduser.h"

class ClientSession
{

    std::optional<AuthenticatedUser> authUser_;
    QTcpSocket *socket_;
    std::int64_t roomID_;


public:

    // ClientSession(std::int64_t ID
    //               ,std::string name
    //               ,std::string username
    //               ,QTcpSocket *socket
    //               ,std::int64_t roomID);

    ClientSession(QTcpSocket *socket);
    ~ClientSession();

    void initAuthUser(std::int64_t ID, const std::string name, const std::string username);
    void initRoomId(std::int64_t roomID);
    QTcpSocket* getSocket() const;
    std::int64_t getUserID() const;

};




#endif // CLIENTSESSION_H