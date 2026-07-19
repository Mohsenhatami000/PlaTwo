#include "readyplayerpacket.h"

ReadyPlayerPacket::ReadyPlayerPacket(): Packet(Type::ReadyPlayer){}

ReadyPlayerPacket::ReadyPlayerPacket(bool isReady): Packet(Type::ReadyPlayer){
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
