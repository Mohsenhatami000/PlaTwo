#ifndef CHOOSECOLORPACKET_H
#define CHOOSECOLORPACKET_H

#include "Network/Packet/packet.h"

class ChooseColorPacket : public Packet
{
    std::string color_;

public:
    ChooseColorPacket(Type type, std::string color);
    ChooseColorPacket();
    void serialize(QDataStream &out) const;
    void deserialize(QDataStream &in);
    std::string color() const;
};

#endif // CHOOSECOLORPACKET_H
