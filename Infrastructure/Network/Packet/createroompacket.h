#ifndef CREATEROOMPACKET_H
#define CREATEROOMPACKET_H

#include "../Packet/packet.h"
#include "Domain/Enums/Enums.h"

class CreateRoomPacket : public Packet
{
    int width_;
    int height_;
    int timeLimit_;
    GameType gameType_;


public:
    CreateRoomPacket(int width, int height, int timeLimit, GameType gameType);
    CreateRoomPacket();
    void serialize(QDataStream &out) const override;
    void deserialize(QDataStream &in) override;

    int width() const;
    int height() const;
    int timeLimit() const;
    GameType gameType() const;
};

#endif // CREATEROOMPACKET_H
