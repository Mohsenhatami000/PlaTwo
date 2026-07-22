#include "sessionmanager.h"

SessionManager::SessionManager(): clientCounter(0){};

int SessionManager::getClientCounter() const{
    return clientCounter;
}

void SessionManager::initSession(QTcpSocket *socket){
    ClientSession *session = new ClientSession(socket);
    Sessions_[socket] = session;
    clientCounter++;
}

void SessionManager::addRoomID(std::int64_t id){

}

void SessionManager::addUserInformation(QTcpSocket *socket, std::int64_t ID, std::string name, std::string username){
    Sessions_[socket]->initAuthUser(ID, name, username);
}

void SessionManager::removeSession(QTcpSocket *socket){
    Sessions_.erase(socket);
}

std::optional<std::int64_t> SessionManager::getUserIDBySocket(QTcpSocket* socket) {
    auto it = Sessions_.find(socket);
    if (it != Sessions_.end() && it->second != nullptr) {
        return it->second->getUserID();
    }
    return std::nullopt;  
}