#ifndef SAVEGAMEPACKET_H
#define SAVEGAMEPACKET_H

#include "Network/Packet/packet.h"

class SaveGamePacket : public Packet
{
    // attributes are added later

public:
    SaveGamePacket();
    void serialize(QDataStream &out) const override; // implement later
    void deserialize(QDataStream &in) override; // implement later
};

#endif // SAVEGAMEPACKET_H
