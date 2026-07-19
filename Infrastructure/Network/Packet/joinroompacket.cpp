#include "joinroompacket.h"
#include <QString>

JoinRoomPacket::JoinRoomPacket(std::string IP, std::int64_t port, std::int64_t roomId): Packet(Type::JoinRoom){
    IP_ = IP;
    port_ = port;
    roomId_ = roomId;
}

JoinRoomPacket::JoinRoomPacket():Packet(Type::JoinRoom){};


void JoinRoomPacket::serialize(QDataStream &out) const{
    out <<  QString::fromStdString(IP_);
    out << port_;
    out << roomId_;
}

void JoinRoomPacket::deserialize(QDataStream &in){
    QString IP;
    in >> IP;
    IP_ = IP.toStdString();
    in >> port_;
    in >> roomId_;
}


std::string JoinRoomPacket::IP() const{
    return IP_;
}

std::int64_t JoinRoomPacket::port() const{
    return port_;
}

std::int64_t JoinRoomPacket::roomId() const{
    return roomId_;
}