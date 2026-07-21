#ifndef LOADGAMEPACKET_H
#define LOADGAMEPACKET_H

#include "Network/Packet/packet.h"

class LoadGamePacket : public Packet
{
    // attributes are added later


public:
    LoadGamePacket();
    void serialize(QDataStream &out) const override; // implement later
    void deserialize(QDataStream &in)override; // implement later
};

#endif // LOADGAMEPACKET_H
