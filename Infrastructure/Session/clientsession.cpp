#include "clientsession.h"

// ClientSession::ClientSession(std::int64_t ID
//                              , std::string name
//                              , std::string username
//                              , QTcpSocket *socket
//                              , std::int64_t roomID
//                              ): authUser_(ID, Name(name), UserName(username)){
//     socket_ = socket;
//     roomID_ = roomID;
// }

ClientSession::ClientSession(QTcpSocket *socket){
    socket_ = socket;
}

ClientSession::~ClientSession(){
    if(!socket_){
        delete socket_;
    }
}

void ClientSession::initAuthUser(std::int64_t ID, const std::string name, const std::string username){
    authUser_ = AuthenticatedUser(ID, Name(name), UserName(username));
}


QTcpSocket* ClientSession::getSocket() const{
    return socket_;
}

void ClientSession::initRoomId(std::int64_t roomID){
    roomID_ = roomID;
}
