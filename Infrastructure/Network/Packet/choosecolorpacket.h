#ifndef CHOOSECOLORPACKET_H
#define CHOOSECOLORPACKET_H

#include "Network/Packet/packet.h"

class ChooseColorPacket : public Packet
{
    std::string color_;

public:
    ChooseColorPacket(std::string color);
    ChooseColorPacket();
    void serialize(QDataStream &out) const override;
    void deserialize(QDataStream &in) override;
    std::string color() const;
};

#endif // CHOOSECOLORPACKET_H
