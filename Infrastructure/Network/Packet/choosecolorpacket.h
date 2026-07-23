#ifndef CHOOSECOLORPACKET_H
#define CHOOSECOLORPACKET_H

#include "../Packet/packet.h"

class ChooseColorPacket : public Packet
{
    std::string color_;
    std::int64_t roomID_;

public:
    ChooseColorPacket(std::string color,std::int64_t id);
    ChooseColorPacket();
    void serialize(QDataStream &out) const override;
    void deserialize(QDataStream &in) override;
    std::string color() const;
    std::int64_t roomID() const;
};

#endif // CHOOSECOLORPACKET_H
