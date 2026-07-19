#ifndef SAVEGAMEPACKET_H
#define SAVEGAMEPACKET_H

#include "Network/Packet/packet.h"

class SaveGamePacket : public Packet
{
    // attributes are added later

public:
    SaveGamePacket();
    void serialize(QDataStream &out) const; // implement later
    void deserialize(QDataStream &in); // implement later
};

#endif // SAVEGAMEPACKET_H
