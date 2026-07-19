#ifndef MAKEMOVEPACKET_H
#define MAKEMOVEPACKET_H
#include "Network/Packet/packet.h"

class MakeMovePacket : public Packet
{
    // attributes are added later


public:
    MakeMovePacket();
    void serialize(QDataStream &out) const override; //implement later
    void deserialize(QDataStream &in) override; //implement later
};

#endif // MAKEMOVEPACKET_H
