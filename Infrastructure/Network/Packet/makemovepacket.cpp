#include "makemovepacket.h"

MakeMovePacket::MakeMovePacket(): Packet(Type::MakeMove){}

void MakeMovePacket::serialize(QDataStream &out) const{

}

void MakeMovePacket::deserialize(QDataStream &in){

}