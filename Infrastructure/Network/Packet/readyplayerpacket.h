#ifndef READYPLAYERPACKET_H
#define READYPLAYERPACKET_H

#include "Network/Packet/packet.h"

class ReadyPlayerPacket : public Packet
{
    bool isReady_;

public:

    ReadyPlayerPacket(Type type, bool isReady);
    ReadyPlayerPacket();
    void serialize(QDataStream &out) const;
    void deserialize(QDataStream &in);
    bool isReady() const;

};

#endif // READYPLAYERPACKET_H
