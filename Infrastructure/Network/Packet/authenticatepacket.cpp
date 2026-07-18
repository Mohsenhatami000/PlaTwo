#include "authenticatepacket.h"
#include <QString>

AuthenticatePacket::AuthenticatePacket(Type type, std::int64_t id, std::string name, std::string username): Packet(type){
    id_ = id;
    name_ = name;
    username_ = username;
}

AuthenticatePacket::AuthenticatePacket(): Packet(Type::Authenticate){}


void AuthenticatePacket::serialize(QDataStream &out) const {
    out << id_;
    out << QString::fromStdString(name_);
    out << QString::fromStdString(username_);
}

void AuthenticatePacket::deserialize(QDataStream &in){
    in >> id_;
    QString tmp;
    in >> tmp;
    name_ = tmp.toStdString();
    in >> tmp;
    username_ = tmp.toStdString();
}


std::int64_t AuthenticatePacket::id() const{
    return id_;
}

std::string AuthenticatePacket::name() const{
    return name_;
}

std::string AuthenticatePacket::username() const{
    return username_;
}
