#ifndef AUTHENTICATEPACKET_H
#define AUTHENTICATEPACKET_H

#include <cstdint>
#include <string>
#include "../Packet/packet.h"

class AuthenticatePacket : public Packet
{
    std::int64_t id_;
    std::string name_;
    std::string username_;

public:

    AuthenticatePacket(std::int64_t id, std::string name, std::string username);
    AuthenticatePacket();
    void serialize(QDataStream &out) const override;
    void deserialize(QDataStream &in) override;

    std::int64_t id() const;
    std::string name() const;
    std::string username() const;

};

#endif // AUTHENTICATEPACKET_H
