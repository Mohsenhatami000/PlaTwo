#ifndef JOINROOMPACKET_H
#define JOINROOMPACKET_H

#include "../Packet/packet.h"
#include <cstdint>
#include <string>

class JoinRoomPacket : public Packet
{
    std::string IP_;
    std::int64_t port_;
    std::int64_t roomId_;


public:

    JoinRoomPacket(std::string IP, std::int64_t port, std::int64_t roomId);
    JoinRoomPacket();
    void serialize(QDataStream &out) const override;
    void deserialize(QDataStream &in) override;

    std::string IP() const;
    std::int64_t port() const;
    std::int64_t roomId() const;



};

#endif // JOINROOMPACKET_H
