#include "loadgamepacket.h"

LoadGamePacket::LoadGamePacket():Packet(Type::LoadGame){}


void LoadGamePacket::serialize(QDataStream &out) const{

}

void LoadGamePacket::deserialize(QDataStream &in){

}