#include "readyplayerpacket.h"

ReadyPlayerPacket::ReadyPlayerPacket(): Packet(Type::ReadyPlayer){}

ReadyPlayerPacket::ReadyPlayerPacket(Type type, bool isReady): Packet(type){
    isReady_ = isReady;
}

void ReadyPlayerPacket::serialize(QDataStream &out) const{
    out << isReady_;
}

void ReadyPlayerPacket::deserialize(QDataStream &in){
    in >> isReady_;
}

bool ReadyPlayerPacket::isReady() const{
    return isReady_;
}
