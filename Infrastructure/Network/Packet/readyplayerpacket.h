#ifndef READYPLAYERPACKET_H
#define READYPLAYERPACKET_H

#include "Network/Packet/packet.h"

class ReadyPlayerPacket : public Packet
{
    bool isReady_;

public:

    ReadyPlayerPacket(bool isReady);
    ReadyPlayerPacket();
    void serialize(QDataStream &out) const override;
    void deserialize(QDataStream &in) override;
    bool isReady() const;

};

#endif // READYPLAYERPACKET_H
