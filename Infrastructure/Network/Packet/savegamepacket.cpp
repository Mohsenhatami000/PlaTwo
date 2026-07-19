#include "savegamepacket.h"

SaveGamePacket::SaveGamePacket(): Packet(Type::SaveGame){}

void SaveGamePacket::serialize(QDataStream &out) const{

}

void SaveGamePacket::deserialize(QDataStream &in){

}

